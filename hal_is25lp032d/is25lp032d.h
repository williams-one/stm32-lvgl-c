/**
  ******************************************************************************
  * @file    IS25LP032D.h
  * @author  davide
  * @brief   This file contains all the description of the IS25LP032D QSPI memory.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef IS25LP032D_H
#define IS25LP032D_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "is25lp032d_conf.h"
/** @addtogroup BSP
  * @{
  */

/** @addtogroup Components
  * @{
  */

/** @addtogroup IS25LP032D
  * @{
  */

/** @defgroup IS25LP032D_Exported_Types
  * @{
  */
   typedef struct {
  uint32_t FlashSize;          /*!< Size of the flash */
  uint32_t EraseSectorSize;    /*!< Size of sectors for the erase operation */
  uint32_t EraseSectorsNumber; /*!< Number of sectors for the erase operation */
  uint32_t ProgPageSize;       /*!< Size of pages for the program operation */
  uint32_t ProgPagesNumber;    /*!< Number of pages for the program operation */
} IS25LP032D_Info;

/* IS25LP032D Component Error codes *********************************************/
#define IS25LP032D_OK                           0
#define IS25LP032D_ERROR_INIT                  -1
#define IS25LP032D_ERROR_COMMAND               -2
#define IS25LP032D_ERROR_TRANSMIT              -3
#define IS25LP032D_ERROR_RECEIVE               -4
#define IS25LP032D_ERROR_AUTOPOLLING           -5
#define IS25LP032D_ERROR_MEMORYMAPPED          -6
/**exported type **/


/******************IS25LP032D_Info_t**********************/
typedef struct
{
  uint32_t FlashSize;          /*!< Size of the flash */
  uint32_t EraseSectorSize;    /*!< Size of sectors for the erase operation */
  uint32_t EraseSectorsNumber; /*!< Number of sectors for the erase operation */
  uint32_t ProgPageSize;       /*!< Size of pages for the program operation */
  uint32_t ProgPagesNumber;    /*!< Number of pages for the program operation */
} IS25LP032D_Info_t;



/******************IS25LP032D_Transfer_t**********************/
typedef enum
{
  IS25LP032D_SPI_MODE = 0,                 /*!< 1-1-1 commands, Power on H/W default setting */
  IS25LP032D_SPI_2IO_MODE,                 /*!< 1-1-2, 1-2-2 read commands                   */
  IS25LP032D_SPI_4IO_MODE,                 /*!< 1-1-4, 1-4-4 read commands                   */
  IS25LP032D_QPI_MODE                      /*!< 4-4-4 commands                               */
} IS25LP032D_Interface_t;

/******************IS25LP032D_Transfer_t**********************/

typedef enum
{
  IS25LP032D_STR_TRANSFER = 0,             /* Single Transfer Rate */
  IS25LP032D_DTR_TRANSFER                  /* Double Transfer Rate */
} IS25LP032D_Transfer_t;


/******************IS25LP032D_Erase_t**********************/


typedef enum
{
  IS25LP032D_ERASE_4K = 0,                 /*!< 4K size Sector erase */
  IS25LP032D_ERASE_32K,                    /*!< 32K size Block erase */
  IS25LP032D_ERASE_64K,                    /*!< 64K size Block erase */
  IS25LP032D_ERASE_CHIP                    /*!< Whole chip erase     */
} IS25LP032D_Erase_t;
/**
  * @}
  */

/** @defgroup IS25LP032D_Exported_Constants
  * @{
  */

/**
  * @brief  IS25LP032D Configuration
  */
#define IS25LP032D_FLASH_SIZE                  0x4000000 	/* 512 MBits => 64MBytes		*/
#define IS25LP032D_SECTOR_SIZE                 0x10000   	/* sectors of 64KBytes 			*/
#define IS25LP032D_SUBSECTOR_SIZE              0x1000    	/* subsectors of 4kBytes 		*/
#define IS25LP032D_PAGE_SIZE                   0x100     	/* pages of 256 bytes 			*/

#define IS25LP512M_DIE_ERASE_MAX_TIME          270000
#define IS25LP256D_DIE_ERASE_MAX_TIME          180000
#define IS25LP032D_DIE_ERASE_MAX_TIME          40000
#define IS25LP032D_SECTOR_ERASE_MAX_TIME       1000
#define IS25LP032D_SUBSECTOR_ERASE_MAX_TIME    400

/**
  * @brief  IS25LP032D Commands
  */
/* Reset Operations */
#define IS25LP032D_RESET_ENABLE_CMD                     0x66
#define IS25LP032D_RESET_EXECUTE_CMD                    0x99

/* Identification Operations */
#define IS25LP032D_READ_ID_CMD                          0x9F
#define IS25LP032D_MULTIPLE_IO_READ_ID_CMD              0xAF
#define IS25LP032D_READ_SERIAL_FLASH_DISCO_PARAM_CMD    0x5A

/* Read Operations */
#define IS25LP032D_READ_CMD                             0x03

#define IS25LP032D_FAST_READ_CMD                        0x0B
#define IS25LP032D_FAST_READ_DTR_CMD                    0x0D

#define IS25LP032D_DUAL_OUT_FAST_READ_CMD               0x3B

#define IS25LP032D_DUAL_INOUT_FAST_READ_CMD             0xBB
#define IS25LP032D_DUAL_INOUT_FAST_READ_DTR_CMD         0xBD

#define IS25LP032D_QUAD_OUT_FAST_READ_CMD               0x6C
#define IS25LP032D_DUMMY_CLOCK_CYCLES_READ_QUAD 			8

#define IS25LP032D_QUAD_INOUT_FAST_READ_CMD             0xEB
#define IS25LP032D_QUAD_INOUT_FAST_READ_DTR_CMD         0xED

/* Write Operations */
#define IS25LP032D_WRITE_ENABLE_CMD                    	0x06
#define IS25LP032D_WRITE_DISABLE_CMD                   	0x04

/* Register Operations */
#define IS25LP032D_READ_STATUS_REG_CMD                  0x05
#define IS25LP032D_WRITE_STATUS_REG_CMD                 0x01

/* Program Operations */
#define IS25LP032D_PAGE_PROG_CMD                        0x02

#define IS25LP032D_QUAD_IN_FAST_PROG_CMD                0x32
#define IS25LP032D_EXT_QUAD_IN_FAST_PROG_CMD            0x3E

/* Erase Operations */
#define IS25LP032D_SUBSECTOR_ERASE_CMD_4K               0x21

#define IS25LP032D_SUBSECTOR_ERASE_CMD_32K              0x52

#define IS25LP032D_SECTOR_ERASE_CMD                     0xD8

#define IS25LP032D_DIE_ERASE_CMD                        0xC7

#define IS25LP032D_PROG_ERASE_RESUME_CMD                0x7A
#define IS25LP032D_PROG_ERASE_SUSPEND_CMD               0x75

/* Quad Operations */
#define IS25LP032D_ENTER_QUAD_CMD                       0x35
#define IS25LP032D_EXIT_QUAD_CMD                        0xF5
#define IS25LP032D_ENTER_DEEP_POWER_DOWN                0xB9
#define IS25LP032D_RELEASE_FROM_DEEP_POWER_DOWN         0xAB


/**
  * @brief  IS25LP032D Registers
  */
/* Status Register */
#define IS25LP032D_SR_WIP                      ((uint8_t)0x01)    /*!< Write in progress */
#define IS25LP032D_SR_WREN                     ((uint8_t)0x02)    /*!< Write enable latch */


/**
  * @}
  */

/** @defgroup IS25LP032D_Exported_Functions
  * @{
  */

int32_t IS25LP032D_ResetChip(void);
int32_t IS25LP032D_AutoPollingMemReady(uint32_t tout);
int32_t IS25LP032D_WriteEnable(void);
int32_t IS25LP032D_ConfigureMemory(void);
int32_t IS25LP032D_EnableMemoryMappedMode(void);
//   MX66UW1G45G_ResetMemory(&hxspi1, MX66UW1G45G_SPI_MODE, MX66UW1G45G_STR_TRANSFER);
//   HAL_Delay(MX66UW1G45G_RESET_MAX_TIME);

//   /* Enable write operations */
//   MX66UW1G45G_WriteEnable(&hxspi1, MX66UW1G45G_SPI_MODE, MX66UW1G45G_STR_TRANSFER);

//   /* Write Configuration register 2 (with new dummy cycles) */
//   MX66UW1G45G_WriteCfg2Register(&hxspi1, MX66UW1G45G_SPI_MODE, MX66UW1G45G_STR_TRANSFER, MX66UW1G45G_CR2_REG3_ADDR, MX66UW1G45G_CR2_DC_6_CYCLES);

//   /* Enable write operations */
//   MX66UW1G45G_WriteEnable(&hxspi1, MX66UW1G45G_SPI_MODE, MX66UW1G45G_STR_TRANSFER);

//   /* Write Configuration register 2 (with Octal I/O SPI protocol) */
//   MX66UW1G45G_WriteCfg2Register(&hxspi1, MX66UW1G45G_SPI_MODE, MX66UW1G45G_STR_TRANSFER, MX66UW1G45G_CR2_REG1_ADDR, MX66UW1G45G_CR2_DOPI);

//   /* Wait that the configuration is effective and check that memory is ready */
//   HAL_Delay(MX66UW1G45G_WRITE_REG_MAX_TIME);

//   MX66UW1G45G_EnableDTRMemoryMappedMode(&hxspi1, MX66UW1G45G_OPI_MODE);

//int32_t IS25LP032D_GetFlashInfo(IS25LP032D_Info_t *pInfo);
//int32_t IS25LP032D_AutoPollingMemReady(QSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode);
///* Register/Setting Commands *************************************************/
//int32_t IS25LP032D_WriteEnable(QSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode);
//int32_t IS25LP032D_BlockErase(QSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode, uint32_t BlockAddress, IS25LP032D_Erase_t BlockSize);
//int32_t IS25LP032D_ChipErase(QSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode);
//int32_t IS25LP032D_PageProgram(QSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode, uint8_t *pData, uint32_t WriteAddr, uint32_t Size);
//int32_t IS25LP032D_ReadSTR(QSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode, uint8_t *pData, uint32_t ReadAddr, uint32_t Size);
//int32_t IS25LP032D_ReadDTR(QSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode, uint8_t *pData, uint32_t ReadAddr, uint32_t Size);
//int32_t IS25LP032D_EnterQPIMode(QSPI_HandleTypeDef *Ctx);
//int32_t IS25LP032D_ExitQPIMode(QSPI_HandleTypeDef *Ctx);

//int32_t IS25LP032D_EnableMemoryMappedModeSTR(QSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode);
//int32_t IS25LP032D_EnableMemoryMappedModeDTR(QSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode);
//int32_t IS25LP032D_WriteDisable(QSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode);
//int32_t IS25LP032D_ReadID(QSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode, uint8_t *ID);

//int32_t IS25LP032D_ResetMemory(QSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode);
//int32_t IS25LP032D_ResetEnable(QSPI_HandleTypeDef *Ctx);

//int32_t IS25LP032D_ReleaseFromDeepPowerDown(QSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode);
//int32_t IS25LP032D_EnterDeepPowerDown(QSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode);
//int32_t IS25LP032D_ProgEraseResume(QSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode);
//int32_t IS25LP032D_ProgEraseSuspend(QSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode);
/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __IS25LP032D_H */

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
