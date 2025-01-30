/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
extern SPI_HandleTypeDef hspi1;

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define SENSOR_2_Pin GPIO_PIN_0
#define SENSOR_2_GPIO_Port GPIOF
#define SENSOR_1_Pin GPIO_PIN_1
#define SENSOR_1_GPIO_Port GPIOF
#define DIAG0_Pin GPIO_PIN_0
#define DIAG0_GPIO_Port GPIOA
#define DIAG1_Pin GPIO_PIN_1
#define DIAG1_GPIO_Port GPIOA
#define N_EN_Pin GPIO_PIN_2
#define N_EN_GPIO_Port GPIOA
#define STEP_Pin GPIO_PIN_3
#define STEP_GPIO_Port GPIOA
#define DIR_Pin GPIO_PIN_4
#define DIR_GPIO_Port GPIOA
#define SCK_Pin GPIO_PIN_5
#define SCK_GPIO_Port GPIOA
#define MISO_Pin GPIO_PIN_6
#define MISO_GPIO_Port GPIOA
#define MOSI_Pin GPIO_PIN_7
#define MOSI_GPIO_Port GPIOA
#define N_CS_Pin GPIO_PIN_0
#define N_CS_GPIO_Port GPIOB
#define SDA_Pin GPIO_PIN_8
#define SDA_GPIO_Port GPIOA
#define SCL_Pin GPIO_PIN_9
#define SCL_GPIO_Port GPIOA
#define AU_Pin GPIO_PIN_10
#define AU_GPIO_Port GPIOA
#define CAN_RX_Pin GPIO_PIN_11
#define CAN_RX_GPIO_Port GPIOA
#define CAN_TX_Pin GPIO_PIN_12
#define CAN_TX_GPIO_Port GPIOA
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define VCP_RX_Pin GPIO_PIN_15
#define VCP_RX_GPIO_Port GPIOA
#define VCP_TX_Pin GPIO_PIN_3
#define VCP_TX_GPIO_Port GPIOB
#define ENC2_A_Pin GPIO_PIN_4
#define ENC2_A_GPIO_Port GPIOB
#define ENC2_B_Pin GPIO_PIN_5
#define ENC2_B_GPIO_Port GPIOB
#define ENC1_A_Pin GPIO_PIN_6
#define ENC1_A_GPIO_Port GPIOB
#define ENC1_B_Pin GPIO_PIN_7
#define ENC1_B_GPIO_Port GPIOB
#define STATUS_Pin GPIO_PIN_8
#define STATUS_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
