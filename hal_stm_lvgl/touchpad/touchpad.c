/**
 * @file touchpad.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "hal_stm_lvgl/tft/tft.h"
#include "lvgl/lvgl.h"

#include "stm32u5xx.h"
#include "main.h"

#include <stdio.h>

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void touchpad_read(lv_indev_t* drv, lv_indev_data_t* data);

/**********************
 *  STATIC VARIABLES
 **********************/
extern I2C_HandleTypeDef hi2c1;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

static void reset_touchpad(void)
{
  HAL_GPIO_WritePin(TS_RST_GPIO_Port, TS_RST_Pin, GPIO_PIN_RESET);
  HAL_Delay(10);
  HAL_GPIO_WritePin(TS_RST_GPIO_Port, TS_RST_Pin, GPIO_PIN_SET);
}

void touchpad_init(void)
{
  reset_touchpad();

  lv_indev_t* indev = lv_indev_create();
  lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);
  lv_indev_set_read_cb(indev, touchpad_read);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void touchpad_read(lv_indev_t* indev, lv_indev_data_t* data)
{
  uint8_t buf[5] = {0};
  const uint8_t FT5446_I2C_ADDR = 0x38 << 1;
  const uint8_t FT5446_TOUCH_REG = 0x02;

  static int16_t last_x = 0;
  static int16_t last_y = 0;

  if (HAL_I2C_Mem_Read(&hi2c1, FT5446_I2C_ADDR, FT5446_TOUCH_REG, I2C_MEMADD_SIZE_8BIT, buf, sizeof(buf), HAL_MAX_DELAY) == HAL_OK)
  {
    uint8_t touches = buf[0] & 0x0F;

    if (touches > 0)
    {
      int16_t x = ((buf[1] & 0x0F) << 8) | buf[2];
      int16_t y = ((buf[3] & 0x0F) << 8) | buf[4];

      data->point.x = x;
      data->point.y = y;
      last_x = data->point.x;
      last_y = data->point.y;
      data->state = LV_INDEV_STATE_PRESSED;
    }
    else
    {
      data->point.x = last_x;
      data->point.y = last_y;
      data->state = LV_INDEV_STATE_RELEASED;
    }
  }
}
