#include "scene.h"
#include "lvgl/lvgl.h"
#include "hal_stm_lvgl/tft/tft.h"

#include <string.h>

#include "stm32u5xx_hal.h"

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

#define MAX_IMAGES 4
lv_obj_t* img[MAX_IMAGES] = {NULL, NULL, NULL, NULL};
#if defined(RESOLUTION_800x480)
LV_IMAGE_DECLARE(image_1_800x480_tsc6);
LV_IMAGE_DECLARE(image_2_800x480_tsc6a);
LV_IMAGE_DECLARE(image_3_800x480_i8);
LV_IMAGE_DECLARE(image_4_800x480_argb8888);
LV_IMAGE_DECLARE(image_5_800x480_i8);
LV_IMAGE_DECLARE(internal_1_800x480_dither);
LV_IMAGE_DECLARE(internal_2_800x480_dither);
LV_IMAGE_DECLARE(external_1_800x480_dither);
LV_IMAGE_DECLARE(external_2_800x480_dither);

// #define SINGLE_IMAGE_BENCHMARK

#ifdef SINGLE_IMAGE_BENCHMARK
#define SINGLE_IMAGE_NAME image_4_800x480_argb8888

const lv_image_dsc_t* image_dsc[MAX_IMAGES] = {
  &SINGLE_IMAGE_NAME,
  &SINGLE_IMAGE_NAME,
  &SINGLE_IMAGE_NAME,
  &SINGLE_IMAGE_NAME,
};
#else
const lv_image_dsc_t* image_dsc[MAX_IMAGES] = {
  &image_1_800x480_tsc6,
  &image_5_800x480_i8,
  &image_1_800x480_tsc6,
  &image_5_800x480_i8,
};
#endif
#elif defined(RESOLUTION_480x272)
LV_IMAGE_DECLARE(image_1_480x272_tsc6);
LV_IMAGE_DECLARE(image_2_480x272_tsc6a);
LV_IMAGE_DECLARE(image_3_480x272_i8);
LV_IMAGE_DECLARE(image_4_480x272_argb8888);
LV_IMAGE_DECLARE(image_5_480x272_i8);
LV_IMAGE_DECLARE(internal_1_480x272_dither);
LV_IMAGE_DECLARE(internal_2_480x272_dither);
LV_IMAGE_DECLARE(external_1_480x272_dither);
LV_IMAGE_DECLARE(external_2_480x272_dither);

// #define SINGLE_IMAGE_BENCHMARK

#ifdef SINGLE_IMAGE_BENCHMARK
#define SINGLE_IMAGE_NAME image_4_480x272_argb8888

const lv_image_dsc_t* image_dsc[MAX_IMAGES] = {
  &SINGLE_IMAGE_NAME,
  &SINGLE_IMAGE_NAME,
  &SINGLE_IMAGE_NAME,
  &SINGLE_IMAGE_NAME,
};
#else
const lv_image_dsc_t* image_dsc[MAX_IMAGES] = {
  &image_1_480x272_tsc6,
  &image_5_480x272_i8,
  &image_1_480x272_tsc6,
  &image_5_480x272_i8,
};
#endif
#endif

static void create_images(int image_count, bool scrollable)
{
  for (int i = 0; i < image_count; ++i)
  {
    img[i] = lv_image_create(lv_screen_active());
    lv_image_set_src(img[i], image_dsc[i]);
    lv_obj_align(img[i], LV_ALIGN_TOP_LEFT, scrollable ? TFT_HOR_RES * i : 0, 0 );
  }
}

void create_image_scroller(void)
{
  create_images(MAX_IMAGES, true);
}

lv_image_dsc_t* load_image_in_memory(uint32_t img_dsc_address, uint32_t img_data_address, const lv_image_dsc_t* image_dsc, const uint8_t* data, uint32_t size)
{
  lv_image_dsc_t* in_memory_image_dsc = (lv_image_dsc_t*)img_dsc_address;
  *in_memory_image_dsc = *image_dsc;
  uint8_t* in_memory_data = (uint8_t*)img_data_address;
  memcpy(in_memory_data, data, size);
  in_memory_image_dsc->data = in_memory_data;
  return in_memory_image_dsc;
}


static void create_images_in_memory(int image_count, bool scrollable)
{
  const uint32_t base_address = 0x91000000;
  const uint32_t img_data_offset = 0x2000;    // 8KB
  const uint32_t slot_size = 0x200000;        // 2MB

  for (int i = 0; i < image_count; ++i)
  {
    uint32_t img_dsc_address = base_address + i * slot_size;
    uint32_t img_data_address = base_address + img_data_offset + (i * slot_size);

    img[i] = lv_image_create(lv_screen_active());
    lv_image_dsc_t* in_memory_image_dsc = load_image_in_memory(img_dsc_address, img_data_address, image_dsc[i], image_dsc[i]->data, image_dsc[i]->data_size);
    lv_image_set_src(img[i], in_memory_image_dsc);
    lv_obj_align(img[i], LV_ALIGN_TOP_LEFT, scrollable ? TFT_HOR_RES * i : 0, 0 );
  }
}

void create_image_scroller_in_memory(void)
{
  create_images_in_memory(MAX_IMAGES, true);
}

#define IMAGE_COUNT 2
void create_image_blended(void)

{
  create_images(IMAGE_COUNT, false);
}

void update_image_blended(void)
{
  static uint8_t opa = 255;
  for (int i = 0; i < IMAGE_COUNT; ++i)
    lv_obj_set_style_opa(img[i], ((uint8_t)(opa + 64 * i) >> 1) + 64, LV_PART_MAIN);
  opa++;
}

#define MAX_RECT 4
lv_obj_t* rect[MAX_RECT] = {NULL, NULL, NULL, NULL};
const uint32_t RECT_COLOR[MAX_RECT] = {0xFF0000, 0x00FF00, 0x0000FF, 0x00FFFF};
#define BOX_COUNT 3

void create_rect_blended(void)
{
  for (int i = 0; i < BOX_COUNT; ++i)
  {
    rect[i] = lv_obj_create(lv_scr_act());
    lv_obj_set_pos(rect[i], 0, 0);
    lv_obj_set_size(rect[i], TFT_HOR_RES, TFT_VER_RES);
    lv_obj_set_style_bg_color(rect[i], lv_color_hex(RECT_COLOR[i]), LV_PART_MAIN);
  }
}

void update_rect_blended(void)
{
  static uint8_t opa = 255;

  for (int i = 0; i < BOX_COUNT; ++i)
    lv_obj_set_style_opa(rect[i], ((uint8_t)(opa + 64 * i) >> 1) + 64, LV_PART_MAIN);
  opa++;
}

void update_image_position(void)
{
  const uint16_t SCALE_FACTOR = 3;
  const int32_t MAX_X = ((MAX_IMAGES - 1) * TFT_HOR_RES) << SCALE_FACTOR;
  const uint16_t STEP = 2;

  static int32_t x = 0;
  static int16_t increment = STEP;
  static uint32_t last_tick = 0;

  uint32_t tick = HAL_GetTick();
  uint32_t delta_tick = tick - last_tick;
  x += increment * delta_tick;
  last_tick = tick;

  if (x > MAX_X) {
    increment = -STEP;
    x = MAX_X;
  } else if (x < 0) {
    increment = STEP;
    x = 0;
  }

  for (int i = 0; i < MAX_IMAGES; i++)
    lv_obj_set_pos(img[i], -(x >> SCALE_FACTOR) + i * TFT_HOR_RES, 0);
}



#define MAX_IMAGES_IN_LIBRARY 4
#define IMAGE_ROWS 2
#define IMAGE_COLUMNS 2

#define IMAGE_WIDTH 480
#define IMAGE_HEIGHT 272
lv_obj_t* img_library[MAX_IMAGES_IN_LIBRARY] = {NULL};
LV_IMAGE_DECLARE(irinox);
LV_IMAGE_DECLARE(irinox_alpha_argb8888);
LV_IMAGE_DECLARE(irinox_alpha_tsc6a);
LV_IMAGE_DECLARE(irinox_alpha_i8);


const lv_image_dsc_t* image_library_dsc[MAX_IMAGES_IN_LIBRARY] = {
  &irinox,
  &irinox_alpha_argb8888,
  &irinox_alpha_tsc6a,
  &irinox_alpha_i8,
};

static void create_images_library(void)
{
  lv_obj_t* rect = lv_obj_create(lv_scr_act());
  lv_obj_set_pos(rect, 0, 0);
  lv_obj_set_size(rect, IMAGE_WIDTH * IMAGE_COLUMNS, IMAGE_HEIGHT * IMAGE_ROWS);
  lv_obj_set_style_border_width(rect, 0, LV_PART_MAIN);
  lv_obj_set_style_radius(rect, 0, LV_PART_MAIN);
  lv_obj_set_style_bg_color(rect, lv_color_hex(0x000000), LV_PART_MAIN);

  for (int i = 0; i < IMAGE_ROWS; ++i)
  {
    for (int j = 0; j < IMAGE_COLUMNS; ++j)
    {
      img_library[i * IMAGE_COLUMNS + j] = lv_image_create(lv_screen_active());
      lv_image_set_src(img_library[i * IMAGE_COLUMNS + j], image_library_dsc[i * IMAGE_COLUMNS + j]);
      lv_obj_align(img_library[i * IMAGE_COLUMNS + j], LV_ALIGN_TOP_LEFT, j * IMAGE_WIDTH, i * IMAGE_HEIGHT);
    }
  }
}

void create_image_library(void)
{
  create_images_library();
}
