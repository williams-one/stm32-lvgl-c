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

/**********************
 *  STATIC VARIABLES
 **********************/
extern LTDC_HandleTypeDef hltdc;

static uint8_t fb[2][TFT_HOR_RES * TFT_VER_RES * (LV_COLOR_DEPTH >> 3)] __attribute__((aligned(4))) = {};

/**********************
 *      MACROS
 **********************/

#if LV_USE_ST_LTDC == 0
/**********************
 *  STATIC PROTOTYPES
 **********************/
static void ex_disp_flush(lv_display_t* disp, const lv_area_t* area, uint8_t* px_map);

void tft_init(void)
{
  lv_init();

  /*-----------------------------------
   * Register the display in LVGL
   *----------------------------------*/
  lv_display_t* disp = lv_display_create(TFT_HOR_RES, TFT_VER_RES);
  lv_display_set_buffers(disp, fb[0], fb[1], sizeof(fb[0]), LV_DISPLAY_RENDER_MODE_DIRECT);
  lv_display_set_flush_cb(disp, ex_disp_flush);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/


/* Flush the content of the internal buffer the specific area on the display
 * You can use DMA or any hardware acceleration to do this operation in the background but
 * 'lv_disp_flush_ready()' has to be called when finished*/
static void ex_disp_flush(lv_display_t* disp, const lv_area_t* area, uint8_t* px_map)
{
  HAL_LTDC_SetAddress(&hltdc, (uint32_t)(uintptr_t)px_map, 0);
  lv_disp_flush_ready(disp);
}

#else

void tft_init(void)
{
  lv_init();

  /*-----------------------------------
   * Register the display in LVGL
   *----------------------------------*/
  lv_display_t* disp = lv_st_ltdc_create_direct(fb[0], fb[1], 0);
  (void) disp;
}

#endif

void create_test_scene(void)
{

  lv_obj_t* label1 = lv_label_create(lv_screen_active());
  lv_label_set_long_mode(label1, LV_LABEL_LONG_WRAP);     /*Break the long lines*/
  lv_label_set_text(label1, "Recolor is not supported for v9 now.");
  lv_obj_set_width(label1, 150);  /*Set smaller width to make the lines wrap*/
  lv_obj_set_style_text_align(label1, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_align(label1, LV_ALIGN_CENTER, 0, -40);
  lv_color_t yellow = {
      .red = 255,
      .green = 255,
      .blue = 0
  };
  lv_obj_set_style_text_color(label1, yellow, LV_PART_MAIN);

  lv_obj_t* label2 = lv_label_create(lv_screen_active());
  lv_label_set_long_mode(label2, LV_LABEL_LONG_SCROLL_CIRCULAR);     /*Circular scroll*/
  lv_obj_set_width(label2, 150);
  lv_label_set_text(label2, "It is a circularly scrolling text. ");
  lv_obj_align(label2, LV_ALIGN_CENTER, 0, 40);

  static lv_point_precise_t line_points_1[] = { {1, 100}, {1, 1}, {100, 1} };
  static lv_point_precise_t line_points_2[] = { {3, 100}, {3, 3}, {100, 3} };
  static lv_point_precise_t line_points_3[] = { {798, 380}, {798, 478}, {700, 478} };
  static lv_point_precise_t line_points_4[] = { {796, 380}, {796, 476}, {700, 476} };

  lv_obj_t* line1 = lv_line_create(lv_screen_active());
  lv_line_set_points(line1, line_points_1, 3);
  lv_obj_t* line2 = lv_line_create(lv_screen_active());
  lv_line_set_points(line2, line_points_2, 3);
  lv_obj_t* line3 = lv_line_create(lv_screen_active());
  lv_line_set_points(line3, line_points_3, 3);
  lv_obj_t* line4 = lv_line_create(lv_screen_active());
  lv_line_set_points(line4, line_points_4, 3);
}

void load_test_image(void)
{
  LV_IMAGE_DECLARE(background);
  lv_obj_t * img1 = lv_image_create(lv_screen_active());
  lv_image_set_src(img1, &background);
  lv_obj_align(img1, LV_ALIGN_CENTER, 0, 0);
}
