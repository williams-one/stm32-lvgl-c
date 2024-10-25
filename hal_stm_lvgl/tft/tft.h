/**
 * @file tft.h
 *
 */

#ifndef TFT_H
#define TFT_H

/*********************
 *      INCLUDES
 *********************/
#include <stdint.h>
#include "lvgl/src/misc/lv_color.h"
#include "lvgl/src/misc/lv_area.h"

/*********************
 *      DEFINES
 *********************/
#define TFT_HOR_RES 800
#define TFT_VER_RES 480

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/
void tft_init(void);
void create_test_scene(void);

/**********************
 *      MACROS
 **********************/

#endif
