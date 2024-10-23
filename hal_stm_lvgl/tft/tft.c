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

static uint8_t fb[2][TFT_HOR_RES * TFT_VER_RES * (LV_COLOR_DEPTH >> 3)] __attribute__((aligned(4))) = {};

/**********************
 *      MACROS
 **********************/

/**
 * Initialize your display here
 */

void tft_init(void)
{
  lv_init();

  /*-----------------------------------
   * Register the display in LVGL
   *----------------------------------*/
  lv_display_t * disp = lv_display_create(TFT_HOR_RES, TFT_VER_RES);
  lv_display_set_buffers(disp, fb[0], fb[1], sizeof(fb[0]), LV_DISPLAY_RENDER_MODE_DIRECT);
  lv_display_set_flush_cb(disp, ex_disp_flush);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/


/* Flush the content of the internal buffer the specific area on the display
 * You can use DMA or any hardware acceleration to do this operation in the background but
 * 'lv_disp_flush_ready()' has to be called when finished*/
static void ex_disp_flush(lv_display_t * disp, const lv_area_t * area, uint8_t * px_map)
{
  HAL_LTDC_SetAddress(&hltdc, (uint32_t)(uintptr_t)px_map, 0);
  lv_disp_flush_ready(disp);
}
