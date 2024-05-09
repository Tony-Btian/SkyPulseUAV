/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
uint8_t polarity = PO_Rising;
uint16_t Capture_Value1 = 0;
uint16_t Capture_Value2 = 0;
uint16_t Distance_Value = 0;
uint16_t Distance_Num = 0;
uint16_t Period_Num = 0;
uint8_t IRIsEnabled = 0;
uint8_t prescale10HzCount = 0;

// Here's the data transmitted to master, and:
// [0] - random, to be dispatched.
// [1] - represents the status of IR sensors(1/0).
// [2], [3]
// 	   - represent the distance between ultrasonic
// sensor and the obstacle(mm).
uint8_t dataToRasp[4] = {0};
//uint8_t dataFromRasp = 0;
uint8_t IRObjectDetected = 0;
// uint8_t isCalculatingDistance = 0;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */
	GPIO_TypeDef* IRGPIOPorts[4] = {
			IR1Output_GPIO_Port,
			IR2Output_GPIO_Port,
			IR3Output_GPIO_Port,
			IR4Output_GPIO_Port,
	};

	uint16_t IRGPIOPins[4] = {
			IR1Output_Pin,
			IR2Output_Pin,
			IR3Output_Pin,
			IR4Output_Pin
	};

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  MX_SPI2_Init();
  MX_TIM3_Init();
  MX_TIM4_Init();
  /* USER CODE BEGIN 2 */
  HAL_SPI_Transmit_DMA(&hspi2, dataToRasp, 4);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  IRStartDetect(IRGPIOPorts, IRGPIOPins);
	  dataToRasp[1] = IRObjectDetected;
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
// Function for IR sensors detection.
void IRStartDetect(GPIO_TypeDef* GPIOPort[4], uint16_t GPIOPin[4])
{
	if(IRIsEnabled)
	{
		IRIsEnabled = 0;
		// Eliminate jitter.
		Delay_us(210);

		for(int i = 0; i < 4; i++)
		{
			if(HAL_GPIO_ReadPin(GPIOPort[i], GPIOPin[i]))
			{
				IRObjectDetected &= ~(1 << i);
			}
			else
			{
				// Eliminate jitter twice.
				Delay_us(400);
				if(HAL_GPIO_ReadPin(GPIOPort[i], GPIOPin[i]))
				{
					IRObjectDetected &= ~(1 << i);
				}
				else
				{
					IRObjectDetected |= (1 << i);
				}
			}
		}
		// Reset enable pin.
		HAL_GPIO_WritePin(IRSensorEnable_GPIO_Port, IRSensorEnable_Pin, RESET);
	}
}

// us level timer.
void Delay_us(uint16_t myus)
{
	uint16_t differ = 0xffff-myus-5;
	HAL_TIM_Base_Start(&htim3);
	__HAL_TIM_SetCounter(&htim3,differ);
	while(differ < 0xffff-5)
	{
		differ = __HAL_TIM_GetCounter(&htim3);
	}
	HAL_TIM_Base_Stop(&htim3);
}

// Trigger ultrasonic sensor.
void Send_Trig(void)
{
	HAL_GPIO_WritePin(Trig_GPIO_Port, Trig_Pin, SET);
	Delay_us(20);
	HAL_GPIO_WritePin(Trig_GPIO_Port, Trig_Pin, RESET);
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
