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
#define RESOLUTION_800x480
// #define RESOLUTION_480x272

#if defined(RESOLUTION_800x480)
  #define TFT_HOR_RES 800
  #define TFT_VER_RES 480
#elif defined(RESOLUTION_480x272)
  #define TFT_HOR_RES 480
  #define TFT_VER_RES 272
#else
  #error "No resolution defined"
#endif

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/
void tft_init(void);

/**********************
 *      MACROS
 **********************/

#endif
