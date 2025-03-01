/**
  ******************************************************************************
  * @file    IS25LP032D_LAE.h
  * @author  davide
  * @brief   This file contains all the description of the IS25LP032D_LAE QSPI memory.
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
#ifndef IS25LP032D_LAE_H
#define IS25LP032D_LAE_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "is25lp032d_lae_conf.h"
/** @addtogroup BSP
  * @{
  */

/** @addtogroup Components
  * @{
  */

/** @addtogroup IS25LP032D_LAE
  * @{
  */

/** @defgroup IS25LP032D_LAE_Exported_Types
  * @{
  */
   typedef struct {
  uint32_t FlashSize;          /*!< Size of the flash */
  uint32_t EraseSectorSize;    /*!< Size of sectors for the erase operation */
  uint32_t EraseSectorsNumber; /*!< Number of sectors for the erase operation */
  uint32_t ProgPageSize;       /*!< Size of pages for the program operation */
  uint32_t ProgPagesNumber;    /*!< Number of pages for the program operation */
} IS25LP032D_LAE_Info;

/* IS25LP032D_LAE Component Error codes *********************************************/
#define IS25LP032D_LAE_OK                           0
#define IS25LP032D_LAE_ERROR_INIT                  -1
#define IS25LP032D_LAE_ERROR_COMMAND               -2
#define IS25LP032D_LAE_ERROR_TRANSMIT              -3
#define IS25LP032D_LAE_ERROR_RECEIVE               -4
#define IS25LP032D_LAE_ERROR_AUTOPOLLING           -5
#define IS25LP032D_LAE_ERROR_MEMORYMAPPED          -6
/**exported type **/


/******************IS25LP032D_LAE_Info_t**********************/
typedef struct
{
  uint32_t FlashSize;          /*!< Size of the flash */
  uint32_t EraseSectorSize;    /*!< Size of sectors for the erase operation */
  uint32_t EraseSectorsNumber; /*!< Number of sectors for the erase operation */
  uint32_t ProgPageSize;       /*!< Size of pages for the program operation */
  uint32_t ProgPagesNumber;    /*!< Number of pages for the program operation */
} IS25LP032D_LAE_Info_t;



/******************IS25LP032D_LAE_Transfer_t**********************/
typedef enum
{
  IS25LP032D_LAE_SPI_MODE = 0,                 /*!< 1-1-1 commands, Power on H/W default setting */
  IS25LP032D_LAE_SPI_2IO_MODE,                 /*!< 1-1-2, 1-2-2 read commands                   */
  IS25LP032D_LAE_SPI_4IO_MODE,                 /*!< 1-1-4, 1-4-4 read commands                   */
  IS25LP032D_LAE_QPI_MODE                      /*!< 4-4-4 commands                               */
} IS25LP032D_LAE_Interface_t;

/******************IS25LP032D_LAE_Transfer_t**********************/

typedef enum
{
  IS25LP032D_LAE_STR_TRANSFER = 0,             /* Single Transfer Rate */
  IS25LP032D_LAE_DTR_TRANSFER                  /* Double Transfer Rate */
} IS25LP032D_LAE_Transfer_t;


/******************IS25LP032D_LAE_Erase_t**********************/


typedef enum
{
  IS25LP032D_LAE_ERASE_4K = 0,                 /*!< 4K size Sector erase */
  IS25LP032D_LAE_ERASE_32K,                    /*!< 32K size Block erase */
  IS25LP032D_LAE_ERASE_64K,                    /*!< 64K size Block erase */
  IS25LP032D_LAE_ERASE_CHIP                    /*!< Whole chip erase     */
} IS25LP032D_LAE_Erase_t;
/**
  * @}
  */

/** @defgroup IS25LP032D_LAE_Exported_Constants
  * @{
  */

/**
  * @brief  IS25LP032D_LAE Configuration
  */
#define IS25LP032D_LAE_FLASH_SIZE                  0x400000 	/* 32 MBits => 4MBytes					*/
#define IS25LP032D_LAE_SECTOR_SIZE                 0x10000   	/* 64 sectors of 64KBytes 				*/
#define IS25LP032D_LAE_SUBSECTOR_SIZE              0x1000    	/* 1024 subsectors of 4kBytes 		*/
#define IS25LP032D_LAE_PAGE_SIZE                   0x100     	/* 16384 pages of 256 bytes 			*/

#define IS25LP032D_LAE_DIE_ERASE_MAX_TIME          40000
#define IS25LP032D_LAE_SECTOR_ERASE_MAX_TIME       1000
#define IS25LP032D_LAE_SUBSECTOR_ERASE_MAX_TIME    400

/**
  * @brief  IS25LP032D_LAE Commands
  */
/* Reset Operations */
#define IS25LP032D_LAE_RESET_ENABLE_CMD                     0x66
#define IS25LP032D_LAE_RESET_EXECUTE_CMD                    0x99

/* Identification Operations */
#define IS25LP032D_LAE_READ_ID_CMD                          0x9F
#define IS25LP032D_LAE_MULTIPLE_IO_READ_ID_CMD              0xAF
#define IS25LP032D_LAE_READ_SERIAL_FLASH_DISCO_PARAM_CMD    0x5A

/* Read Operations */
#define IS25LP032D_LAE_READ_CMD                             0x03

#define IS25LP032D_LAE_FAST_READ_CMD                        0x0B
#define IS25LP032D_LAE_FAST_READ_DTR_CMD                    0x0D

#define IS25LP032D_LAE_DUAL_OUT_FAST_READ_CMD               0x3B

#define IS25LP032D_LAE_DUAL_INOUT_FAST_READ_CMD             0xBB
#define IS25LP032D_LAE_DUAL_INOUT_FAST_READ_DTR_CMD         0xBD

#define IS25LP032D_LAE_QUAD_OUT_FAST_READ_CMD               0x6B
#define IS25LP032D_LAE_DUMMY_CLOCK_CYCLES_READ_QUAD 			8

#define IS25LP032D_LAE_QUAD_INOUT_FAST_READ_CMD             0xEB
#define IS25LP032D_LAE_QUAD_INOUT_FAST_READ_DTR_CMD         0xED

/* Write Operations */
#define IS25LP032D_LAE_WRITE_ENABLE_CMD                    	0x06
#define IS25LP032D_LAE_WRITE_DISABLE_CMD                   	0x04

/* Register Operations */
#define IS25LP032D_LAE_READ_STATUS_REG_CMD                  0x05
#define IS25LP032D_LAE_WRITE_STATUS_REG_CMD                 0x01

/* Program Operations */
#define IS25LP032D_LAE_PAGE_PROG_CMD                        0x02

#define IS25LP032D_LAE_QUAD_IN_FAST_PROG_CMD                0x32
#define IS25LP032D_LAE_EXT_QUAD_IN_FAST_PROG_CMD            0x38

/* Erase Operations */
#define IS25LP032D_LAE_SUBSECTOR_ERASE_CMD_4K               0x20

#define IS25LP032D_LAE_SUBSECTOR_ERASE_CMD_32K              0x52

#define IS25LP032D_LAE_SECTOR_ERASE_CMD                     0xD8

#define IS25LP032D_LAE_DIE_ERASE_CMD                        0xC7

#define IS25LP032D_LAE_PROG_ERASE_RESUME_CMD                0x7A
#define IS25LP032D_LAE_PROG_ERASE_SUSPEND_CMD               0x75

/* Quad Operations */
#define IS25LP032D_LAE_ENTER_QUAD_CMD                       0x35
#define IS25LP032D_LAE_EXIT_QUAD_CMD                        0xF5
#define IS25LP032D_LAE_ENTER_DEEP_POWER_DOWN                0xB9
#define IS25LP032D_LAE_RELEASE_FROM_DEEP_POWER_DOWN         0xAB


/**
  * @brief  IS25LP032D_LAE Registers
  */
/* Status Register */
#define IS25LP032D_LAE_SR_WIP                      ((uint8_t)0x01)    /*!< Write in progress */
#define IS25LP032D_LAE_SR_WREN                     ((uint8_t)0x02)    /*!< Write enable latch */


/**
  * @}
  */

/** @defgroup IS25LP032D_LAE_Exported_Functions
  * @{
  */

uint8_t OSPI_Init(void);
uint8_t OSPI_EnableMemoryMappedMode(void);
uint8_t OSPI_ResetChip(void);
uint8_t OSPI_Erase_Chip(void);
uint8_t OSPI_EraseSector(uint32_t EraseStartAddress, uint32_t EraseEndAddress);
uint8_t OSPI_WriteMemory(uint8_t* buffer, uint32_t address,uint32_t buffer_size);
uint8_t OSPI_WriteEnable(void);
uint8_t OSPI_Configuration(void);

//int32_t IS25LP032D_LAE_GetFlashInfo(IS25LP032D_LAE_Info_t *pInfo);
//int32_t IS25LP032D_LAE_AutoPollingMemReady(QSPI_HandleTypeDef *Ctx, IS25LP032D_LAE_Interface_t Mode);
///* Register/Setting Commands *************************************************/
//int32_t IS25LP032D_LAE_WriteEnable(QSPI_HandleTypeDef *Ctx, IS25LP032D_LAE_Interface_t Mode);
//int32_t IS25LP032D_LAE_BlockErase(QSPI_HandleTypeDef *Ctx, IS25LP032D_LAE_Interface_t Mode, uint32_t BlockAddress, IS25LP032D_LAE_Erase_t BlockSize);
//int32_t IS25LP032D_LAE_ChipErase(QSPI_HandleTypeDef *Ctx, IS25LP032D_LAE_Interface_t Mode);
//int32_t IS25LP032D_LAE_PageProgram(QSPI_HandleTypeDef *Ctx, IS25LP032D_LAE_Interface_t Mode, uint8_t *pData, uint32_t WriteAddr, uint32_t Size);
//int32_t IS25LP032D_LAE_ReadSTR(QSPI_HandleTypeDef *Ctx, IS25LP032D_LAE_Interface_t Mode, uint8_t *pData, uint32_t ReadAddr, uint32_t Size);
//int32_t IS25LP032D_LAE_ReadDTR(QSPI_HandleTypeDef *Ctx, IS25LP032D_LAE_Interface_t Mode, uint8_t *pData, uint32_t ReadAddr, uint32_t Size);
//int32_t IS25LP032D_LAE_EnterQPIMode(QSPI_HandleTypeDef *Ctx);
//int32_t IS25LP032D_LAE_ExitQPIMode(QSPI_HandleTypeDef *Ctx);

//int32_t IS25LP032D_LAE_EnableMemoryMappedModeSTR(QSPI_HandleTypeDef *Ctx, IS25LP032D_LAE_Interface_t Mode);
//int32_t IS25LP032D_LAE_EnableMemoryMappedModeDTR(QSPI_HandleTypeDef *Ctx, IS25LP032D_LAE_Interface_t Mode);
//int32_t IS25LP032D_LAE_WriteDisable(QSPI_HandleTypeDef *Ctx, IS25LP032D_LAE_Interface_t Mode);
//int32_t IS25LP032D_LAE_ReadID(QSPI_HandleTypeDef *Ctx, IS25LP032D_LAE_Interface_t Mode, uint8_t *ID);

//int32_t IS25LP032D_LAE_ResetMemory(QSPI_HandleTypeDef *Ctx, IS25LP032D_LAE_Interface_t Mode);
//int32_t IS25LP032D_LAE_ResetEnable(QSPI_HandleTypeDef *Ctx);

//int32_t IS25LP032D_LAE_ReleaseFromDeepPowerDown(QSPI_HandleTypeDef *Ctx, IS25LP032D_LAE_Interface_t Mode);
//int32_t IS25LP032D_LAE_EnterDeepPowerDown(QSPI_HandleTypeDef *Ctx, IS25LP032D_LAE_Interface_t Mode);
//int32_t IS25LP032D_LAE_ProgEraseResume(QSPI_HandleTypeDef *Ctx, IS25LP032D_LAE_Interface_t Mode);
//int32_t IS25LP032D_LAE_ProgEraseSuspend(QSPI_HandleTypeDef *Ctx, IS25LP032D_LAE_Interface_t Mode);
/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __IS25LP032D_LAE_H */

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
