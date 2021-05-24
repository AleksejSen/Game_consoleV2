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
#include "adc.h"
#include "dma.h"
#include "spi.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "printf.h"
#include "ST7735.h"
#include "fonts.h"
#include "GFX_FUNCTIONS.h"
#include "bitmaps.h"

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
uint32_t adc_buff_x;
uint32_t adc_buff_y;
uint32_t adc_x;
uint32_t adc_y;
uint8_t conversion_done = 0;

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
  /* USER CODE BEGIN 2 */

   ST7735_Init(0);
   fillScreen(BLACK);
   ST7735_SetRotation(1);
//   testAll();
//   HAL_Delay(1000);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */


   HAL_ADC_Start_DMA(&hadc1, &adc_buff_x, 1);
 //  HAL_ADC_Start_DMA(&hadc2, &adc_buff_y, 1);

 //  HAL_ADC_Start_IT(&hadc1);
//   HAL_ADC_Start_IT(&hadc2);

   char adc_x_str[8];
   char adc_y_str[8];
   int x = 0;
   int y = 0;

   int btn_jst = 0;
   //conversion_done = 1;
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

	  //ST7735_WriteString(60, 80, "BTN", Font_11x18, RED,BLACK);

	//  btn_jst = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4);
	  fillRect(120, 100, 20, 20, GREEN);

	  if(!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4)){

		   ST7735_WriteString(10, 10, "BJ", Font_11x18, RED,BLACK);
	  }else{
		   ST7735_WriteString(10, 10, "BJ", Font_11x18, BLACK,BLACK);
	  }

	  if(!HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_7)){

		   ST7735_WriteString(10, 20, "B1", Font_11x18, RED,BLACK);
	  }else{
		   ST7735_WriteString(10, 20, "B1", Font_11x18, BLACK,BLACK);
	  }

	  if(!HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_11)){

		   ST7735_WriteString(10, 30, "B2", Font_11x18, RED,BLACK);
	  }else{
		   ST7735_WriteString(10, 30, "B2", Font_11x18, BLACK,BLACK);
	  }


	  itoa(adc_x, adc_x_str, 10);

	  ST7735_WriteString(60, 60, adc_x_str, Font_11x18, BLACK,BLACK);
	  ST7735_WriteString(60, 60, adc_x_str, Font_11x18, RED,BLACK);
//
//	  if (conversion_done) {
//		conversion_done = 0;
//
//		  itoa(adc_x, adc_x_str, 10);
////		  itoa(adc_y, adc_y_str, 10);
//
//		  drawLine(0, 0, 0, 100, GREEN);
//
//		  ST7735_WriteString(60, 60, adc_x_str, Font_11x18, BLACK,BLACK);
//		  ST7735_WriteString(60, 60, adc_x_str, Font_11x18, RED,BLACK);
//
////		  ST7735_WriteString(60, 80, adc_y_str, Font_11x18, BLACK,BLACK);
////		  ST7735_WriteString(60, 80, adc_y_str, Font_11x18, RED,BLACK);
//	}
//
//	  drawLine(0, 0, 0, 100, GREEN);
//	  ST7735_WriteString(60, 80, adc_y_str, Font_11x18, BLACK,BLACK);
//	  ST7735_WriteString(60, 80, adc_y_str, Font_11x18, RED,BLACK);

//	  fillRect(5, 5, 50, 50, GREEN);
//	  HAL_Delay(1000);
//	  fillRect(5, 5, 50, 50, RED);
//	  HAL_Delay(1000);
//	  fillRect(5, 5, 50, 50, BLUE);
//	  HAL_Delay(1000);
//	  fillRect(5, 5, 50, 50, YELLOW);
//	  HAL_Delay(1000);

	 // drawRGBBitmap(0,0, myBitmapBitmap, 70, 61);
	  //ST7735_SetRotation(1);
//	  ST7735_WriteString(1, 1, "HELLO", Font_11x18, BLACK,BLACK);
//	  ST7735_WriteString(1, 1, "HELLO", Font_11x18, RED,BLACK);



	   //fillScreen(BLACK);
	   //HAL_Delay(5);


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

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
  adc_x = adc_buff_x;
  HAL_ADC_Start_DMA(&hadc1, &adc_buff_x, 1);
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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
