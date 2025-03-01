/**
  ******************************************************************************
  * @file    is25lp032d_conf.h
  * @brief   This file contains the configurations of the IS25LP032D QSPI memory.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef IS25LP032D_CONF_H
#define IS25LP032D_CONF_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32u5xx_hal.h"

/** @addtogroup BSP
  * @{
  */

/** @addtogroup Components
  * @{
  */

/** @addtogroup IS25LP032D
  * @brief     This file provides a set of definitions for the ISSI
  *            IS25LP032D memory configuration.
  * @{
  */

/** @addtogroup IS25LP032D_Exported_Constants
  * @{
  */

/* Dummy cycles for STR read mode */
#define IS25LP032D_DUMMY_CYCLES_FRD_FAST_READ               8U
#define IS25LP032D_DUMMY_CYCLES_FRD_FAST_READ_QPI           6U
// #define IS25LP032D_DUMMY_CYCLES_READ            8U
// #define IS25LP032D_DUMMY_CYCLES_READ_DUAL_INOUT 4U
// #define IS25LP032D_DUMMY_CYCLES_READ_QUAD_INOUT 6U

/* Dummy cycles for DTR read mode */
#define IS25LP032D_DUMMY_CYCLES_FRDTR_FAST_READ_DTR         8U
#define IS25LP032D_DUMMY_CYCLES_FRDTR_FAST_READ_DTR_QPI     6U
// #define IS25LP032D_DUMMY_CYCLES_READ_QUAD_DTR       8U
// #define IS25LP032D_DUMMY_CYCLES_READ_DTR            8U
// #define IS25LP032D_DUMMY_CYCLES_READ_DUAL_INOUT_DTR 4U
// #define IS25LP032D_DUMMY_CYCLES_READ_QUAD_INOUT_DTR 6U

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* IS25LP032D_CONF_H */

