/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"
#include "adc.h"
#include "dma.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "printf.h"
#include <cstdio>
//#include "ST7735.h"
//#include "fonts.h"
//#include "GFX_FUNCTIONS.h"
//#include "bitmaps.h"

#include "DebugTask.h"
#include "JoystickButtonTask.h"
#include "DisplayTask.h"

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

/*Adc Stuff(Global to be used from ISR)*/
uint32_t adc_buff[2];
uint32_t adc_buff_y;
uint32_t adc_x;
uint32_t adc_y;
uint8_t conversion_done = 0;


/*ADC queue*/
extern osMessageQueueId_t AdcQueueHandle;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void MX_FREERTOS_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */


/*Message Queue*/

#define MSGQUEUE_OBJECTS 16                     // number of Message Queue Objects

/*Queue example*/
typedef struct                                  // object data type
{
    uint8_t Buf[32];
    uint8_t Idx;
} MSGQUEUE_OBJ_t;

MSGQUEUE_OBJ_t queue_msg;
osMessageQueueId_t msgQueue;
/*End Queue example*/

/*ADC Qeue*/
uint32_t adc_queue_msg[2];
osMessageQueueId_t adcQueue;



/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

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
  MX_DMA_Init();
  MX_USART2_UART_Init();
  MX_SPI3_Init();
  MX_ADC1_Init();
  MX_TIM1_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */

//	ST7735_Init(0);
//	fillScreen(BLACK);
//	ST7735_SetRotation(1);
//   testAll();
//   HAL_Delay(1000);

	HAL_ADC_Start_DMA(&hadc1, adc_buff, 2);

//	char adc_x_str[8];
//	char adc_y_str[8];
//	int x = 50;
//	int y = 50;
//
//	int color = PURPLE;
//
//	int btn_jst = 0;

  /* USER CODE END 2 */

  /* Init scheduler */
  osKernelInitialize();  /* Call init function for freertos objects (in freertos.c) */
  //MX_FREERTOS_Init();

  /*Create Queue example*/
 // msgQueue = osMessageQueueNew(MSGQUEUE_OBJECTS, sizeof(MSGQUEUE_OBJ_t), NULL);
  adcQueue = osMessageQueueNew(MSGQUEUE_OBJECTS, sizeof(adc_queue_msg), NULL);


  /*Createing task*/
  DebugTask debug_task = DebugTask("debug_tsk", 128 * 4, (osPriority_t) osPriorityNormal);
  JoystickButtonTask joystick_task = JoystickButtonTask("joystick_tsk", 128 * 4, (osPriority_t) osPriorityNormal);
  DisplayTask display_tasl = DisplayTask("display_tsk", 128 * 4, (osPriority_t) osPriorityNormal);


  /* Start scheduler */
  osKernelStart();

  /* We should never get here as control is now taken by the scheduler */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */


	//  HAL_ADC_Start_DMA(&hadc2, &adc_buff_y, 1);

	//  HAL_ADC_Start_IT(&hadc1);
//   HAL_ADC_Start_IT(&hadc2);


	//conversion_done = 1;

	//HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);

	//ST7735_DrawImage(50, 50, 10, 8, (uint16_t*)test_img_128x128);

	//ST7735_DrawPixel(50, 50, RED);

	while (1) {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

		//fillRect(x, y, 20, 20, color);
//		printf("Test\r\n");
//
//		ST7735_WriteString(30, 30, "Game Console V2", Font_7x10, RED, BLACK);
//		ST7735_WriteString(50, 50, "STM32F4", Font_7x10, RED, BLACK);
//		ST7735_WriteString(10, 70, "by Aleksejs Sencenko", Font_7x10, RED, BLACK);
//
//		if (!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4)) {
//			ST7735_WriteString(120, 5, "J", Font_7x10, RED, BLACK);
//		} else {
//			ST7735_WriteString(120, 5, " ", Font_7x10, RED, BLACK);
//		}
//
//		if (!HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_7)) {
//			ST7735_WriteString(128, 5, "1", Font_7x10, RED, BLACK);
//
////			TIM1->DCR = 30000;
////			HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
//
//			color += 1;
//		} else {
//			ST7735_WriteString(128, 5, "  ", Font_7x10, RED, BLACK);
//			HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
//		}
//
//		if (!HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_11)) {
//
//			ST7735_WriteString(132, 5, "2", Font_7x10, RED, BLACK);
//
////			TIM1->DCR =  28000;
////			HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
//
//			color -= 1;
//		} else {
//			ST7735_WriteString(132, 5, " ", Font_7x10, RED, BLACK);
//			HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
//		}
//
////		itoa(adc_x, adc_x_str, 10);
////		itoa(adc_y, adc_y_str, 10);
//
////ST7735_WriteString(80, 5, adc_x_str, Font_7x10, BLACK,BLACK);
//		if (adc_x < 1700) {
//			ST7735_WriteString(150, 5, "<", Font_7x10, RED, BLACK);
//			if (x < 0) {
//				x = 0;
//			} else {
//				--x;
//			}
//
//		} else if (adc_x > 2300) {
//			ST7735_WriteString(150, 5, ">", Font_7x10, RED, BLACK);
//			if (x > 140) {
//				x = 140;
//			} else {
//				++x;
//			}
//
//		} else {
//			ST7735_WriteString(150, 5, " ", Font_7x10, RED, BLACK);
//		}
//
//		if (adc_y < 1700) {
//			ST7735_WriteString(142, 5, "^", Font_7x10, RED, BLACK);
//			if (y < 0) {
//				y = 0;
//			} else {
//				--y;
//			}
//
//		} else if (adc_y > 2300) {
//			ST7735_WriteString(142, 5, "v", Font_7x10, RED, BLACK);
//			if (y > 100) {
//				y = 100;
//			} else {
//				++y;
//			}
//		} else {
//			ST7735_WriteString(142, 5, " ", Font_7x10, RED, BLACK);
//		}
//
//		HAL_Delay(10);

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

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
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
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc) {

	//printf("adc \r\n");


	adc_queue_msg[0] =  adc_buff[0];
    adc_queue_msg[1] =	adc_buff[1];


	osMessageQueuePut(adcQueue, &adc_queue_msg, 0U, 0U);
	HAL_ADC_Start_DMA(&hadc1, adc_buff, 2);


//	adc_x = adc_buff[1];
//	adc_y = adc_buff[0];

//	HAL_ADC_Start_DMA(&hadc1, adc_buff, 2);
}

//void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc) {
//	conversion_done = 1;
//
//	adc_x = HAL_ADC_GetValue(&hadc1);
//				HAL_ADC_Start_IT(&hadc1);

//		if(hadc->Instance = ADC1){
//			adc_x = HAL_ADC_GetValue(&hadc1);
//			HAL_ADC_Start_IT(&hadc1);
//
//		}

//		if(hadc->Instance = ADC2){
//			adc_y = HAL_ADC_GetValue(&hadc2);
//			HAL_ADC_Start_IT(&hadc2);
//
//		}

//	adc_x = adc_buff_x;
//	HAL_ADC_Start_DMA(&hadc1, &adc_buff_x, 1);
//
//	if(hadc->Instance = ADC1){
//		adc_x = adc_buff_x;
//		 HAL_ADC_Start_DMA(&hadc1, &adc_buff_x, 1);
//	}
//
//	if(hadc->Instance = ADC2){
//		adc_y = adc_buff_y;
//		 HAL_ADC_Start_DMA(&hadc2, &adc_buff_y, 1);
//	}
//}

//void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
//{
//	conversion_done = 1;
//	if(hadc->Instance = ADC1){
//		adc_x = adc_buff_x;
//		 HAL_ADC_Start_DMA(&hadc1, &adc_buff_x, 1);
//	}
//
//	if(hadc->Instance = ADC2){
//		adc_y = adc_buff_y;
//		 HAL_ADC_Start_DMA(&hadc2, &adc_buff_y, 1);
//	}
//}

/* USER CODE END 4 */

 /**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM14 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM14) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1) {
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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
