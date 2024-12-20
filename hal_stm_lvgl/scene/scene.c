#include "scene.h"
#include "lvgl/lvgl.h"

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

  lv_obj_t* slider1 = lv_slider_create(lv_screen_active());
  lv_obj_set_width(slider1, 200);
  lv_obj_align(slider1, LV_ALIGN_BOTTOM_MID, 0, -40);

  lv_obj_t* bar1 = lv_bar_create(lv_screen_active());
  lv_obj_set_size(bar1, 200, 50);
  lv_obj_align(bar1, LV_ALIGN_BOTTOM_MID, 0, -100);
}

void create_image_scroller(void)
{
#define USE_DITHER
#ifndef USE_DITHER
  LV_IMAGE_DECLARE(internal_1_800x480);
  lv_obj_t * img_internal_1 = lv_image_create(lv_screen_active());
  lv_image_set_src(img_internal_1, &internal_1_800x480);
  lv_obj_align(img_internal_1, LV_ALIGN_TOP_LEFT, 0, 0);

  LV_IMAGE_DECLARE(internal_2_800x480);
  lv_obj_t * img_internal_2 = lv_image_create(lv_screen_active());
  lv_image_set_src(img_internal_2, &internal_2_800x480);
  lv_obj_align(img_internal_2, LV_ALIGN_TOP_LEFT, 800 * 1, 0);

  LV_IMAGE_DECLARE(external_1_800x480);
  lv_obj_t * img_external_1 = lv_image_create(lv_screen_active());
  lv_image_set_src(img_external_1, &external_1_800x480);
  lv_obj_align(img_external_1, LV_ALIGN_TOP_LEFT, 800 * 2, 0);

  LV_IMAGE_DECLARE(external_2_800x480);
  lv_obj_t * img_external_2 = lv_image_create(lv_screen_active());
  lv_image_set_src(img_external_2, &external_2_800x480);
  lv_obj_align(img_external_2, LV_ALIGN_TOP_LEFT, 800*3, 0);
#else
  LV_IMAGE_DECLARE(internal_1_800x480_dither);
  lv_obj_t * img_internal_1 = lv_image_create(lv_screen_active());
  lv_image_set_src(img_internal_1, &internal_1_800x480_dither);
  lv_obj_align(img_internal_1, LV_ALIGN_TOP_LEFT, 0, 0);

  LV_IMAGE_DECLARE(internal_2_800x480_dither);
  lv_obj_t * img_internal_2 = lv_image_create(lv_screen_active());
  lv_image_set_src(img_internal_2, &internal_2_800x480_dither);
  lv_obj_align(img_internal_2, LV_ALIGN_TOP_LEFT, 800 * 1, 0);

  LV_IMAGE_DECLARE(external_1_800x480_dither);
  lv_obj_t * img_external_1 = lv_image_create(lv_screen_active());
  lv_image_set_src(img_external_1, &external_1_800x480_dither);
  lv_obj_align(img_external_1, LV_ALIGN_TOP_LEFT, 800 * 2, 0);

  LV_IMAGE_DECLARE(external_2_800x480_dither);
  lv_obj_t * img_external_2 = lv_image_create(lv_screen_active());
  lv_image_set_src(img_external_2, &external_2_800x480_dither);
  lv_obj_align(img_external_2, LV_ALIGN_TOP_LEFT, 800*3, 0);
#endif
}
