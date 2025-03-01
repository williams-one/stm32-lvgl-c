/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    octospi.c
  * @brief   This file provides code for the configuration
  *          of the OCTOSPI instances.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN 0 */
#include	"is25lp032d_lae.h"

/* USER CODE END 0 */

extern OSPI_HandleTypeDef hospi1;

/**
  * @brief	perform chip reset
  * @param	none
  * @retval	OK, ERROR
  */
uint8_t OSPI_ResetChip(void) {
	OSPI_RegularCmdTypeDef s_command = {0};
	uint32_t temp = 0;
	/* Erasing Sequence -------------------------------------------------- */
	s_command.OperationType      = HAL_OSPI_OPTYPE_COMMON_CFG;
	s_command.FlashId            = HAL_OSPI_FLASH_ID_1;
	s_command.InstructionMode    = HAL_OSPI_INSTRUCTION_1_LINE;
	s_command.InstructionDtrMode = HAL_OSPI_INSTRUCTION_DTR_DISABLE;
	s_command.InstructionSize    = HAL_OSPI_INSTRUCTION_8_BITS;
	s_command.Instruction        = IS25LP032D_LAE_RESET_ENABLE_CMD;
	s_command.AddressMode        = HAL_OSPI_ADDRESS_NONE;
	s_command.AlternateBytesMode = HAL_OSPI_ALTERNATE_BYTES_NONE;
	s_command.DataMode           = HAL_OSPI_DATA_NONE;
	s_command.DummyCycles        = 0U;
	s_command.DQSMode            = HAL_OSPI_DQS_DISABLE;
	s_command.SIOOMode           = HAL_OSPI_SIOO_INST_EVERY_CMD;

	/* Send the command */
	if (HAL_OSPI_Command(&hospi1, &s_command, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
	{
		return HAL_ERROR;
	}
	for (temp = 0; temp < 0x2f; temp++) {
		__NOP();
	}

	s_command.OperationType      = HAL_OSPI_OPTYPE_COMMON_CFG;
	s_command.FlashId            = HAL_OSPI_FLASH_ID_1;
	s_command.InstructionMode    = HAL_OSPI_INSTRUCTION_1_LINE;
	s_command.InstructionDtrMode = HAL_OSPI_INSTRUCTION_DTR_DISABLE;
	s_command.InstructionSize    = HAL_OSPI_INSTRUCTION_8_BITS;
	s_command.Instruction        = IS25LP032D_LAE_RESET_EXECUTE_CMD;
	s_command.AddressMode        = HAL_OSPI_ADDRESS_NONE;
	s_command.AlternateBytesMode = HAL_OSPI_ALTERNATE_BYTES_NONE;
	s_command.DataMode           = HAL_OSPI_DATA_NONE;
	s_command.DummyCycles        = 0U;
	s_command.DQSMode            = HAL_OSPI_DQS_DISABLE;
	s_command.SIOOMode           = HAL_OSPI_SIOO_INST_EVERY_CMD;

	/* Send the command */
	if (HAL_OSPI_Command(&hospi1, &s_command, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
	{
		return HAL_ERROR;
	}



	s_command.OperationType      = HAL_OSPI_OPTYPE_COMMON_CFG;
	s_command.FlashId            = HAL_OSPI_FLASH_ID_1;
	s_command.InstructionMode    = HAL_OSPI_INSTRUCTION_1_LINE;
	s_command.InstructionDtrMode = HAL_OSPI_INSTRUCTION_DTR_DISABLE;
	s_command.InstructionSize    = HAL_OSPI_INSTRUCTION_8_BITS;
	s_command.Instruction        = IS25LP032D_LAE_RESET_ENABLE_CMD;
	s_command.AddressMode        = HAL_OSPI_ADDRESS_NONE;
	s_command.AlternateBytesMode = HAL_OSPI_ALTERNATE_BYTES_NONE;
	s_command.DataMode           = HAL_OSPI_DATA_NONE;
	s_command.DummyCycles        = 0U;
	s_command.DQSMode            = HAL_OSPI_DQS_DISABLE;
	s_command.SIOOMode           = HAL_OSPI_SIOO_INST_EVERY_CMD;

	/* Send the command */
	if (HAL_OSPI_Command(&hospi1, &s_command, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
	{
		return HAL_ERROR;
	}
	for (temp = 0; temp < 0x2f; temp++) {
		__NOP();
	}

	s_command.OperationType      = HAL_OSPI_OPTYPE_COMMON_CFG;
	s_command.FlashId            = HAL_OSPI_FLASH_ID_1;
	s_command.InstructionMode    = HAL_OSPI_INSTRUCTION_1_LINE;
	s_command.InstructionDtrMode = HAL_OSPI_INSTRUCTION_DTR_DISABLE;
	s_command.InstructionSize    = HAL_OSPI_INSTRUCTION_8_BITS;
	s_command.Instruction        = IS25LP032D_LAE_RESET_EXECUTE_CMD;
	s_command.AddressMode        = HAL_OSPI_ADDRESS_NONE;
	s_command.AlternateBytesMode = HAL_OSPI_ALTERNATE_BYTES_NONE;
	s_command.DataMode           = HAL_OSPI_DATA_NONE;
	s_command.DummyCycles        = 0U;
	s_command.DQSMode            = HAL_OSPI_DQS_DISABLE;
	s_command.SIOOMode           = HAL_OSPI_SIOO_INST_EVERY_CMD;

	/* Send the command */
	if (HAL_OSPI_Command(&hospi1, &s_command, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
	{
		return HAL_ERROR;
	}



	s_command.OperationType      = HAL_OSPI_OPTYPE_COMMON_CFG;
	s_command.FlashId            = HAL_OSPI_FLASH_ID_1;
	s_command.InstructionMode    = HAL_OSPI_INSTRUCTION_1_LINE;
	s_command.InstructionDtrMode = HAL_OSPI_INSTRUCTION_DTR_DISABLE;
	s_command.InstructionSize    = HAL_OSPI_INSTRUCTION_8_BITS;
	s_command.Instruction        = IS25LP032D_LAE_RESET_ENABLE_CMD;
	s_command.AddressMode        = HAL_OSPI_ADDRESS_NONE;
	s_command.AlternateBytesMode = HAL_OSPI_ALTERNATE_BYTES_NONE;
	s_command.DataMode           = HAL_OSPI_DATA_NONE;
	s_command.DummyCycles        = 0U;
	s_command.DQSMode            = HAL_OSPI_DQS_DISABLE;
	s_command.SIOOMode           = HAL_OSPI_SIOO_INST_EVERY_CMD;

	/* Send the command */
	if (HAL_OSPI_Command(&hospi1, &s_command, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
	{
		return HAL_ERROR;
	}
	for (temp = 0; temp < 0x2f; temp++) {
		__NOP();
	}

	s_command.OperationType      = HAL_OSPI_OPTYPE_COMMON_CFG;
	s_command.FlashId            = HAL_OSPI_FLASH_ID_1;
	s_command.InstructionMode    = HAL_OSPI_INSTRUCTION_1_LINE;
	s_command.InstructionDtrMode = HAL_OSPI_INSTRUCTION_DTR_DISABLE;
	s_command.InstructionSize    = HAL_OSPI_INSTRUCTION_8_BITS;
	s_command.Instruction        = IS25LP032D_LAE_RESET_EXECUTE_CMD;
	s_command.AddressMode        = HAL_OSPI_ADDRESS_NONE;
	s_command.AlternateBytesMode = HAL_OSPI_ALTERNATE_BYTES_NONE;
	s_command.DataMode           = HAL_OSPI_DATA_NONE;
	s_command.DummyCycles        = 0U;
	s_command.DQSMode            = HAL_OSPI_DQS_DISABLE;
	s_command.SIOOMode           = HAL_OSPI_SIOO_INST_EVERY_CMD;

	/* Send the command */
	if (HAL_OSPI_Command(&hospi1, &s_command, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
	{
		return HAL_ERROR;
	}

	return HAL_OK;
}


/**
  * @brief	auto polling memory ready
  * @param	timeout
  * @retval	OK, ERROR
  */
uint8_t OSPI_AutoPollingMemReady(uint32_t tout) {
  OSPI_RegularCmdTypeDef  s_command = {0};
  OSPI_AutoPollingTypeDef s_config = {0};


  /* Configure automatic polling mode to wait for memory ready */
  s_command.OperationType      = HAL_OSPI_OPTYPE_COMMON_CFG;
  s_command.FlashId            = HAL_OSPI_FLASH_ID_1;
  s_command.InstructionMode    = HAL_OSPI_INSTRUCTION_1_LINE;
  s_command.InstructionDtrMode = HAL_OSPI_INSTRUCTION_DTR_DISABLE;
  s_command.InstructionSize    = HAL_OSPI_INSTRUCTION_8_BITS;
  s_command.Instruction        = IS25LP032D_LAE_READ_STATUS_REG_CMD;
  s_command.AddressMode        = HAL_OSPI_ADDRESS_NONE;
  s_command.AddressDtrMode     = HAL_OSPI_ADDRESS_DTR_DISABLE;
  s_command.AddressSize        = HAL_OSPI_ADDRESS_8_BITS;
  s_command.Address            = 0U;
  s_command.AlternateBytesMode = HAL_OSPI_ALTERNATE_BYTES_NONE;
  s_command.DataMode           = HAL_OSPI_DATA_1_LINE;
  s_command.DataDtrMode        = HAL_OSPI_DATA_DTR_DISABLE;
  s_command.DummyCycles        = 0;
  s_command.NbData             = 1U;
  s_command.DQSMode            = HAL_OSPI_DQS_DISABLE;
  s_command.SIOOMode           = HAL_OSPI_SIOO_INST_EVERY_CMD;

  s_config.Match         = 0U;
  s_config.Mask          = 0x01;
  s_config.MatchMode     = HAL_OSPI_MATCH_MODE_AND;
  s_config.Interval      = 0x10;
  s_config.AutomaticStop = HAL_OSPI_AUTOMATIC_STOP_ENABLE;

  if (HAL_OSPI_Command(&hospi1, &s_command, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return HAL_ERROR;
  }

  if (HAL_OSPI_AutoPolling(&hospi1, &s_config, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return HAL_ERROR;
  }

	return HAL_OK;
}

/**
  * @brief	Enable quad mode
  * @param	none
  * @retval	OK, ERROR
  */
uint8_t OSPI_Configuration(void) {
  OSPI_RegularCmdTypeDef s_command = {0};
  uint8_t test_buffer[4] = { 0 };


  /* Initialize the reading of status register */
  s_command.OperationType      = HAL_OSPI_OPTYPE_COMMON_CFG;
  s_command.FlashId            = HAL_OSPI_FLASH_ID_1;
  s_command.InstructionMode    = HAL_OSPI_INSTRUCTION_1_LINE;
  s_command.InstructionDtrMode = HAL_OSPI_INSTRUCTION_DTR_DISABLE;
  s_command.InstructionSize    = HAL_OSPI_INSTRUCTION_8_BITS;
  s_command.Instruction        = IS25LP032D_LAE_READ_STATUS_REG_CMD;
  s_command.AddressMode        = HAL_OSPI_ADDRESS_NONE;
  s_command.AddressDtrMode     = HAL_OSPI_ADDRESS_DTR_DISABLE;
  s_command.AddressSize        = HAL_OSPI_ADDRESS_32_BITS;
  s_command.Address            = 0U;
  s_command.AlternateBytesMode = HAL_OSPI_ALTERNATE_BYTES_NONE;
  s_command.DataMode           = HAL_OSPI_DATA_1_LINE;
  s_command.DataDtrMode        = HAL_OSPI_DATA_DTR_DISABLE;
  s_command.DummyCycles        = 0;
  s_command.NbData             = 1U;
  s_command.DQSMode            = HAL_OSPI_DQS_DISABLE;
  s_command.SIOOMode           = HAL_OSPI_SIOO_INST_EVERY_CMD;

  /* Send the command */
  if (HAL_OSPI_Command(&hospi1, &s_command, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return HAL_ERROR;
  }

  /* Reception of the data */
  if (HAL_OSPI_Receive(&hospi1, test_buffer, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return HAL_ERROR;
  }

	/*modify buffer to enable quad mode*/
	test_buffer[0] |= 0x40;


  /* Initialize the writing of status register */
  s_command.OperationType      = HAL_OSPI_OPTYPE_COMMON_CFG;
  s_command.FlashId            = HAL_OSPI_FLASH_ID_1;
  s_command.InstructionMode    = HAL_OSPI_INSTRUCTION_1_LINE;
  s_command.InstructionDtrMode = HAL_OSPI_INSTRUCTION_DTR_DISABLE;
  s_command.InstructionSize    = HAL_OSPI_INSTRUCTION_8_BITS;
  s_command.Instruction        = IS25LP032D_LAE_WRITE_STATUS_REG_CMD;
  s_command.AddressMode        = HAL_OSPI_ADDRESS_NONE;
  s_command.AddressDtrMode     = HAL_OSPI_ADDRESS_DTR_DISABLE;
  s_command.AddressSize        = HAL_OSPI_ADDRESS_32_BITS;
  s_command.Address            = 0U;
  s_command.AlternateBytesMode = HAL_OSPI_ALTERNATE_BYTES_NONE;
  s_command.DataMode           = HAL_OSPI_DATA_1_LINE;
  s_command.DataDtrMode        = HAL_OSPI_DATA_DTR_DISABLE;
  s_command.DummyCycles        = 0U;
  s_command.NbData             = 1U;
  s_command.DQSMode            = HAL_OSPI_DQS_DISABLE;
  s_command.SIOOMode           = HAL_OSPI_SIOO_INST_EVERY_CMD;

  /* Send the command */
  if (HAL_OSPI_Command(&hospi1, &s_command, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return HAL_ERROR;
  }

  if (HAL_OSPI_Transmit(&hospi1, test_buffer, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return HAL_ERROR;
  }

  return HAL_OK;
}


/**
  * @brief	Enable memory mapped mode
  * @param	none
  * @retval	OK, ERROR
  */
uint8_t OSPI_EnableMemoryMappedMode(void) {
  OSPI_RegularCmdTypeDef   s_command = {0};
  OSPI_MemoryMappedTypeDef	s_mem_mapped_cfg = {0};

  /* Initialize the read command */
  s_command.OperationType      = HAL_OSPI_OPTYPE_COMMON_CFG;
  s_command.FlashId            = HAL_OSPI_FLASH_ID_1;
  s_command.InstructionMode    = HAL_OSPI_INSTRUCTION_1_LINE;
  s_command.InstructionDtrMode = HAL_OSPI_INSTRUCTION_DTR_DISABLE;
  s_command.InstructionSize    = HAL_OSPI_INSTRUCTION_8_BITS;
  s_command.Instruction        = IS25LP032D_LAE_QUAD_OUT_FAST_READ_CMD;
  s_command.AddressMode        = HAL_OSPI_ADDRESS_1_LINE;
  s_command.AddressDtrMode     = HAL_OSPI_ADDRESS_DTR_DISABLE;
  s_command.AddressSize        = HAL_OSPI_ADDRESS_24_BITS;
  s_command.AlternateBytesMode = HAL_OSPI_ALTERNATE_BYTES_NONE;
  s_command.DataMode           = HAL_OSPI_DATA_4_LINES;
  s_command.DataDtrMode        = HAL_OSPI_DATA_DTR_DISABLE;
  s_command.DummyCycles        = IS25LP032D_LAE_DUMMY_CLOCK_CYCLES_READ_QUAD;
  s_command.DQSMode            = HAL_OSPI_DQS_DISABLE;
  s_command.SIOOMode           = HAL_OSPI_SIOO_INST_EVERY_CMD;

  /* Send the read command */
  if (HAL_OSPI_Command(&hospi1, &s_command, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return HAL_ERROR;
  }

  /* Configure the memory mapped mode */
  s_mem_mapped_cfg.TimeOutActivation = HAL_OSPI_TIMEOUT_COUNTER_DISABLE;

  if (HAL_OSPI_MemoryMapped(&hospi1, &s_mem_mapped_cfg) != HAL_OK)
  {
    return HAL_ERROR;
  }

  return HAL_OK;
}



uint8_t OSPI_WriteEnable(void) {
  OSPI_RegularCmdTypeDef 	s_command = {0};
  OSPI_AutoPollingTypeDef 	s_config = {0};

  /* Initialize the write enable command */
  s_command.OperationType      = HAL_OSPI_OPTYPE_COMMON_CFG;
  s_command.FlashId            = HAL_OSPI_FLASH_ID_1;
  s_command.InstructionMode    = HAL_OSPI_INSTRUCTION_1_LINE;
  s_command.InstructionDtrMode = HAL_OSPI_INSTRUCTION_DTR_DISABLE;
  s_command.InstructionSize    = HAL_OSPI_INSTRUCTION_8_BITS;
  s_command.Instruction        = IS25LP032D_LAE_WRITE_ENABLE_CMD;
  s_command.AddressMode        = HAL_OSPI_ADDRESS_NONE;
  s_command.AlternateBytesMode = HAL_OSPI_ALTERNATE_BYTES_NONE;
  s_command.DataMode           = HAL_OSPI_DATA_NONE;
  s_command.DummyCycles        = 0U;
  s_command.DQSMode            = HAL_OSPI_DQS_DISABLE;
  s_command.SIOOMode           = HAL_OSPI_SIOO_INST_EVERY_CMD;

  /* Send the command */
  if (HAL_OSPI_Command(&hospi1, &s_command, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return HAL_ERROR;
  }

  /* Configure automatic polling mode to wait for write enabling */
  s_command.Instruction    = IS25LP032D_LAE_READ_STATUS_REG_CMD;
  s_command.AddressMode    = HAL_OSPI_ADDRESS_NONE;
  s_command.AddressDtrMode = HAL_OSPI_ADDRESS_DTR_DISABLE;
  s_command.AddressSize    = HAL_OSPI_ADDRESS_32_BITS;
  s_command.Address        = 0U;
  s_command.DataMode       = HAL_OSPI_DATA_1_LINE;
  s_command.DataDtrMode    = HAL_OSPI_DATA_DTR_DISABLE;
  s_command.DummyCycles    = 0U;
  s_command.NbData         = 1U;
  s_command.DQSMode        = HAL_OSPI_DQS_DISABLE;

  /* Send the command */
  if (HAL_OSPI_Command(&hospi1, &s_command, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return HAL_ERROR;
  }

  s_config.Match           = 2U;
  s_config.Mask            = 2U;
  s_config.MatchMode       = HAL_OSPI_MATCH_MODE_AND;
  s_config.Interval        = HAL_OSPI_TIMEOUT_DEFAULT_VALUE;
  s_config.AutomaticStop   = HAL_OSPI_AUTOMATIC_STOP_ENABLE;

  if (HAL_OSPI_AutoPolling(&hospi1, &s_config, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return HAL_ERROR;
  }

  return HAL_OK;
}



uint8_t OSPI_Erase_Chip(void) {
  OSPI_RegularCmdTypeDef s_command = {0};

  /* Initialize the erase command */
  s_command.OperationType      = HAL_OSPI_OPTYPE_COMMON_CFG;
  s_command.FlashId            = HAL_OSPI_FLASH_ID_1;
  s_command.InstructionMode    = HAL_OSPI_INSTRUCTION_1_LINE;
  s_command.InstructionDtrMode = HAL_OSPI_INSTRUCTION_DTR_DISABLE;
  s_command.InstructionSize    = HAL_OSPI_INSTRUCTION_8_BITS;
  s_command.Instruction        = IS25LP032D_LAE_DIE_ERASE_CMD;
  s_command.AddressMode        = HAL_OSPI_ADDRESS_NONE;
  s_command.AlternateBytesMode = HAL_OSPI_ALTERNATE_BYTES_NONE;
  s_command.DataMode           = HAL_OSPI_DATA_NONE;
  s_command.DummyCycles        = 0U;
  s_command.DQSMode            = HAL_OSPI_DQS_DISABLE;
  s_command.SIOOMode           = HAL_OSPI_SIOO_INST_EVERY_CMD;

  /* Send the command */
  if(HAL_OSPI_Command(&hospi1, &s_command, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return HAL_ERROR;
  }

	if (OSPI_AutoPollingMemReady(IS25LP032D_LAE_DIE_ERASE_MAX_TIME) != HAL_OK) {
		return HAL_ERROR;
	}

  return HAL_OK;
}

uint8_t OSPI_EraseSector(uint32_t EraseStartAddress, uint32_t EraseEndAddress) {
  OSPI_RegularCmdTypeDef s_command = {0};

  /* Initialize the erase command */
  s_command.OperationType      = HAL_OSPI_OPTYPE_COMMON_CFG;
  s_command.FlashId            = HAL_OSPI_FLASH_ID_1;
  s_command.InstructionMode    = HAL_OSPI_INSTRUCTION_1_LINE;
  s_command.InstructionDtrMode = HAL_OSPI_INSTRUCTION_DTR_DISABLE;
  s_command.InstructionSize    = HAL_OSPI_INSTRUCTION_8_BITS;
  s_command.Instruction 	    = IS25LP032D_LAE_SUBSECTOR_ERASE_CMD_4K;
  s_command.AddressMode        = HAL_OSPI_ADDRESS_1_LINE;
  s_command.AddressDtrMode     = HAL_OSPI_ADDRESS_DTR_DISABLE;
  s_command.AddressSize        = HAL_OSPI_ADDRESS_24_BITS;
  s_command.AlternateBytesMode = HAL_OSPI_ALTERNATE_BYTES_NONE;
  s_command.DataMode           = HAL_OSPI_DATA_NONE;
  s_command.DummyCycles        = 0U;
  s_command.DQSMode            = HAL_OSPI_DQS_DISABLE;
  s_command.SIOOMode           = HAL_OSPI_SIOO_INST_EVERY_CMD;


	while (EraseEndAddress >= EraseStartAddress) {
		s_command.Address = (EraseStartAddress & 0x00FFFFFF);

		if (OSPI_WriteEnable() != HAL_OK) {
			return HAL_ERROR;
		}

		if (HAL_OSPI_Command(&hospi1, &s_command, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK) {
			return HAL_ERROR;
		}
		EraseStartAddress += IS25LP032D_LAE_SUBSECTOR_SIZE;

		if (OSPI_AutoPollingMemReady(HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK) {
			return HAL_ERROR;
		}
	}

  return HAL_OK;
}


uint8_t OSPI_WriteMemory(uint8_t* buffer, uint32_t address, uint32_t buffer_size) {
  OSPI_RegularCmdTypeDef s_command = {0};
	uint32_t end_addr, current_size, current_addr;

	/* Calculation of the size between the write address and the end of the page */
	current_addr = 0;

	//
	while (current_addr <= address) {
		current_addr += IS25LP032D_LAE_PAGE_SIZE;
	}
	current_size = current_addr - address;

	/* Check if the size of the data is less than the remaining place in the page */
	if (current_size > buffer_size) {
		current_size = buffer_size;
	}

	/* Initialize the adress variables */
	current_addr = address;
	end_addr = address + buffer_size;


  /* Initialize the program command */
  s_command.OperationType      = HAL_OSPI_OPTYPE_COMMON_CFG;
  s_command.FlashId            = HAL_OSPI_FLASH_ID_1;
  s_command.InstructionMode    = HAL_OSPI_INSTRUCTION_1_LINE;
  s_command.InstructionDtrMode = HAL_OSPI_INSTRUCTION_DTR_DISABLE;
  s_command.InstructionSize    = HAL_OSPI_INSTRUCTION_8_BITS;
  s_command.Instruction        = IS25LP032D_LAE_EXT_QUAD_IN_FAST_PROG_CMD;
  s_command.AddressMode        = HAL_OSPI_ADDRESS_1_LINE;
  s_command.AddressDtrMode     = HAL_OSPI_ADDRESS_DTR_DISABLE;
  s_command.AddressSize        = HAL_OSPI_ADDRESS_24_BITS;
  s_command.AlternateBytesMode = HAL_OSPI_ALTERNATE_BYTES_NONE;
  s_command.DataMode           = HAL_OSPI_DATA_4_LINES;
  s_command.DataDtrMode        = HAL_OSPI_DATA_DTR_DISABLE;
  s_command.DummyCycles        = 0U;
  s_command.DQSMode            = HAL_OSPI_DQS_DISABLE;
  s_command.SIOOMode           = HAL_OSPI_SIOO_INST_EVERY_CMD;


	/* Perform the write page by page */
	do {
		s_command.Address = current_addr;
		s_command.NbData = current_size;

		if (current_size == 0) {
			return HAL_OK;
		}

		/* Enable write operations */
		if (OSPI_WriteEnable() != HAL_OK) {
			return HAL_ERROR;
		}

		/* Configure the command */
		if (HAL_OSPI_Command(&hospi1, &s_command, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK) {
			return HAL_ERROR;
		}

		/* Transmission of the data */
		if (HAL_OSPI_Transmit(&hospi1, buffer, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK) {
			return HAL_ERROR;
		}

		/* Configure automatic polling mode to wait for end of program */
		if (OSPI_AutoPollingMemReady(HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK) {
			return HAL_ERROR;
		}

		/* Update the address and size variables for next page programming */
		current_addr += current_size;
		buffer += current_size;
		current_size = ((current_addr + IS25LP032D_LAE_PAGE_SIZE) > end_addr) ? (end_addr - current_addr) : IS25LP032D_LAE_PAGE_SIZE;
	} while (current_addr <= end_addr);

	return HAL_OK;
}


/* USER CODE END 1 */
