/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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
#include "stm32f1xx_hal.h"

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
#define BCD_C3_Pin GPIO_PIN_13
#define BCD_C3_GPIO_Port GPIOC
#define BCD_C2_Pin GPIO_PIN_14
#define BCD_C2_GPIO_Port GPIOC
#define BCD_C1_Pin GPIO_PIN_15
#define BCD_C1_GPIO_Port GPIOC
#define BCD_C0_Pin GPIO_PIN_0
#define BCD_C0_GPIO_Port GPIOA
#define BCD_B3_Pin GPIO_PIN_1
#define BCD_B3_GPIO_Port GPIOA
#define BCD_B2_Pin GPIO_PIN_2
#define BCD_B2_GPIO_Port GPIOA
#define BCD_B1_Pin GPIO_PIN_3
#define BCD_B1_GPIO_Port GPIOA
#define BCD_B0_Pin GPIO_PIN_4
#define BCD_B0_GPIO_Port GPIOA
#define BCD_A3_Pin GPIO_PIN_5
#define BCD_A3_GPIO_Port GPIOA
#define BCD_A2_Pin GPIO_PIN_6
#define BCD_A2_GPIO_Port GPIOA
#define BCD_A1_Pin GPIO_PIN_7
#define BCD_A1_GPIO_Port GPIOA
#define BCD_A0_Pin GPIO_PIN_0
#define BCD_A0_GPIO_Port GPIOB
#define BCD_E3_Pin GPIO_PIN_1
#define BCD_E3_GPIO_Port GPIOB
#define START_RELAY_Pin GPIO_PIN_11
#define START_RELAY_GPIO_Port GPIOB
#define BCD_D0_Pin GPIO_PIN_12
#define BCD_D0_GPIO_Port GPIOB
#define BCD_D1_Pin GPIO_PIN_13
#define BCD_D1_GPIO_Port GPIOB
#define BCD_D2_Pin GPIO_PIN_14
#define BCD_D2_GPIO_Port GPIOB
#define BCD_D3_Pin GPIO_PIN_15
#define BCD_D3_GPIO_Port GPIOB
#define BCD_E0_Pin GPIO_PIN_8
#define BCD_E0_GPIO_Port GPIOA
#define BCD_E1_Pin GPIO_PIN_9
#define BCD_E1_GPIO_Port GPIOA
#define BCD_E2_Pin GPIO_PIN_10
#define BCD_E2_GPIO_Port GPIOA
#define BCD_F0_Pin GPIO_PIN_15
#define BCD_F0_GPIO_Port GPIOA
#define BCD_F1_Pin GPIO_PIN_3
#define BCD_F1_GPIO_Port GPIOB
#define BCD_F2_Pin GPIO_PIN_4
#define BCD_F2_GPIO_Port GPIOB
#define BCD_F3_Pin GPIO_PIN_5
#define BCD_F3_GPIO_Port GPIOB
#define BCD_G0_Pin GPIO_PIN_6
#define BCD_G0_GPIO_Port GPIOB
#define BCD_G1_Pin GPIO_PIN_7
#define BCD_G1_GPIO_Port GPIOB
#define BCD_G2_Pin GPIO_PIN_8
#define BCD_G2_GPIO_Port GPIOB
#define BCD_G3_Pin GPIO_PIN_9
#define BCD_G3_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
