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
static void touchpad_read(lv_indev_t *drv, lv_indev_data_t *data);

/**********************
 *  STATIC VARIABLES
 **********************/
extern I2C_HandleTypeDef hi2c2;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void touchpad_init(void)
{
  lv_indev_t * indev = lv_indev_create();
  lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);
  lv_indev_set_read_cb(indev, touchpad_read);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void touchpad_read(lv_indev_t *indev, lv_indev_data_t *data)
{
  uint8_t touches = 0;
  uint8_t buf[6];
  const uint16_t STATUS_REG = 0x814E;
  const uint16_t TOUCH_POS_REG = 0x8150;
  uint8_t ZERO = 0;

  static int16_t last_x = 0;
  static int16_t last_y = 0;

  HAL_I2C_Mem_Read(&hi2c2, 0xBA, STATUS_REG, 2, buf, 1, HAL_MAX_DELAY);
  touches = (0x0F & buf[0]);

  HAL_I2C_Mem_Write(&hi2c2, 0xBA, STATUS_REG, 2, &ZERO, 1, HAL_MAX_DELAY);

  if (touches > 0)
  {
    HAL_I2C_Mem_Read(&hi2c2, 0xBA, TOUCH_POS_REG, 2, buf, 4, HAL_MAX_DELAY);
    int16_t x = buf[0] + (buf[1] << 8);
    int16_t y = buf[2] + (buf[3] << 8);

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
