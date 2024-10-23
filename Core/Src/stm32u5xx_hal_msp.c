
/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file         stm32u5xx_hal_msp.c
  * @brief        This file provides code for the MSP Initialization
  *               and de-Initialization codes.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "main.h"
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN Define */

/* USER CODE END Define */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN Macro */

/* USER CODE END Macro */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* External functions --------------------------------------------------------*/
/* USER CODE BEGIN ExternalFunctions */

/* USER CODE END ExternalFunctions */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */
/**
  * Initializes the Global MSP.
  */
void HAL_MspInit(void)
{

  /* USER CODE BEGIN MspInit 0 */

  /* USER CODE END MspInit 0 */

  __HAL_RCC_PWR_CLK_ENABLE();

  /* System interrupt init*/

  /* USER CODE BEGIN MspInit 1 */

  /* USER CODE END MspInit 1 */
}

/**
* @brief DCACHE MSP Initialization
* This function configures the hardware resources used in this example
* @param hdcache: DCACHE handle pointer
* @retval None
*/
void HAL_DCACHE_MspInit(DCACHE_HandleTypeDef* hdcache)
{
  if(hdcache->Instance==DCACHE1)
  {
  /* USER CODE BEGIN DCACHE1_MspInit 0 */

  /* USER CODE END DCACHE1_MspInit 0 */
    /* Peripheral clock enable */
    __HAL_RCC_DCACHE1_CLK_ENABLE();
  /* USER CODE BEGIN DCACHE1_MspInit 1 */

  /* USER CODE END DCACHE1_MspInit 1 */
  }
  else if(hdcache->Instance==DCACHE2)
  {
  /* USER CODE BEGIN DCACHE2_MspInit 0 */

  /* USER CODE END DCACHE2_MspInit 0 */
    /* Peripheral clock enable */
    __HAL_RCC_DCACHE2_CLK_ENABLE();
  /* USER CODE BEGIN DCACHE2_MspInit 1 */

  /* USER CODE END DCACHE2_MspInit 1 */
  }

}

/**
* @brief DCACHE MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param hdcache: DCACHE handle pointer
* @retval None
*/
void HAL_DCACHE_MspDeInit(DCACHE_HandleTypeDef* hdcache)
{
  if(hdcache->Instance==DCACHE1)
  {
  /* USER CODE BEGIN DCACHE1_MspDeInit 0 */

  /* USER CODE END DCACHE1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_DCACHE1_CLK_DISABLE();
  /* USER CODE BEGIN DCACHE1_MspDeInit 1 */

  /* USER CODE END DCACHE1_MspDeInit 1 */
  }
  else if(hdcache->Instance==DCACHE2)
  {
  /* USER CODE BEGIN DCACHE2_MspDeInit 0 */

  /* USER CODE END DCACHE2_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_DCACHE2_CLK_DISABLE();
  /* USER CODE BEGIN DCACHE2_MspDeInit 1 */

  /* USER CODE END DCACHE2_MspDeInit 1 */
  }

}

/**
* @brief XSPI MSP Initialization
* This function configures the hardware resources used in this example
* @param hxspi: XSPI handle pointer
* @retval None
*/
void HAL_XSPI_MspInit(XSPI_HandleTypeDef* hxspi)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};
  if(hxspi->Instance==HSPI1)
  {
  /* USER CODE BEGIN HSPI1_MspInit 0 */

  /* USER CODE END HSPI1_MspInit 0 */

  /** Initializes the peripherals clock
  */
    PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_HSPI;
    PeriphClkInit.HspiClockSelection = RCC_HSPICLKSOURCE_PLL2;
    PeriphClkInit.PLL2.PLL2Source = RCC_PLLSOURCE_HSE;
    PeriphClkInit.PLL2.PLL2M = 4;
    PeriphClkInit.PLL2.PLL2N = 66;
    PeriphClkInit.PLL2.PLL2P = 2;
    PeriphClkInit.PLL2.PLL2Q = 2;
    PeriphClkInit.PLL2.PLL2R = 2;
    PeriphClkInit.PLL2.PLL2RGE = RCC_PLLVCIRANGE_0;
    PeriphClkInit.PLL2.PLL2FRACN = 0;
    PeriphClkInit.PLL2.PLL2ClockOut = RCC_PLL2_DIVQ;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
    {
      Error_Handler();
    }

    /* Peripheral clock enable */
    __HAL_RCC_HSPI1_CLK_ENABLE();

    __HAL_RCC_GPIOH_CLK_ENABLE();
    __HAL_RCC_GPIOI_CLK_ENABLE();
    /**HSPI1 GPIO Configuration
    PH9     ------> HSPI1_NCS
    PH10     ------> HSPI1_IO0
    PH11     ------> HSPI1_IO1
    PH12     ------> HSPI1_IO2
    PH13     ------> HSPI1_IO3
    PH14     ------> HSPI1_IO4
    PH15     ------> HSPI1_IO5
    PI0     ------> HSPI1_IO6
    PI1     ------> HSPI1_IO7
    PI2     ------> HSPI1_DQS0
    PI3     ------> HSPI1_CLK
    */
    GPIO_InitStruct.Pin = GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12
                          |GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF8_HSPI1;
    HAL_GPIO_Init(GPIOH, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF8_HSPI1;
    HAL_GPIO_Init(GPIOI, &GPIO_InitStruct);

  /* USER CODE BEGIN HSPI1_MspInit 1 */

  /* USER CODE END HSPI1_MspInit 1 */

  }

}

/**
* @brief XSPI MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param hxspi: XSPI handle pointer
* @retval None
*/
void HAL_XSPI_MspDeInit(XSPI_HandleTypeDef* hxspi)
{
  if(hxspi->Instance==HSPI1)
  {
  /* USER CODE BEGIN HSPI1_MspDeInit 0 */

  /* USER CODE END HSPI1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_HSPI1_CLK_DISABLE();

    /**HSPI1 GPIO Configuration
    PH9     ------> HSPI1_NCS
    PH10     ------> HSPI1_IO0
    PH11     ------> HSPI1_IO1
    PH12     ------> HSPI1_IO2
    PH13     ------> HSPI1_IO3
    PH14     ------> HSPI1_IO4
    PH15     ------> HSPI1_IO5
    PI0     ------> HSPI1_IO6
    PI1     ------> HSPI1_IO7
    PI2     ------> HSPI1_DQS0
    PI3     ------> HSPI1_CLK
    */
    HAL_GPIO_DeInit(GPIOH, GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12
                          |GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15);

    HAL_GPIO_DeInit(GPIOI, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);

  /* USER CODE BEGIN HSPI1_MspDeInit 1 */

  /* USER CODE END HSPI1_MspDeInit 1 */
  }

}

/**
* @brief I2C MSP Initialization
* This function configures the hardware resources used in this example
* @param hi2c: I2C handle pointer
* @retval None
*/
void HAL_I2C_MspInit(I2C_HandleTypeDef* hi2c)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};
  if(hi2c->Instance==I2C2)
  {
  /* USER CODE BEGIN I2C2_MspInit 0 */

  /* USER CODE END I2C2_MspInit 0 */

  /** Initializes the peripherals clock
  */
    PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_I2C2;
    PeriphClkInit.I2c2ClockSelection = RCC_I2C2CLKSOURCE_PCLK1;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
    {
      Error_Handler();
    }

    __HAL_RCC_GPIOF_CLK_ENABLE();
    /**I2C2 GPIO Configuration
    PF0     ------> I2C2_SDA
    PF1     ------> I2C2_SCL
    */
    GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF4_I2C2;
    HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

    /* Peripheral clock enable */
    __HAL_RCC_I2C2_CLK_ENABLE();
    /* I2C2 interrupt Init */
    HAL_NVIC_SetPriority(I2C2_EV_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(I2C2_EV_IRQn);
    HAL_NVIC_SetPriority(I2C2_ER_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(I2C2_ER_IRQn);
  /* USER CODE BEGIN I2C2_MspInit 1 */

  /* USER CODE END I2C2_MspInit 1 */

  }

}

/**
* @brief I2C MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param hi2c: I2C handle pointer
* @retval None
*/
void HAL_I2C_MspDeInit(I2C_HandleTypeDef* hi2c)
{
  if(hi2c->Instance==I2C2)
  {
  /* USER CODE BEGIN I2C2_MspDeInit 0 */

  /* USER CODE END I2C2_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_I2C2_CLK_DISABLE();

    /**I2C2 GPIO Configuration
    PF0     ------> I2C2_SDA
    PF1     ------> I2C2_SCL
    */
    HAL_GPIO_DeInit(GPIOF, GPIO_PIN_0);

    HAL_GPIO_DeInit(GPIOF, GPIO_PIN_1);

    /* I2C2 interrupt DeInit */
    HAL_NVIC_DisableIRQ(I2C2_EV_IRQn);
    HAL_NVIC_DisableIRQ(I2C2_ER_IRQn);
  /* USER CODE BEGIN I2C2_MspDeInit 1 */

  /* USER CODE END I2C2_MspDeInit 1 */
  }

}

/**
* @brief LTDC MSP Initialization
* This function configures the hardware resources used in this example
* @param hltdc: LTDC handle pointer
* @retval None
*/
void HAL_LTDC_MspInit(LTDC_HandleTypeDef* hltdc)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};
  if(hltdc->Instance==LTDC)
  {
  /* USER CODE BEGIN LTDC_MspInit 0 */

  /* USER CODE END LTDC_MspInit 0 */

  /** Initializes the peripherals clock
  */
    PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_LTDC;
    PeriphClkInit.LtdcClockSelection = RCC_LTDCCLKSOURCE_PLL3;
    PeriphClkInit.PLL3.PLL3Source = RCC_PLLSOURCE_HSE;
    PeriphClkInit.PLL3.PLL3M = 4;
    PeriphClkInit.PLL3.PLL3N = 50;
    PeriphClkInit.PLL3.PLL3P = 2;
    PeriphClkInit.PLL3.PLL3Q = 2;
    PeriphClkInit.PLL3.PLL3R = 8;
    PeriphClkInit.PLL3.PLL3RGE = RCC_PLLVCIRANGE_0;
    PeriphClkInit.PLL3.PLL3FRACN = 0;
    PeriphClkInit.PLL3.PLL3ClockOut = RCC_PLL3_DIVR;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
    {
      Error_Handler();
    }

    /* Peripheral clock enable */
    __HAL_RCC_LTDC_CLK_ENABLE();

    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOE_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    /**LTDC GPIO Configuration
    PB2     ------> LTDC_B1
    PE7     ------> LTDC_B6
    PE8     ------> LTDC_B7
    PE9     ------> LTDC_G2
    PE10     ------> LTDC_G3
    PE11     ------> LTDC_G4
    PE12     ------> LTDC_G5
    PE13     ------> LTDC_G6
    PE14     ------> LTDC_G7
    PE15     ------> LTDC_R2
    PD8     ------> LTDC_R3
    PD9     ------> LTDC_R4
    PD10     ------> LTDC_R5
    PD11     ------> LTDC_R6
    PD12     ------> LTDC_R7
    PD13     ------> LTDC_VSYNC
    PD14     ------> LTDC_B2
    PD15     ------> LTDC_B3
    PC6     ------> LTDC_R0
    PC7     ------> LTDC_R1
    PC8     ------> LTDC_G0
    PC9     ------> LTDC_G1
    PD0     ------> LTDC_B4
    PD1     ------> LTDC_B5
    PD3     ------> LTDC_CLK
    PD6     ------> LTDC_DE
    PB9     ------> LTDC_B0
    PE0     ------> LTDC_HSYNC
    */
    GPIO_InitStruct.Pin = GPIO_PIN_2;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF8_LTDC;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10
                          |GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14
                          |GPIO_PIN_15|GPIO_PIN_0;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF8_LTDC;
    HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11
                          |GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15
                          |GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_3|GPIO_PIN_6;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF8_LTDC;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF7_LTDC;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_9;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF8_LTDC;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_9;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF7_LTDC;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* LTDC interrupt Init */
    HAL_NVIC_SetPriority(LTDC_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(LTDC_IRQn);
  /* USER CODE BEGIN LTDC_MspInit 1 */

  /* USER CODE END LTDC_MspInit 1 */

  }

}

/**
* @brief LTDC MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param hltdc: LTDC handle pointer
* @retval None
*/
void HAL_LTDC_MspDeInit(LTDC_HandleTypeDef* hltdc)
{
  if(hltdc->Instance==LTDC)
  {
  /* USER CODE BEGIN LTDC_MspDeInit 0 */

  /* USER CODE END LTDC_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_LTDC_CLK_DISABLE();

    /**LTDC GPIO Configuration
    PB2     ------> LTDC_B1
    PE7     ------> LTDC_B6
    PE8     ------> LTDC_B7
    PE9     ------> LTDC_G2
    PE10     ------> LTDC_G3
    PE11     ------> LTDC_G4
    PE12     ------> LTDC_G5
    PE13     ------> LTDC_G6
    PE14     ------> LTDC_G7
    PE15     ------> LTDC_R2
    PD8     ------> LTDC_R3
    PD9     ------> LTDC_R4
    PD10     ------> LTDC_R5
    PD11     ------> LTDC_R6
    PD12     ------> LTDC_R7
    PD13     ------> LTDC_VSYNC
    PD14     ------> LTDC_B2
    PD15     ------> LTDC_B3
    PC6     ------> LTDC_R0
    PC7     ------> LTDC_R1
    PC8     ------> LTDC_G0
    PC9     ------> LTDC_G1
    PD0     ------> LTDC_B4
    PD1     ------> LTDC_B5
    PD3     ------> LTDC_CLK
    PD6     ------> LTDC_DE
    PB9     ------> LTDC_B0
    PE0     ------> LTDC_HSYNC
    */
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_2|GPIO_PIN_9);

    HAL_GPIO_DeInit(GPIOE, GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10
                          |GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14
                          |GPIO_PIN_15|GPIO_PIN_0);

    HAL_GPIO_DeInit(GPIOD, GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11
                          |GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15
                          |GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_3|GPIO_PIN_6);

    HAL_GPIO_DeInit(GPIOC, GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9);

    /* LTDC interrupt DeInit */
    HAL_NVIC_DisableIRQ(LTDC_IRQn);
  /* USER CODE BEGIN LTDC_MspDeInit 1 */

  /* USER CODE END LTDC_MspDeInit 1 */
  }

}

/**
* @brief RTC MSP Initialization
* This function configures the hardware resources used in this example
* @param hrtc: RTC handle pointer
* @retval None
*/
void HAL_RTC_MspInit(RTC_HandleTypeDef* hrtc)
{
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};
  if(hrtc->Instance==RTC)
  {
  /* USER CODE BEGIN RTC_MspInit 0 */

  /* USER CODE END RTC_MspInit 0 */

  /** Initializes the peripherals clock
  */
    PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_RTC;
    PeriphClkInit.RTCClockSelection = RCC_RTCCLKSOURCE_LSE;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
    {
      Error_Handler();
    }

    /* Peripheral clock enable */
    __HAL_RCC_RTC_ENABLE();
    __HAL_RCC_RTCAPB_CLK_ENABLE();
    __HAL_RCC_RTCAPB_CLKAM_ENABLE();
  /* USER CODE BEGIN RTC_MspInit 1 */

  /* USER CODE END RTC_MspInit 1 */

  }

}

/**
* @brief RTC MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param hrtc: RTC handle pointer
* @retval None
*/
void HAL_RTC_MspDeInit(RTC_HandleTypeDef* hrtc)
{
  if(hrtc->Instance==RTC)
  {
  /* USER CODE BEGIN RTC_MspDeInit 0 */

  /* USER CODE END RTC_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_RTC_DISABLE();
    __HAL_RCC_RTCAPB_CLK_DISABLE();
    __HAL_RCC_RTCAPB_CLKAM_DISABLE();
  /* USER CODE BEGIN RTC_MspDeInit 1 */

  /* USER CODE END RTC_MspDeInit 1 */
  }

}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
