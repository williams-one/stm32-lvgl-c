/**
  ******************************************************************************
  * @file    is25lp032d.h
  * @brief   This file contains all the description of the IS25LP032D QSPI memory.
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
  * @brief     This file provides a set of definitions for the ISSI
  *            IS25LP032D memory (configuration, commands, registers).
  * @{
  */

/** @defgroup IS25LP032D_Exported_Constants
  * @{
  */

/* IS25LP032DAGMFI01 Spansion Memory */
/**
  * @brief  IS25LP032D Configuration
  */

#define IS25LP032D_BLOCK_64K                    (uint32_t) (64 * 1024)        /* 256 blocks of 64KBytes  */
#define IS25LP032D_SECTOR_4K                   (uint32_t) (4  * 1024)        /* 4096 sectors of 4KBytes */

#define IS25LP032D_FLASH_SIZE                           0x400000    /* 32 MBits => 4MBytes */
#define IS25LP032D_SECTOR_SIZE                          0x1000      /* 1024 sectors of 4kBytes */
#define IS25LP032D_PAGE_SIZE                            0x100       /* 16384 pages of 256 bytes */

#define IS25LP032D_BULK_ERASE_MAX_TIME                  24000
#define IS25LP032D_SECTOR_ERASE_MAX_TIME                300

#define IS25LP032D_WRITE_REG_MAX_TIME                   15

#define IS25LP032D_RESET_MAX_TIME                       5

#define IS25LP032D_AUTOPOLLING_INTERVAL_TIME            10

/**
  * @brief  IS25LP032D Error codes
  */
#define IS25LP032D_OK                                   (0)
#define IS25LP032D_ERROR                                (-1)





/**
  * @brief  IS25LP032D Commands
  */
/* Reset Operations */
#define IS25LP032D_RSTEN_RESET_ENABLE_CMD               0x66
#define IS25LP032D_RST_RESET_CMD                        0x99

/* Register Operations */
#define IS25LP032D_WRSR_WRITE_STATUS_REG_CMD            0x01
#define IS25LP032D_RDSR_READ_STATUS_REG_CMD             0x05
#define IS25LP032D_WREN_WRITE_ENABLE_CMD                0x06
#define IS25LP032D_QPIEN_ENTER_QPI_MODE_CMD             0x35

/* Read Operations */
#define IS25LP032D_FRD_FAST_READ_CMD                    0x0B
#define IS25LP032D_FRDTR_FAST_READ_DTR_CMD              0x0D




/* Identification Operations */
#define IS25LP032D_READ_ID_CMD                           0x90
#define IS25LP032D_READ_ID_CMD2                          0x9F
#define IS25LP032D_READ_ELECTRONIC_SIGNATURE             0xAB
#define IS25LP032D_READ_SERIAL_FLASH_DISCO_PARAM_CMD     0x5A

/* Register Operations */
#define IS25LP032D_READ_STATUS_REG1_CMD                  0x05
#define IS25LP032D_READ_STATUS_REG2_CMD                  0x07
#define IS25LP032D_READ_CONFIGURATION_REG1_CMD           0x35

#define IS25LP032D_WRITE_DISABLE_CMD                     0x04
#define IS25LP032D_WRITE_ENABLE_CMD                      0x06
#define IS25LP032D_CLEAR_STATUS_REG1_CMD                 0x30
#define IS25LP032D_READ_AUTOBOOT_REG_CMD                 0x14
#define IS25LP032D_WRITE_AUTOBOOT_REG_CMD                0x15
#define IS25LP032D_READ_BANK_REG_CMD                     0x16
#define IS25LP032D_WRITE_BANK_REG_CMD                    0x17
#define IS25LP032D_ACCESS_BANK_REG_CMD                   0xB9
#define IS25LP032D_READ_DATA_LEARNING_PATTERN_CMD        0x41
#define IS25LP032D_PGM_NV_DATA_LEARNING_REG_CMD          0x43
#define IS25LP032D_WRITE_VOL_DATA_LEARNING_REG_CMD       0x4A

/* Read Operations */
#define IS25LP032D_READ_CMD                              0x03
#define IS25LP032D_READ_4_BYTE_ADDR_CMD                  0x13
#define IS25LP032D_FAST_READ_CMD                         0x0B
#define IS25LP032D_FAST_READ_4_BYTE_ADDR_CMD             0x0C
#define IS25LP032D_FAST_READ_DDR_CMD                     0x0D
#define IS25LP032D_FAST_READ__DDR_4_BYTE_ADDR_CMD        0x0E
#define IS25LP032D_DUAL_OUT_FAST_READ_CMD                0x3B
#define IS25LP032D_DUAL_OUT_FAST_READ_4_BYTE_ADDR_CMD    0x3C
#define IS25LP032D_QUAD_OUT_FAST_READ_CMD                0x6B
#define IS25LP032D_QUAD_OUT_FAST_READ_4_BYTE_ADDR_CMD    0x6C
#define IS25LP032D_DUAL_INOUT_FAST_READ_CMD              0xBB
#define IS25LP032D_DUAL_INOUT_FAST_READ_DTR_CMD          0xBD
#define IS25LP032D_DUAL_INOUT_FAST_READ_4_BYTE_ADDR_CMD  0xBC
#define IS25LP032D_DDR_DUAL_INOUT_READ_4_BYTE_ADDR_CMD   0xBE
#define IS25LP032D_QUAD_INOUT_FAST_READ_CMD              0xEB
#define IS25LP032D_QUAD_INOUT_FAST_READ_4_BYTE_ADDR_CMD  0xEC
#define IS25LP032D_QUAD_INOUT_FAST_READ_DDR_CMD          0xED
#define IS25LP032D_QUAD_INOUT_READ_DDR_4_BYTE_ADDR_CMD   0xEE

/* Program Operations */
#define IS25LP032D_PAGE_PROG_CMD                         0x02
#define IS25LP032D_PAGE_PROG_4_BYTE_ADDR_CMD             0x12
#define IS25LP032D_QUAD_IN_FAST_PROG_CMD                 0x32
#define IS25LP032D_QUAD_IN_FAST_PROG_ALTERNATE_CMD       0x38
#define IS25LP032D_QUAD_IN_FAST_PROG_4_BYTE_ADDR_CMD     0x34
#define IS25LP032D_PROGRAM_SUSPEND_CMD                   0x85
#define IS25LP032D_PROGRAM_RESUME_CMD                    0x8A

/* Erase Operations */
#define IS25LP032D_SUBSECTOR_ERASE_CMD_4K                0x20
#define IS25LP032D_SUBSECTOR_ERASE_4_BYTE_ADDR_CMD_4K    0x21
#define IS25LP032D_SECTOR_ERASE_CMD                      0xD8
#define IS25LP032D_SECTOR_ERASE_4_BYTE_ADDR_CMD          0xDC
#define IS25LP032D_BULK_ERASE_CMD                        0x60
#define IS25LP032D_BULK_ERASE_ALTERNATE_CMD              0xC7
#define IS25LP032D_PROG_ERASE_SUSPEND_CMD                0x75
#define IS25LP032D_PROG_ERASE_RESUME_CMD                 0x7A

/* One-Time Programmable Operations */
#define IS25LP032D_PROG_OTP_ARRAY_CMD                    0x42
#define IS25LP032D_READ_OTP_ARRAY_CMD                    0x4B

/* Deep Power Operations */
#define IS25LP032D_ENTER_DEEP_POWER_DOWN                 0xB9

/* Advanced Sector Protection Operations */
#define IS25LP032D_READ_DYB_CMD                          0xE0
#define IS25LP032D_WRITE_DYB_CMD                         0xE1
#define IS25LP032D_READ_PPB_CMD                          0xE2
#define IS25LP032D_PROGRAM_PPB_CMD                       0xE3
#define IS25LP032D_ERASE_PPB_CMD                         0xE4
#define IS25LP032D_READ_ASP_CMD                          0x2B
#define IS25LP032D_PROGRAM_ASP_CMD                       0x2F
#define IS25LP032D_READ_PPB_LOCKBIT_CMD                  0xA7
#define IS25LP032D_WRITE_PPB_LOCKBIT_CMD                 0xA6
#define IS25LP032D_READ_PASSWORD_CMD                     0xE7
#define IS25LP032D_PROGRAM_PASSWORD_CMD                  0xE8
#define IS25LP032D_UNLOCK_PASSWORD_CMD                   0xE9

/**
  * @brief  IS25LP032D Registers
  */
/* Status Register-1 */
#define IS25LP032D_SR_WREN_WRITE_ENABLE_LATCH           ((uint8_t)0x02)     /*!< Write Registers, program or commands are accepted */
#define IS25LP032D_SR_QE_QUAD_ENABLE                    ((uint8_t)0x40)     /*!< Quad Enable */



/* Status Register-1 */
#define IS25LP032D_SR1_WIP                               ((uint8_t)0x01)      /*!< Write in progress, device busy */
#define IS25LP032D_SR1_WREN                              ((uint8_t)0x02)      /*!< Write Registers, program or commands are accepted */
#define IS25LP032D_SR1_BP0                               ((uint8_t)0x04)      /*!< Sector0 protected from Program or Erase */
#define IS25LP032D_SR1_BP1                               ((uint8_t)0x08)      /*!< Sector1 protected from Program or Erase */
#define IS25LP032D_SR1_BP2                               ((uint8_t)0x10)      /*!< Sector2 protected from Program or Erase */
#define IS25LP032D_SR1_ERERR                             ((uint8_t)0x20)      /*!< Erase error */
#define IS25LP032D_SR1_PGERR                             ((uint8_t)0x40)      /*!< Program error */
#define IS25LP032D_SR1_SRWD                              ((uint8_t)0x80)      /*!< Status Register Write Disable */

/* Status Register-2 */
#define IS25LP032D_SR2_PS                                ((uint8_t)0x01)      /*!< Program in Suspend mode */
#define IS25LP032D_SR2_ES                                ((uint8_t)0x02)      /*!< Erase Suspend Mode */

/* Configuration Register CR1 */
#define IS25LP032D_CR1_FREEZE                            ((uint8_t)0x01)      /*!< Block protection and OTP locked */
#define IS25LP032D_CR1_QUAD                              ((uint8_t)0x02)      /*!< Quad mode enable */
#define IS25LP032D_CR1_BPNV                              ((uint8_t)0x08)      /*!< BP2-0 bits of Status Reg are volatile */
#define IS25LP032D_CR1_TBPROT                            ((uint8_t)0x20)      /*!< BPstarts at bottom */
#define IS25LP032D_CR1_LC_MASK                           ((uint8_t)0xC0)      /*!< Latency Code mask */
#define IS25LP032D_CR1_LC0                               ((uint8_t)0x00)      /*!< Latency Code = 0 */
#define IS25LP032D_CR1_LC1                               ((uint8_t)0x40)      /*!< Latency Code = 1 */
#define IS25LP032D_CR1_LC2                               ((uint8_t)0x80)      /*!< Latency Code = 2 */
#define IS25LP032D_CR1_LC3                               ((uint8_t)0xC0)      /*!< Latency Code = 3 */

/* AutoBoot Register */
#define IS25LP032D_AB_EN                                 ((uint32_t)0x00000001) /*!< AutoBoot Enabled     */
#define IS25LP032D_AB_SD_MASK                            ((uint32_t)0x000001FE) /*!< AutoBoot Start Delay mask */
#define IS25LP032D_AB_SA_MASK                            ((uint32_t)0xFFFFFE00) /*!< AutoBoot Start Address mask */

/* Bank Address Register */
#define IS25LP032D_BA_BA24                               ((uint8_t)0x01)      /*!< A24 for 512 Mb device */
#define IS25LP032D_BA_BA25                               ((uint8_t)0x02)      /*!< A25 for 512 Mb device */
#define IS25LP032D_BA_EXTADD                             ((uint8_t)0x80)      /*!< 4 bytes addressing required from command */

/* ASP Register */
#define IS25LP032D_ASP_PSTMLB                            ((uint16_t)0x0002)   /*!< Persistent protection mode not permanently enabled */
#define IS25LP032D_ASP_PWSMLB                            ((uint16_t)0x0003)   /*!< Password protection mode not permanently enabled */

/* PPB Lock Register */
#define IS25LP032D_PPBLOCK                               ((uint8_t)0x01)      /*!< PPB array may be programmed or erased */

/**
  * @}
  */

/** @defgroup IS25LP032D_Exported_Types IS25LP032D Exported Types
  * @{
  */

typedef struct {
  uint32_t FlashSize;                     /*!< Size of the flash                         */
  uint32_t EraseSectorSize;               /*!< Size of sectors for the erase operation   */
  uint32_t EraseSectorsNumber;            /*!< Number of sectors for the erase operation */
  uint32_t ProgPageSize;                  /*!< Size of pages for the program operation   */
  uint32_t ProgPagesNumber;               /*!< Number of pages for the program operation */
} IS25LP032D_Info_t;

typedef enum
{
  IS25LP032D_SPI_MODE = 0,                 /*!< 1-1-1 commands, Power on H/W default setting */
  IS25LP032D_QPI_MODE                      /*!< 4-4-4 commands                               */
} IS25LP032D_Interface_t;

typedef enum
{
  IS25LP032D_STR_TRANSFER = 0,             /*!< Single Transfer Rate */
  IS25LP032D_DTR_TRANSFER                  /*!< Double Transfer Rate */
} IS25LP032D_Transfer_t;

typedef enum
{
  IS25LP032D_DUALFLASH_DISABLE = 0,        /*!< Single flash mode    */
} IS25LP032D_DualFlash_t;

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

/** @defgroup IS25LP032D_Exported_Functions
  * @{
  */

int32_t IS25LP032D_GetFlashInfo(IS25LP032D_Info_t *pInfo);
int32_t IS25LP032D_AutoPollingMemReady(OSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode);


/* Read/Write Array Commands **************************************************/
int32_t IS25LP032D_ReadSTR(OSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode, uint8_t *pData, uint32_t ReadAddr, uint32_t Size);
int32_t IS25LP032D_ReadDTR(OSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode, uint8_t *pData, uint32_t ReadAddr, uint32_t Size);
int32_t IS25LP032D_PageProgram(OSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode, uint8_t *pData, uint32_t WriteAddr, uint32_t Size);
int32_t IS25LP032D_PageProgramDTR(OSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode, uint8_t *pData, uint32_t WriteAddr, uint32_t Size);
int32_t IS25LP032D_BlockErase(OSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode, uint32_t BlockAddress, IS25LP032D_Erase_t BlockSize);
int32_t IS25LP032D_ChipErase(OSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode);
int32_t IS25LP032D_EnableMemoryMappedModeSTR(OSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode);
int32_t IS25LP032D_EnableMemoryMappedModeDTR(OSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode);

/* Register/Setting Commands **************************************************/
int32_t IS25LP032D_WriteEnable(OSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode);
int32_t IS25LP032D_ReadStatusRegister(OSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode, uint8_t *Value);
int32_t IS25LP032D_WriteStatusRegister(OSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode, uint8_t Value);
int32_t IS25LP032D_EnterQPIMode(OSPI_HandleTypeDef *Ctx);






int32_t IS25LP032D_WriteDisable(OSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode);
int32_t IS25LP032D_EnterDeepPowerDown(OSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode);
int32_t IS25LP032D_ReadSFDP(OSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode, uint8_t *pData, uint32_t ReadAddr, uint32_t Size);

/* ID/Security Commands *******************************************************/
int32_t IS25LP032D_ReadID(OSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode, uint8_t *ID);

/* Reset Commands *************************************************************/
int32_t IS25LP032D_ResetEnable(OSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode);
int32_t IS25LP032D_ResetMemory(OSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode);

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

#endif /* IS25LP032D_H */
