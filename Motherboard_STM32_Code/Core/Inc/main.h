/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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
extern uint8_t polarity;
extern uint16_t Capture_Value1;
extern uint16_t Capture_Value2;
extern uint16_t Distance_Value;
extern uint16_t Distance_Num;
extern uint16_t Period_Num;
extern uint8_t IRIsEnabled;
extern uint8_t prescale10HzCount;
extern uint8_t dataToRasp[4];
extern uint8_t dataFromRasp;
// extern uint8_t isCalculatingDistance;

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
void IRStartDetect(GPIO_TypeDef* GPIOPort[4], uint16_t GPIOPin[4]);
void Send_Trig(void);
void py_f2s4printf(char * stra, float x, uint8_t flen);
void Delay_us(uint16_t myus);

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define WK_LED_Pin GPIO_PIN_13
#define WK_LED_GPIO_Port GPIOC
#define voltageTest_Pin GPIO_PIN_0
#define voltageTest_GPIO_Port GPIOA
#define BUZZ_Pin GPIO_PIN_3
#define BUZZ_GPIO_Port GPIOA
#define SPISelect_Pin GPIO_PIN_12
#define SPISelect_GPIO_Port GPIOB
#define IR4Output_Pin GPIO_PIN_11
#define IR4Output_GPIO_Port GPIOA
#define IR1Output_Pin GPIO_PIN_15
#define IR1Output_GPIO_Port GPIOA
#define IRSensorEnable_Pin GPIO_PIN_3
#define IRSensorEnable_GPIO_Port GPIOB
#define IR3Output_Pin GPIO_PIN_4
#define IR3Output_GPIO_Port GPIOB
#define IR2Output_Pin GPIO_PIN_5
#define IR2Output_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */
#define PO_Rising 1
#define PO_Falling 2
#define Trig_GPIO_Port GPIOB
#define Trig_Pin GPIO_PIN_0

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
