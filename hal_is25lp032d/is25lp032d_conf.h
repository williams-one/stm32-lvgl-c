/**
  ******************************************************************************
  * @file    is25lp032_conf.h
  * @author  davide
  * @brief   This file contains all the description of the QSPI memory.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef IS25LP032D_CONF_H
#define IS25LP032D_CONF_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32u5xx.h"
#include "stm32u5xx_hal.h"

/** @addtogroup BSP
  * @{
  */
#define CONF_QSPI_DUMMY_CLOCK                  8U

/* Dummy cycles for STR read mode */
#define IS25LP032D_DUMMY_CYCLES_READ_QUAD      8U
#define IS25LP032D_DUMMY_CYCLES_READ           8U
/* Dummy cycles for DTR read mode */
#define IS25LP032D_DUMMY_CYCLES_READ_DTR       6U
#define IS25LP032D_DUMMY_CYCLES_READ_QUAD_DTR  8U

#ifdef __cplusplus
}
#endif

#endif /* IS25LP032D_CONF_H */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
