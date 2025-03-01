/**
  ******************************************************************************
  * @file    is25lp032d.c
  * @brief   This file provides the IS25LP032D QSPI drivers.
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "is25lp032d.h"

// /** @addtogroup BSP
//   * @{
//   */

// /** @addtogroup Components
//   * @{
//   */

// /** @defgroup IS25LP032D IS25LP032D
//   * @{
//   */

// /** @defgroup IS25LP032D_Private_Define IS25LP032D Private Define
//  * @{
//  */
// /* To avoid compiling issues for projects using previous version */
// #ifndef IS25LP032D_DUMMY_CYCLES_READ_DUAL_INOUT
// #define IS25LP032D_DUMMY_CYCLES_READ_DUAL_INOUT 4U
// #endif

// #ifndef IS25LP032D_DUMMY_CYCLES_READ_QUAD_INOUT
// #define IS25LP032D_DUMMY_CYCLES_READ_QUAD_INOUT 6U
// #endif
// /**
//  * @}
//  */

// /** @defgroup IS25LP032D_Exported_Functions IS25LP032D Exported Functions
//   * @{
//   */

// /**
//   * @brief  Get Flash information
//   * @param  pInfo pointer to information structure
//   * @retval QSPI memory status
//   */
// int32_t IS25LP032D_GetFlashInfo(IS25LP032D_Info_t *pInfo)
// {
//   /* Configure the structure with the memory configuration */
//   pInfo->FlashSize = IS25LP032D_FLASH_SIZE;
//   pInfo->EraseSectorSize = IS25LP032D_SECTOR_SIZE;
//   pInfo->EraseSectorsNumber = (IS25LP032D_FLASH_SIZE/IS25LP032D_SECTOR_SIZE);
//   pInfo->ProgPageSize = IS25LP032D_PAGE_SIZE;
//   pInfo->ProgPagesNumber = (IS25LP032D_FLASH_SIZE/IS25LP032D_PAGE_SIZE);

//   return IS25LP032D_OK;
// }


// /**
//   * @brief  This function reset the (WEL) Write Enable Latch bit.
//   * @param  Ctx OSPI handle
//   * @param  Mode Flash mode
//   * @retval QSPI memory status
//   */
// int32_t IS25LP032D_WriteDisable(OSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode)
// {
//   OSPI_RegularCmdTypeDef     s_command;

//   UNUSED(Mode); /* The command Write Disable is always 1-0-0 */

//   /* Initialize the read ID command */
//   s_command.InstructionMode   = QSPI_INSTRUCTION_1_LINE;
//   s_command.Instruction       = IS25LP032D_WRITE_DISABLE_CMD;
//   s_command.AddressMode       = QSPI_ADDRESS_NONE;
//   s_command.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
//   s_command.DummyCycles       = 0;
//   s_command.DataMode          = QSPI_DATA_NONE;
//   s_command.DdrMode           = QSPI_DDR_MODE_DISABLE;
//   s_command.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD;

//   /* Configure the command */
//   if (HAL_QSPI_Command(Ctx, &s_command, HAL_QSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
//   {
//     return IS25LP032D_ERROR;
//   }

//   return IS25LP032D_OK;
// }

// /**
//   * @brief  Writes an amount of data to the QSPI memory.
//   *         SPI/QPI; 1-1-1/1-1-4
//   * @param  Ctx OSPI handle
//   * @param  Mode Flash mode
//   * @param  pData Pointer to data to be written
//   * @param  WriteAddr Write start address
//   * @param  Size Size of data to write. Range 1 ~ 256
//   * @retval QSPI memory status
//   */
// int32_t IS25LP032D_PageProgram(OSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode, uint8_t *pData, uint32_t WriteAddr, uint32_t Size)
// {
//   OSPI_RegularCmdTypeDef s_command;

//   /* Setup program command */
//   switch(Mode)
//   {
//   case IS25LP032D_SPI_1I4O_MODE :              /* 1-1-4 program commands */
//     s_command.Instruction     = IS25LP032D_QUAD_IN_FAST_PROG_4_BYTE_ADDR_CMD;
//     s_command.InstructionMode = QSPI_INSTRUCTION_1_LINE;
//     s_command.AddressMode     = QSPI_ADDRESS_1_LINE;
//     s_command.DataMode        = QSPI_DATA_4_LINES;
//     break;

//   case IS25LP032D_SPI_MODE :                   /* 1-1-1 commands, Power on H/W default setting */
//   default :
//     s_command.Instruction     = IS25LP032D_PAGE_PROG_4_BYTE_ADDR_CMD;
//     s_command.InstructionMode = QSPI_INSTRUCTION_1_LINE;
//     s_command.AddressMode     = QSPI_ADDRESS_1_LINE;
//     s_command.DataMode        = QSPI_DATA_1_LINE;
//     break;
//   }

//   s_command.AddressSize       = QSPI_ADDRESS_32_BITS;
//   s_command.Address           = WriteAddr;
//   s_command.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
//   s_command.DummyCycles       = 0;
//   s_command.NbData            = Size;
//   s_command.DdrMode           = QSPI_DDR_MODE_DISABLE;
//   s_command.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD;

//   /* Configure the command */
//   if (HAL_QSPI_Command(Ctx, &s_command, HAL_QSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
//   {
//     return IS25LP032D_ERROR;
//   }

//   /* Transmission of the data */
//   if (HAL_QSPI_Transmit(Ctx, pData, HAL_QSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
//   {
//     return IS25LP032D_ERROR;
//   }

//   return IS25LP032D_OK;
// }

// /**
//   * @brief  Polling WIP(Write In Progress) bit become to 0
//   * @param  Ctx Component object pointer
//   * @param  Mode Interface mode
//   * @retval QSPI memory status
//   */
// int32_t IS25LP032D_AutoPollingMemReady(OSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode)
// {
//   OSPI_RegularCmdTypeDef     s_command;
//   QSPI_AutoPollingTypeDef s_config;

//   UNUSED(Mode); /* The command Read Status Register-1 is always 1-0-1 */

//   /* Configure automatic polling mode to wait for memory ready */
//   s_command.InstructionMode   = QSPI_INSTRUCTION_1_LINE;
//   s_command.Instruction       = IS25LP032D_READ_STATUS_REG1_CMD;
//   s_command.AddressMode       = QSPI_ADDRESS_NONE;
//   s_command.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
//   s_command.DataMode          = QSPI_DATA_1_LINE;
//   s_command.DummyCycles       = 0;
//   s_command.DdrMode           = QSPI_DDR_MODE_DISABLE;
//   s_command.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD;

//   s_config.Match              = 0;
//   s_config.Mask               = IS25LP032D_SR1_WIP;
//   s_config.MatchMode          = QSPI_MATCH_MODE_AND;
//   s_config.StatusBytesSize    = 1;
//   s_config.Interval           = 0x10;
//   s_config.AutomaticStop      = QSPI_AUTOMATIC_STOP_ENABLE;

//   if (HAL_QSPI_AutoPolling(Ctx, &s_command, &s_config, HAL_QSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
//   {
//     return IS25LP032D_ERROR;
//   }

//   return IS25LP032D_OK;
// }

// /**
//   * @brief  This function set the QSPI memory in 4-byte address mode
//   * @param  Ctx Component object pointer
//   * @param  Mode Interface mode
//   * @retval QSPI memory status
//   */
// int32_t IS25LP032D_Enter4BytesAddressMode(OSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode)
// {
//   OSPI_RegularCmdTypeDef s_command;
//   uint8_t reg1;

//   /* Initialize the read bank register command */
//   s_command.InstructionMode   = QSPI_INSTRUCTION_1_LINE;
//   s_command.Instruction       = IS25LP032D_READ_BANK_REG_CMD;
//   s_command.AddressMode       = QSPI_ADDRESS_NONE;
//   s_command.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
//   s_command.DataMode          = QSPI_DATA_1_LINE;
//   s_command.DummyCycles       = 0;
//   s_command.NbData            = 1;
//   s_command.DdrMode           = QSPI_DDR_MODE_DISABLE;
//   s_command.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD;

//   /* Configure the command */
//   if (HAL_QSPI_Command(Ctx, &s_command, HAL_QSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
//   {
//     return IS25LP032D_ERROR;
//   }

//   /* Reception of the data */
//   if (HAL_QSPI_Receive(Ctx, &reg1, HAL_QSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
//   {
//     return IS25LP032D_ERROR;
//   }

//   /* Enable write operations */
//   if( IS25LP032D_WriteEnable(Ctx,Mode)!=IS25LP032D_OK)
//   {
//     return IS25LP032D_ERROR;
//   }

//   /* Update Bank address register (with 4byte addressing bit) */
//   s_command.Instruction = IS25LP032D_WRITE_BANK_REG_CMD;
//   MODIFY_REG(reg1, IS25LP032D_BA_EXTADD, IS25LP032D_BA_EXTADD);

//   /* Configure the write volatile configuration register command */
//   if (HAL_QSPI_Command(Ctx, &s_command, HAL_QSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
//   {
//     return IS25LP032D_ERROR;
//   }

//   /* Transmission of the data Status Register 1 */
//   if (HAL_QSPI_Transmit(Ctx, &reg1, HAL_QSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
//   {
//     return IS25LP032D_ERROR;
//   }

//   return IS25LP032D_OK;
// }

// /**
//   * @brief  Reads an amount of data from the QSPI memory in STR mode.
//   *         SPI/DPI/QPI; 1-1-1/1-1-2/1-2-2/1-1-4/1-4-4
//   * @param  Ctx OSPI handle
//   * @param  Mode Flash mode
//   * @param  pData Pointer to data to be read
//   * @param  ReadAddr Read start address
//   * @param  Size Size of data to read
//   * @retval QSPI memory status
//   */
// int32_t IS25LP032D_ReadSTR(OSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode, uint8_t *pData, uint32_t ReadAddr, uint32_t Size)
// {
//   OSPI_RegularCmdTypeDef s_command;

//   switch(Mode)
//   {
//   case IS25LP032D_SPI_1I2O_MODE :           /* 1-1-2 read commands */
//     s_command.InstructionMode = QSPI_INSTRUCTION_1_LINE;
//     s_command.Instruction     = IS25LP032D_DUAL_OUT_FAST_READ_4_BYTE_ADDR_CMD;
//     s_command.AddressMode     = QSPI_ADDRESS_1_LINE;
//     s_command.DataMode        = QSPI_DATA_2_LINES;
//     s_command.DummyCycles     = IS25LP032D_DUMMY_CYCLES_READ;
//     break;

//   case IS25LP032D_SPI_2IO_MODE :           /* 1-2-2 read commands */
//     s_command.InstructionMode = QSPI_INSTRUCTION_1_LINE;
//     s_command.Instruction     = IS25LP032D_DUAL_INOUT_FAST_READ_4_BYTE_ADDR_CMD;
//     s_command.AddressMode     = QSPI_ADDRESS_2_LINES;
//     s_command.DataMode        = QSPI_DATA_2_LINES;
//     s_command.DummyCycles     = IS25LP032D_DUMMY_CYCLES_READ_DUAL_INOUT;
//     break;

//   case IS25LP032D_SPI_1I4O_MODE :           /* 1-1-4 read commands */
//     s_command.InstructionMode = QSPI_INSTRUCTION_1_LINE;
//     s_command.Instruction     = IS25LP032D_QUAD_OUT_FAST_READ_4_BYTE_ADDR_CMD;
//     s_command.AddressMode     = QSPI_ADDRESS_1_LINE;
//     s_command.DataMode        = QSPI_DATA_4_LINES;
//     s_command.DummyCycles     = IS25LP032D_DUMMY_CYCLES_READ;
//     break;

//   case IS25LP032D_SPI_4IO_MODE :           /* 1-4-4 read commands */
//     s_command.InstructionMode = QSPI_INSTRUCTION_1_LINE;
//     s_command.Instruction     = IS25LP032D_QUAD_INOUT_FAST_READ_4_BYTE_ADDR_CMD;
//     s_command.AddressMode     = QSPI_ADDRESS_4_LINES;
//     s_command.DataMode        = QSPI_DATA_4_LINES;
//     s_command.DummyCycles     = IS25LP032D_DUMMY_CYCLES_READ_QUAD_INOUT;
//     break;

//   case IS25LP032D_SPI_MODE :               /* 1-1-1 commands, Power on H/W default setting */
//   default:
//     s_command.InstructionMode = QSPI_INSTRUCTION_1_LINE;
//     s_command.Instruction     = IS25LP032D_FAST_READ_4_BYTE_ADDR_CMD;
//     s_command.AddressMode     = QSPI_ADDRESS_1_LINE;
//     s_command.DataMode        = QSPI_DATA_1_LINE;
//     s_command.DummyCycles     = IS25LP032D_DUMMY_CYCLES_READ;
//     break;
//   }

//   /* Initialize the read command */
//   s_command.AddressSize       = QSPI_ADDRESS_32_BITS;
//   s_command.Address           = ReadAddr;
//   s_command.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
//   s_command.NbData            = Size;
//   s_command.DdrMode           = QSPI_DDR_MODE_DISABLE;
//   s_command.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD;

//   /* Configure the command */
//   if (HAL_QSPI_Command(Ctx, &s_command, HAL_QSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
//   {
//     return IS25LP032D_ERROR;
//   }

//   /* Reception of the data */
//   if (HAL_QSPI_Receive(Ctx, pData, HAL_QSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
//   {
//     return IS25LP032D_ERROR;
//   }

//   return IS25LP032D_OK;
// }

// /**
//   * @brief  Erases the specified block of the QSPI memory.
//   *         IS25LP032D support 4K, 64K size block erase commands.
//   *         SPI; 1-0-0/1-1-0
//   * @param  Ctx OSPI handle
//   * @param  Mode Flash mode
//   * @param  BlockAddress Block address to erase
//   * @param  BlockSize 4K or 64K
//   * @retval QSPI memory status
//   */
// int32_t IS25LP032D_BlockErase(OSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode, uint32_t BlockAddress, IS25LP032D_Erase_t BlockSize)
// {
//   OSPI_RegularCmdTypeDef s_command;

//   UNUSED(Mode); /* The Erase commands are always 1-1-0 or 1-0-0 */

//   /* Setup erase command */
//   switch(BlockSize)
//   {
//   case IS25LP032D_ERASE_64K :
//     s_command.Instruction     = IS25LP032D_SECTOR_ERASE_4_BYTE_ADDR_CMD;
//     s_command.AddressMode     = QSPI_ADDRESS_1_LINE;
//     s_command.AddressSize     = QSPI_ADDRESS_32_BITS;
//     s_command.Address         = BlockAddress;
//     break;

//   case IS25LP032D_ERASE_CHIP :
//     s_command.Instruction     = IS25LP032D_BULK_ERASE_ALTERNATE_CMD;
//     s_command.AddressMode     = QSPI_ADDRESS_NONE;
//   break;

//   case IS25LP032D_ERASE_4K :
//   default :
//     s_command.Instruction     = IS25LP032D_SUBSECTOR_ERASE_4_BYTE_ADDR_CMD_4K;
//     s_command.AddressMode     = QSPI_ADDRESS_1_LINE;
//     s_command.AddressSize     = QSPI_ADDRESS_32_BITS;
//     s_command.Address         = BlockAddress;
//     break;
//   }

//   /* Initialize the erase command */
//   s_command.InstructionMode   = QSPI_INSTRUCTION_1_LINE;
//   s_command.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
//   s_command.DummyCycles       = 0;
//   s_command.DataMode          = QSPI_DATA_NONE;
//   s_command.DdrMode           = QSPI_DDR_MODE_DISABLE;
//   s_command.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD;

//   /* Send the command */
//   if(HAL_QSPI_Command(Ctx, &s_command, HAL_QSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
//   {
//     return IS25LP032D_ERROR;
//   }

//   return IS25LP032D_OK;
// }

// /**
//   * @brief  Whole chip erase.
//   *         SPI; 1-0-0
//   * @param  Ctx OSPI handle
//   * @param  Mode Flash mode
//   * @retval QSPI memory status
//   */
// int32_t IS25LP032D_ChipErase(OSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode)
// {
//   OSPI_RegularCmdTypeDef s_command;

//   UNUSED(Mode); /* The command Chip Erase is always 1-0-0 */

//   /* Initialize the erase command */
//   s_command.InstructionMode   = QSPI_INSTRUCTION_1_LINE;
//   s_command.AddressMode       = QSPI_ADDRESS_NONE;
//   s_command.Instruction       = IS25LP032D_BULK_ERASE_ALTERNATE_CMD;
//   s_command.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
//   s_command.DummyCycles       = 0;
//   s_command.DataMode          = QSPI_DATA_NONE;
//   s_command.DdrMode           = QSPI_DDR_MODE_DISABLE;
//   s_command.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD;

//   /* Send the command */
//   if (HAL_QSPI_Command(Ctx, &s_command, HAL_QSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
//   {
//     return IS25LP032D_ERROR;
//   }

//   return IS25LP032D_OK;
// }

/**
  * @brief  Enable memory mapped mode with STR transfers.
  * @param  Ctx OSPI handle
  * @param  Mode Flash mode
  * @retval QSPI memory status
  */
int32_t IS25LP032D_EnableMemoryMappedModeSTR(OSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode)
{
  OSPI_RegularCmdTypeDef s_command = {0};
  OSPI_MemoryMappedTypeDef s_mem_mapped_cfg = {0};

  /* Initialize the read command */
  s_command.OperationType      = HAL_OSPI_OPTYPE_COMMON_CFG;
  s_command.InstructionMode    = (Mode == IS25LP032D_SPI_MODE)
                                  ? HAL_OSPI_INSTRUCTION_1_LINE
                                  : HAL_OSPI_INSTRUCTION_4_LINES;
  s_command.InstructionSize    = HAL_OSPI_INSTRUCTION_8_BITS;
  s_command.Instruction        = IS25LP032D_FRD_FAST_READ_CMD;
  s_command.AddressMode        = (Mode == IS25LP032D_SPI_MODE)
                                  ? HAL_OSPI_ADDRESS_1_LINE
                                  : HAL_OSPI_ADDRESS_4_LINES;
  s_command.AddressSize        = HAL_OSPI_ADDRESS_24_BITS;
  s_command.AlternateBytesMode = HAL_OSPI_ALTERNATE_BYTES_NONE;
  s_command.DataMode           = (Mode == IS25LP032D_SPI_MODE)
                                  ? HAL_OSPI_DATA_1_LINE
                                  : HAL_OSPI_DATA_4_LINES;
  s_command.DummyCycles        = (Mode == IS25LP032D_SPI_MODE)
                                  ? IS25LP032D_DUMMY_CYCLES_FRD_FAST_READ
                                  : IS25LP032D_DUMMY_CYCLES_FRD_FAST_READ_QPI;

  /* Send the read command */
  if (HAL_OSPI_Command(Ctx, &s_command, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return IS25LP032D_ERROR;
  }

  /* Configure the memory mapped mode */
  s_mem_mapped_cfg.TimeOutActivation = HAL_OSPI_TIMEOUT_COUNTER_DISABLE;

  if (HAL_OSPI_MemoryMapped(Ctx, &s_mem_mapped_cfg) != HAL_OK)
  {
    return IS25LP032D_ERROR;
  }

  return IS25LP032D_OK;
}

/**
  * @brief  Enable memory mapped mode with DTR transfers.
  * @param  Ctx OSPI handle
  * @param  Mode Flash mode
  * @retval QSPI memory status
  */
int32_t IS25LP032D_EnableMemoryMappedModeDTR(OSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode)
{
  OSPI_RegularCmdTypeDef s_command = {0};
  OSPI_MemoryMappedTypeDef s_mem_mapped_cfg = {0};

  /* Initialize the read command */
  s_command.OperationType      = HAL_OSPI_OPTYPE_COMMON_CFG;
  s_command.InstructionMode    = (Mode == IS25LP032D_SPI_MODE)
                                  ? HAL_OSPI_INSTRUCTION_1_LINE
                                  : HAL_OSPI_INSTRUCTION_4_LINES;
  s_command.InstructionSize    = HAL_OSPI_INSTRUCTION_8_BITS;
  s_command.Instruction        = IS25LP032D_FRDTR_FAST_READ_DTR_CMD;
  s_command.AddressMode        = (Mode == IS25LP032D_SPI_MODE)
                                  ? HAL_OSPI_ADDRESS_1_LINE
                                  : HAL_OSPI_ADDRESS_4_LINES;
  s_command.AddressSize        = HAL_OSPI_ADDRESS_24_BITS;
  s_command.AddressDtrMode     = HAL_OSPI_ADDRESS_DTR_ENABLE;
  s_command.AlternateBytesMode = HAL_OSPI_ALTERNATE_BYTES_NONE;
  s_command.DataMode           = (Mode == IS25LP032D_SPI_MODE)
                                  ? HAL_OSPI_DATA_1_LINE
                                  : HAL_OSPI_DATA_4_LINES;
  s_command.DataDtrMode        = HAL_OSPI_DATA_DTR_ENABLE;
    s_command.DummyCycles        = (Mode == IS25LP032D_SPI_MODE)
                                  ? IS25LP032D_DUMMY_CYCLES_FRDTR_FAST_READ_DTR
                                  : IS25LP032D_DUMMY_CYCLES_FRDTR_FAST_READ_DTR_QPI;


  /* Send the read command */
  if (HAL_OSPI_Command(Ctx, &s_command, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return IS25LP032D_ERROR;
  }

  /* Configure the memory mapped mode */
  s_mem_mapped_cfg.TimeOutActivation = HAL_OSPI_TIMEOUT_COUNTER_DISABLE;

  if (HAL_OSPI_MemoryMapped(Ctx, &s_mem_mapped_cfg) != HAL_OK)
  {
    return IS25LP032D_ERROR;
  }

  return IS25LP032D_OK;
}

/**
  * @brief  This function send a Write Enable and wait it is effective.
  * @param  Ctx Component object pointer
  * @param  Mode Interface mode
  * @retval QSPI memory status
  */
int32_t IS25LP032D_WriteEnable(OSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode)
{
  OSPI_RegularCmdTypeDef s_command = {0};
  OSPI_AutoPollingTypeDef s_config = {0};

  s_command.InstructionMode    = (Mode == IS25LP032D_SPI_MODE)
                                  ? HAL_OSPI_INSTRUCTION_1_LINE
                                  : HAL_OSPI_INSTRUCTION_4_LINES;
  s_command.InstructionSize    = HAL_OSPI_INSTRUCTION_8_BITS;
  s_command.Instruction        = IS25LP032D_WREN_WRITE_ENABLE_CMD;
  s_command.AddressMode        = HAL_OSPI_ADDRESS_NONE;
  s_command.AlternateBytesMode = HAL_OSPI_ALTERNATE_BYTES_NONE;
  s_command.DataMode           = HAL_OSPI_DATA_NONE;
  s_command.DummyCycles        = 0;

  if (HAL_OSPI_Command(Ctx, &s_command, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return IS25LP032D_ERROR;
  }

  /* Configure automatic polling mode to wait for write enabling */
  s_command.InstructionMode    = (Mode == IS25LP032D_SPI_MODE)
                                  ? HAL_OSPI_INSTRUCTION_1_LINE
                                  : HAL_OSPI_INSTRUCTION_4_LINES;
  s_command.InstructionSize    = HAL_OSPI_INSTRUCTION_8_BITS;
  s_command.Instruction        = IS25LP032D_RDSR_READ_STATUS_REG_CMD;
  s_command.AddressMode        = HAL_OSPI_ADDRESS_NONE;
  s_command.AlternateBytesMode = HAL_OSPI_ALTERNATE_BYTES_NONE;
  s_command.DataMode           = (Mode == IS25LP032D_SPI_MODE)
                                  ? HAL_OSPI_DATA_1_LINE
                                  : HAL_OSPI_DATA_4_LINES;
  s_command.NbData             = 1;
  s_command.DummyCycles        = 0;

  /* Send the command */
  if (HAL_OSPI_Command(Ctx, &s_command, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return IS25LP032D_ERROR;
  }

  s_config.Match          = IS25LP032D_SR_WREN_WRITE_ENABLE_LATCH;
  s_config.Mask           = IS25LP032D_SR_WREN_WRITE_ENABLE_LATCH;
  s_config.MatchMode      = HAL_OSPI_MATCH_MODE_AND;
  s_config.Interval       = IS25LP032D_AUTOPOLLING_INTERVAL_TIME;
  s_config.AutomaticStop  = HAL_OSPI_AUTOMATIC_STOP_ENABLE;

  if (HAL_OSPI_AutoPolling(Ctx, &s_config, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return IS25LP032D_ERROR;
  }

  return IS25LP032D_OK;
}

/**
  * @brief  Read Flash Status register value
  * @param  Ctx OSPI handle
  * @param  Mode Flash mode
  * @param  Value to read from status register
  */
int32_t IS25LP032D_ReadStatusRegister(OSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode, uint8_t *Value)
{
  OSPI_RegularCmdTypeDef s_command = {0};

  /* Initialize the reading of status register */
  s_command.InstructionMode    = (Mode == IS25LP032D_SPI_MODE)
                                  ? HAL_OSPI_INSTRUCTION_1_LINE
                                  : HAL_OSPI_INSTRUCTION_4_LINES;
  s_command.InstructionSize    = HAL_OSPI_INSTRUCTION_8_BITS;
  s_command.Instruction        = IS25LP032D_RDSR_READ_STATUS_REG_CMD;
  s_command.AddressMode        = HAL_OSPI_ADDRESS_NONE;
  s_command.AlternateBytesMode = HAL_OSPI_ALTERNATE_BYTES_NONE;
  s_command.DataMode           = (Mode == IS25LP032D_SPI_MODE)
                                  ? HAL_OSPI_DATA_1_LINE
                                  : HAL_OSPI_DATA_4_LINES;
  s_command.NbData             = 1;
  s_command.DummyCycles        = 0;

  /* Send the command */
  if (HAL_OSPI_Command(Ctx, &s_command, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return IS25LP032D_ERROR;
  }

  /* Reception of the data */
  if (HAL_OSPI_Receive(Ctx, Value, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return IS25LP032D_ERROR;
  }

  return IS25LP032D_OK;
}

/**
  * @brief  Write Flash Status register value
  * @param  Ctx OSPI handle
  * @param  Mode Flash mode
  * @param  Value to write in the status register
  */
int32_t IS25LP032D_WriteStatusRegister(OSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode, uint8_t Value)
{
  OSPI_RegularCmdTypeDef s_command = {0};

  /* Initialize the writing of status register */
  s_command.InstructionMode    = (Mode == IS25LP032D_SPI_MODE)
                                  ? HAL_OSPI_INSTRUCTION_1_LINE
                                  : HAL_OSPI_INSTRUCTION_4_LINES;
  s_command.InstructionSize    = HAL_OSPI_INSTRUCTION_8_BITS;
  s_command.Instruction        = IS25LP032D_WRSR_WRITE_STATUS_REG_CMD;
  s_command.AddressMode        = HAL_OSPI_ADDRESS_NONE;
  s_command.AlternateBytesMode = HAL_OSPI_ALTERNATE_BYTES_NONE;
  s_command.DataMode           = (Mode == IS25LP032D_SPI_MODE)
                                  ? HAL_OSPI_DATA_1_LINE
                                  : HAL_OSPI_DATA_4_LINES;
  s_command.NbData             = 1;
  s_command.DummyCycles        = 0;

  /* Send the command */
  if (HAL_OSPI_Command(Ctx, &s_command, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return IS25LP032D_ERROR;
  }

  /* Reception of the data */
  if (HAL_OSPI_Transmit(Ctx, &Value, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return IS25LP032D_ERROR;
  }

  return IS25LP032D_OK;
}

/**
  * @brief  This function enable QPI mode for the flash
  * @param  Ctx Component object pointer
  * @retval QSPI memory status
  */
int32_t IS25LP032D_EnterQPIMode(OSPI_HandleTypeDef *Ctx)
{
  OSPI_RegularCmdTypeDef s_command = {0};

  /* Initialize the reset command */
  s_command.InstructionMode    = HAL_OSPI_INSTRUCTION_1_LINE;
  s_command.InstructionSize    = HAL_OSPI_INSTRUCTION_8_BITS;
  s_command.Instruction        = IS25LP032D_QPIEN_ENTER_QPI_MODE_CMD;
  s_command.AddressMode        = HAL_OSPI_ADDRESS_NONE;
  s_command.AlternateBytesMode = HAL_OSPI_ALTERNATE_BYTES_NONE;
  s_command.DataMode           = HAL_OSPI_DATA_NONE;
  s_command.DummyCycles        = 0;

  /* Send the command */
  if (HAL_OSPI_Command(Ctx, &s_command, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return IS25LP032D_ERROR;
  }

  return IS25LP032D_OK;
}


/**
  * @brief  Flash reset enable command
  * @param  Ctx OSPI handle
  * @param  Mode Flash mode
  * @retval QSPI memory status
  */
int32_t IS25LP032D_ResetEnable(OSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode)
{
  OSPI_RegularCmdTypeDef s_command = {0};

  /* Initialize the reset enable command */
  s_command.InstructionMode    = (Mode == IS25LP032D_SPI_MODE)
                                  ? HAL_OSPI_INSTRUCTION_1_LINE
                                  : HAL_OSPI_INSTRUCTION_4_LINES;
  s_command.InstructionSize    = HAL_OSPI_INSTRUCTION_8_BITS;
  s_command.Instruction        = IS25LP032D_RSTEN_RESET_ENABLE_CMD;
  s_command.AddressMode        = HAL_OSPI_ADDRESS_NONE;
  s_command.AlternateBytesMode = HAL_OSPI_ALTERNATE_BYTES_NONE;
  s_command.DataMode           = HAL_OSPI_DATA_NONE;
  s_command.DummyCycles        = 0;

  /* Send the command */
  if (HAL_OSPI_Command(Ctx, &s_command, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return IS25LP032D_ERROR;
  }

  return IS25LP032D_OK;
}

/**
  * @brief  Flash reset memory command
  * @param  Ctx OSPI handle
  * @param  Mode Flash mode
  * @retval QSPI memory status
  */
int32_t IS25LP032D_ResetMemory(OSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode)
{
  OSPI_RegularCmdTypeDef s_command = {0};

  /* Initialize the reset command */
  s_command.InstructionMode    = (Mode == IS25LP032D_SPI_MODE)
                                  ? HAL_OSPI_INSTRUCTION_1_LINE
                                  : HAL_OSPI_INSTRUCTION_4_LINES;
  s_command.InstructionSize    = HAL_OSPI_INSTRUCTION_8_BITS;
  s_command.Instruction        = IS25LP032D_RST_RESET_CMD;
  s_command.AddressMode        = HAL_OSPI_ADDRESS_NONE;
  s_command.AlternateBytesMode = HAL_OSPI_ALTERNATE_BYTES_NONE;
  s_command.DataMode           = HAL_OSPI_DATA_NONE;
  s_command.DummyCycles        = 0;

  /* Send the command */
  if (HAL_OSPI_Command(Ctx, &s_command, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return IS25LP032D_ERROR;
  }

  return IS25LP032D_OK;
}



// /**
//   * @brief  Read Flash 3 Byte IDs.
//   *         Manufacturer ID, Memory type, Memory density
//   *         SPI; 1-0-1
//   * @param  Ctx OSPI handle
//   * @param  Mode Flash mode
//   * @param  ID  Flash ID
//   * @retval QSPI memory status
//   */
// int32_t IS25LP032D_ReadID(OSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode, uint8_t *ID)
// {
//   OSPI_RegularCmdTypeDef s_command;

//   UNUSED(Mode); /* The command Read Identification is always 1-0-1 */

//   /* Initialize the read ID command */
//   s_command.InstructionMode   = QSPI_INSTRUCTION_1_LINE;
//   s_command.Instruction       = IS25LP032D_READ_ID_CMD2;
//   s_command.AddressMode       = QSPI_ADDRESS_NONE;
//   s_command.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
//   s_command.DataMode          = QSPI_DATA_1_LINE;
//   s_command.NbData            = 3;
//   s_command.DummyCycles       = 0;
//   s_command.DdrMode           = QSPI_DDR_MODE_DISABLE;
//   s_command.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD;

//   /* Configure the command */
//   if (HAL_QSPI_Command(Ctx, &s_command, HAL_QSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
//   {
//     return IS25LP032D_ERROR;
//   }

//   /* Reception of the data */
//   if (HAL_QSPI_Receive(Ctx, ID, HAL_QSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
//   {
//     return IS25LP032D_ERROR;
//   }

//   return IS25LP032D_OK;
// }

// /**
//   * @brief  Program/Erases suspend. Interruption Program/Erase operations.
//   *         After the device has entered Erase-Suspended mode,
//   *         system can read any address except the block/sector being Program/Erased.
//   *         SPI; 1-0-0
//   * @param  Ctx OSPI handle
//   * @param  Mode Flash moder
//   * @retval QSPI memory status
//   */
// int32_t IS25LP032D_ProgEraseSuspend(OSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode)
// {
//   OSPI_RegularCmdTypeDef s_command;

//   UNUSED(Mode); /* The command Program Erase Suspend is always 1-0-0 */

//   /* Initialize the IS25LP032D_PROG_ERASE_SUSPEND_CMD command */
//   s_command.InstructionMode   = QSPI_INSTRUCTION_1_LINE;
//   s_command.Instruction       = IS25LP032D_PROG_ERASE_SUSPEND_CMD;
//   s_command.AddressMode       = QSPI_ADDRESS_NONE;
//   s_command.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
//   s_command.DummyCycles       = 0;
//   s_command.DataMode          = QSPI_DATA_NONE;
//   s_command.DdrMode           = QSPI_DDR_MODE_DISABLE;
//   s_command.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD;

//   /* Configure the command */
//   if (HAL_QSPI_Command(Ctx, &s_command, HAL_QSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
//   {
//     return IS25LP032D_ERROR;
//   }

//   return IS25LP032D_OK;
// }

// /**
//   * @brief  Program/Erases resume.
//   *         SPI; 1-0-0
//   * @param  Ctx OSPI handle
//   * @param  Mode Flash mode
//   * @retval QSPI memory status
//   */
// int32_t IS25LP032D_ProgEraseResume(OSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode)
// {
//   OSPI_RegularCmdTypeDef s_command;

//   UNUSED(Mode); /* The command Program Erase Resume is always 1-0-0 */

//   /* Initialize the IS25LP032D_PROG_ERASE_RESUME_CMD command */
//   s_command.InstructionMode   = QSPI_INSTRUCTION_1_LINE;
//   s_command.Instruction       = IS25LP032D_PROG_ERASE_RESUME_CMD;
//   s_command.AddressMode       = QSPI_ADDRESS_NONE;
//   s_command.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
//   s_command.DummyCycles       = 0;
//   s_command.DataMode          = QSPI_DATA_NONE;
//   s_command.DdrMode           = QSPI_DDR_MODE_DISABLE;
//   s_command.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD;

//   /* Configure the command */
//   if (HAL_QSPI_Command(Ctx, &s_command, HAL_QSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
//   {
//     return IS25LP032D_ERROR;
//   }

//   return IS25LP032D_OK;
// }

// /**
//   * @brief  Enter deep sleep
//   * @param  Ctx OSPI handle
//   * @param  Mode Flash mode
//   * @retval QSPI memory status
//   */
// int32_t IS25LP032D_EnterDeepPowerDown(OSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode)
// {
//   UNUSED(Ctx);
//   UNUSED(Mode);

//   /* No Deep Power Down command for this memory */
//   return IS25LP032D_ERROR;
// }

// /**
//   * @brief  Reads an amount of SFDP data from the QSPI memory.
//   *         SFDP : Serial Flash Discoverable Parameter
//   * @param  Ctx OSPI handle
//   * @param  Mode Flash mode
//   * @param  pData Pointer to data to be read
//   *         ReadAddr Read start address
//   *         Size Size of data to read in Byte
//   * @retval QSPI memory status
//   */
// int32_t IS25LP032D_ReadSFDP(OSPI_HandleTypeDef *Ctx, IS25LP032D_Interface_t Mode, uint8_t *pData, uint32_t ReadAddr, uint32_t Size)
// {
//   UNUSED(Ctx);
//   UNUSED(Mode);
//   UNUSED(pData);
//   UNUSED(ReadAddr);
//   UNUSED(Size);

//   /* No Serial Flash Discoverable Parameter command for this memory */
//   return IS25LP032D_ERROR;
//  }

// /**
//   * @}
//   */

// /**
//   * @}
//   */

// /**
//   * @}
//   */

// /**
//   * @}
//   */

