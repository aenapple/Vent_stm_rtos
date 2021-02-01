/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32l0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define VIN_CONTROL_Pin GPIO_PIN_1
#define VIN_CONTROL_GPIO_Port GPIOH
#define VIN_Pin GPIO_PIN_0
#define VIN_GPIO_Port GPIOA
#define T3_Pin GPIO_PIN_1
#define T3_GPIO_Port GPIOA
#define DBG_TX_Pin GPIO_PIN_2
#define DBG_TX_GPIO_Port GPIOA
#define DBG_RX_Pin GPIO_PIN_3
#define DBG_RX_GPIO_Port GPIOA
#define MOT_CURRENT_Pin GPIO_PIN_4
#define MOT_CURRENT_GPIO_Port GPIOA
#define T1_Pin GPIO_PIN_6
#define T1_GPIO_Port GPIOA
#define T2_Pin GPIO_PIN_7
#define T2_GPIO_Port GPIOA
#define SCS_Pin GPIO_PIN_12
#define SCS_GPIO_Port GPIOB
#define SCK_Pin GPIO_PIN_13
#define SCK_GPIO_Port GPIOB
#define SDIO_Pin GPIO_PIN_14
#define SDIO_GPIO_Port GPIOB
#define MOT_IN2_Pin GPIO_PIN_8
#define MOT_IN2_GPIO_Port GPIOA
#define PC_TX_Pin GPIO_PIN_9
#define PC_TX_GPIO_Port GPIOA
#define GPIO1_Pin GPIO_PIN_10
#define GPIO1_GPIO_Port GPIOA
#define GPIO2_Pin GPIO_PIN_11
#define GPIO2_GPIO_Port GPIOA
#define CKO_Pin GPIO_PIN_12
#define CKO_GPIO_Port GPIOA
#define PC_RX_Pin GPIO_PIN_15
#define PC_RX_GPIO_Port GPIOA
#define MOT_IN1_Pin GPIO_PIN_3
#define MOT_IN1_GPIO_Port GPIOB
#define MOT_EN_Pin GPIO_PIN_5
#define MOT_EN_GPIO_Port GPIOB
#define CTRL_Pin GPIO_PIN_6
#define CTRL_GPIO_Port GPIOB
#define LED2_Pin GPIO_PIN_8
#define LED2_GPIO_Port GPIOB
#define LED1_Pin GPIO_PIN_9
#define LED1_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
