/**
 * @file tft.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "lv_conf.h"
#include "lvgl/lvgl.h"

#include "tft.h"
#include "stm32u5xx.h"


/*********************
 *      DEFINES
 *********************/
#if LV_COLOR_DEPTH != 16 && LV_COLOR_DEPTH != 24 && LV_COLOR_DEPTH != 32
#error LV_COLOR_DEPTH must be 16, 24, or 32
#endif

#define TFT_FULL_REFRESH	0

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void ex_disp_flush(lv_display_t * disp, const lv_area_t * area, uint8_t * px_map);

/**********************
 *  STATIC VARIABLES
 **********************/
extern LTDC_HandleTypeDef hltdc;


/**********************
 *      MACROS
 **********************/

/**
 * Initialize your display here
 */

void tft_init(void)
{
//  BSP_LCD_Init(0,LCD_ORIENTATION_LANDSCAPE);
//	BSP_LCD_DisplayOn(0);

  lv_init();

	/*-----------------------------------
	 * Register the display in LVGL
	 *----------------------------------*/

	/*Basic initialization*/
	/*Set the resolution of the display*/
	lv_display_t * disp = lv_display_create(TFT_HOR_RES, TFT_VER_RES);

	/*Used to copy the buffer's content to the display*/
#if TFT_FULL_REFRESH
	static uint8_t fb[2][TFT_HOR_RES * TFT_VER_RES * LV_COLOR_FORMAT_GET_SIZE(LV_COLOR_FORMAT_RGB565)] __attribute__((aligned(4)));
//	lv_display_set_buffers(disp, fb[0], fb[1], sizeof(fb[0]), LV_DISPLAY_RENDER_MODE_FULL);
	// lv_display_set_buffers(disp, fb[0], fb[1], sizeof(fb[0]), LV_DISPLAY_RENDER_MODE_PARTIAL);
#else
//	static uint8_t fb[1][TFT_HOR_RES * TFT_VER_RES / 4 * LV_COLOR_FORMAT_GET_SIZE(LV_COLOR_FORMAT_RGB565)] __attribute__((aligned(4)));
//	lv_display_set_buffers(disp, fb[0], NULL, sizeof(fb[0]), LV_DISPLAY_RENDER_MODE_PARTIAL);
	static uint8_t fb[1][TFT_HOR_RES * TFT_VER_RES * LV_COLOR_FORMAT_GET_SIZE(LV_COLOR_FORMAT_RGB565)] __attribute__((aligned(4)));
	lv_display_set_buffers(disp, fb[0], NULL, sizeof(fb[0]), LV_DISPLAY_RENDER_MODE_FULL);
#endif

	/*set the callback to flush the pixels to the display*/
	lv_display_set_flush_cb(disp, ex_disp_flush);

//	for (int i = 0; i < sizeof(fb[0]); ++i)
//		fb[0][i] = 0x22;
//
//
	HAL_LTDC_SetAddress(&hltdc, (uint32_t)(uintptr_t)fb[0], 0);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static uint8_t dummy_fb[TFT_HOR_RES * TFT_VER_RES * LV_COLOR_FORMAT_GET_SIZE(LV_COLOR_FORMAT_RGB565)] __attribute__((aligned(4)));

/* Flush the content of the internal buffer the specific area on the display
 * You can use DMA or any hardware acceleration to do this operation in the background but
 * 'lv_disp_flush_ready()' has to be called when finished*/
static void ex_disp_flush(lv_display_t * disp, const lv_area_t * area, uint8_t * px_map)
{
	static uint16_t color = 0;
#if TFT_FULL_REFRESH == 0
//	uint16_t * fb = (uint16_t *) hltdc.LayerCfg[0].FBStartAdress;
//	uint16_t stride = lv_display_get_horizontal_resolution(disp);
//	fb += area->y1 * stride;
//	fb += area->x1;
//	lv_coord_t w = lv_area_get_width(area);
//	int32_t y;
//	for(y = area->y1; y <= area->y2; y++) {
//		lv_memcpy(fb, px_map, w * 2);
//		fb += stride;
//		px_map += w * 2;
//	}
	uint16_t * fb = (uint16_t *) hltdc.LayerCfg[0].FBStartAdress;
	uint16_t stride = lv_display_get_horizontal_resolution(disp);
//	lv_memcpy(fb, px_map, TFT_HOR_RES * TFT_VER_RES);

	color = (color + 1) & 0xFF;
	for (int i = 0; i < sizeof(TFT_HOR_RES * TFT_VER_RES); ++i)
		dummy_fb[i] = color;


#else
	if(lv_display_flush_is_last(disp)) {
		HAL_LTDC_SetAddress(&hltdc, (uint32_t)(uintptr_t)px_map, 0);
	}
#endif
	HAL_LTDC_SetAddress(&hltdc, (uint32_t)(uintptr_t)dummy_fb, 0);
	lv_disp_flush_ready(disp);
}
