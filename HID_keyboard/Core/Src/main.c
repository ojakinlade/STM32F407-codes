/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
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
#include "usb_device.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "usbd_hid.h"
#include "Button.h"
#include "Timer.h"
#include "Usb.h"
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

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
#define NUM_OF_BUTTONS 9
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
  MX_USB_DEVICE_Init();
  /* USER CODE BEGIN 2 */
  __disable_irq();
  Button_Init();
  TIMER2_Init();
  TIMER3_Init();
  NVIC_EnableIRQ(TIM2_IRQn);
  NVIC_EnableIRQ(TIM3_IRQn);

  Button_t button[] = {{0,0,8},{0,0,0},{0,0,1},{0,0,2},{0,0,3},{0,0,4},{0,0,5},{0,0,6},{0,0,7}};
  const uint8_t BUTTON[NUM_OF_BUTTONS] = {CAPS_LCK,BUTTON1,BUTTON2,BUTTON3,BUTTON4,BUTTON5,BUTTON6,SPACE,BACKSPACE};
  uint16_t buttonRegister = 0;
  uint8_t caps_LckPressed = 0;
  uint8_t slide_Switch = 0;
  __enable_irq();

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
	  slide_Switch = GPIOC->IDR & SLIDE_SW;

	  for(int i = 0; i < NUM_OF_BUTTONS; i++){
		  if(i<4)
			  button[i].pressed = (!(GPIOB->IDR & BUTTON[i]));
		  else
			  button[i].pressed = (!(GPIOC->IDR & BUTTON[i]));

		  Button_Poll(&button[i],&buttonRegister);
	  }
	  if(Button_pressTimeElapsed){
		  switch(buttonRegister){
		  case BUTTON_1_PRESSED:
			  if(slide_Switch){
				  Usb_SendKeyPress(0x00,USB_USAGE_ID_1);
				  Usb_ReleaseKeys();
			  }
			  else{
				  if(caps_LckPressed){
					  Usb_SendKeyPress(LEFT_SHIFT,USB_USAGE_ID_A);
					  Usb_ReleaseKeys();
				  }
				  else{
					  Usb_SendKeyPress(0x00,USB_USAGE_ID_A);
					  Usb_ReleaseKeys();
				  }
			  }
			  break;

		  case BUTTON_1_2_PRESSED:
			  if(slide_Switch){
				  Usb_SendKeyPress(0x00,USB_USAGE_ID_2);
				  Usb_ReleaseKeys();
			  }
			  else{
				  if(caps_LckPressed){
					  Usb_SendKeyPress(LEFT_SHIFT,USB_USAGE_ID_B);
					  Usb_ReleaseKeys();
				  }
				  else{
					  Usb_SendKeyPress(0x00,USB_USAGE_ID_B);
					  Usb_ReleaseKeys();
				  }
			  }
			  break;

		  case BUTTON_1_4_PRESSED:
			  if(slide_Switch){
				  Usb_SendKeyPress(0x00,USB_USAGE_ID_3);
				  Usb_ReleaseKeys();
			  }
			  else{
				  if(caps_LckPressed){
					  Usb_SendKeyPress(LEFT_SHIFT,USB_USAGE_ID_C);
					  Usb_ReleaseKeys();
				  }
				  else{
					  Usb_SendKeyPress(0x00,USB_USAGE_ID_C);
					  Usb_ReleaseKeys();
				  }
			  }
			  break;

		  case BUTTON_1_4_5_PRESSED:
			  if(slide_Switch){
				  Usb_SendKeyPress(0x00,USB_USAGE_ID_4);
				  Usb_ReleaseKeys();

			  }
			  else{
				  if(caps_LckPressed){
					  Usb_SendKeyPress(LEFT_SHIFT,USB_USAGE_ID_D);
					  Usb_ReleaseKeys();
				  }
				  else{
					  Usb_SendKeyPress(0x00,USB_USAGE_ID_D);
					  Usb_ReleaseKeys();
				  }
			  }
			  break;

		  case BUTTON_1_5_PRESSED:
			  if(slide_Switch){
				  Usb_SendKeyPress(0x00,USB_USAGE_ID_5);
				  Usb_ReleaseKeys();
			  }
			  else{
				  if(caps_LckPressed){
					  Usb_SendKeyPress(LEFT_SHIFT,USB_USAGE_ID_E);
					  Usb_ReleaseKeys();
				  }
				  else{
					  Usb_SendKeyPress(0x00,USB_USAGE_ID_E);
					  Usb_ReleaseKeys();
				  }
			  }
			  break;

		  case BUTTON_1_2_4_PRESSED:
			  if(slide_Switch){
				  Usb_SendKeyPress(0x00,USB_USAGE_ID_6);
				  Usb_ReleaseKeys();

			  }
			  else{
				  if(caps_LckPressed){
					  Usb_SendKeyPress(LEFT_SHIFT,USB_USAGE_ID_F);
					  Usb_ReleaseKeys();
				  }
				  else{
					  Usb_SendKeyPress(0x00,USB_USAGE_ID_F);
					  Usb_ReleaseKeys();
				  }
			  }
			  break;

		  case BUTTON_1_2_4_5_PRESSED:
			  if(slide_Switch){
				  Usb_SendKeyPress(0x00,USB_USAGE_ID_7);
				  Usb_ReleaseKeys();

			  }
			  else{
				  if(caps_LckPressed){
					  Usb_SendKeyPress(LEFT_SHIFT,USB_USAGE_ID_G);
					  Usb_ReleaseKeys();
				  }
				  else{
					  Usb_SendKeyPress(0x00,USB_USAGE_ID_G);
					  Usb_ReleaseKeys();
				  }
			  }
			  break;

		  case BUTTON_1_2_5_PRESSED:
			  if(slide_Switch){
				  Usb_SendKeyPress(0x00,USB_USAGE_ID_8);
				  Usb_ReleaseKeys();

			  }
			  else{
				  if(caps_LckPressed){
					  Usb_SendKeyPress(LEFT_SHIFT,USB_USAGE_ID_H);
					  Usb_ReleaseKeys();
				  }
				  else{
					  Usb_SendKeyPress(0x00,USB_USAGE_ID_H);
					  Usb_ReleaseKeys();
				  }
			  }
			  break;

		  case BUTTON_2_4_PRESSED:
			  if(slide_Switch){
				  Usb_SendKeyPress(0x00,USB_USAGE_ID_9);
				  Usb_ReleaseKeys();

			  }
			  else{
				  if(caps_LckPressed){
					  Usb_SendKeyPress(LEFT_SHIFT,USB_USAGE_ID_I);
					  Usb_ReleaseKeys();
				  }
				  else{
					  Usb_SendKeyPress(0x00,USB_USAGE_ID_I);
					  Usb_ReleaseKeys();
				  }
			  }
			  break;

		  case BUTTON_2_4_5_PRESSED:
			  if(slide_Switch){
				  Usb_SendKeyPress(0x00,USB_USAGE_ID_0);
				  Usb_ReleaseKeys();

			  }
			  else{
				  if(caps_LckPressed){
					  Usb_SendKeyPress(LEFT_SHIFT,USB_USAGE_ID_J);
					  Usb_ReleaseKeys();
				  }
				  else{
					  Usb_SendKeyPress(0x00,USB_USAGE_ID_J);
					  Usb_ReleaseKeys();
				  }
			  }
		  	 break;

		  case BUTTON_1_3_PRESSED:
			  if(caps_LckPressed){
				  Usb_SendKeyPress(LEFT_SHIFT,USB_USAGE_ID_K);
				  Usb_ReleaseKeys();
			  }
			  else{
				  Usb_SendKeyPress(0x00,USB_USAGE_ID_K);
				  Usb_ReleaseKeys();
			  }

		  	  break;

		  case BUTTON_1_2_3_PRESSED:
			  if(caps_LckPressed){
				  Usb_SendKeyPress(LEFT_SHIFT,USB_USAGE_ID_L);
				  Usb_ReleaseKeys();
			  }
			  else{
				  Usb_SendKeyPress(0x00,USB_USAGE_ID_L);
				  Usb_ReleaseKeys();
			  }
		  	  break;

		  case BUTTON_1_3_4_PRESSED:
			  if(caps_LckPressed){
				  Usb_SendKeyPress(LEFT_SHIFT,USB_USAGE_ID_M);
				  Usb_ReleaseKeys();
			  }
			  else{
				  Usb_SendKeyPress(0x00,USB_USAGE_ID_M);
				  Usb_ReleaseKeys();
			  }
		  	  break;

		  case BUTTON_1_3_4_5_PRESSED:
		  	  if(caps_LckPressed){
		  		  Usb_SendKeyPress(LEFT_SHIFT,USB_USAGE_ID_N);
		  		  Usb_ReleaseKeys();
		  	  }
		  	  else{
		  		  Usb_SendKeyPress(0x00,USB_USAGE_ID_N);
		  		  Usb_ReleaseKeys();
		  	  }
		  	 break;

		  case BUTTON_1_3_5_PRESSED:
			  if(caps_LckPressed){
				  Usb_SendKeyPress(LEFT_SHIFT,USB_USAGE_ID_O);
				  Usb_ReleaseKeys();
			  }
			  else{
				  Usb_SendKeyPress(0x00,USB_USAGE_ID_O);
				  Usb_ReleaseKeys();
			  }
			  break;

		 case BUTTON_1_2_3_4_PRESSED:
			if(caps_LckPressed){
				Usb_SendKeyPress(LEFT_SHIFT,USB_USAGE_ID_P);
				Usb_ReleaseKeys();
			}
			else{
				Usb_SendKeyPress(0x00,USB_USAGE_ID_P);
				Usb_ReleaseKeys();
			}
		   break;

		case BUTTON_1_2_3_4_5_PRESSED:
			if(caps_LckPressed){
				Usb_SendKeyPress(LEFT_SHIFT,USB_USAGE_ID_Q);
				Usb_ReleaseKeys();
			}
			else{
				Usb_SendKeyPress(0x00,USB_USAGE_ID_Q);
				Usb_ReleaseKeys();
			}
		   break;

		case BUTTON_1_2_3_5_PRESSED:
			if(caps_LckPressed){
				Usb_SendKeyPress(LEFT_SHIFT,USB_USAGE_ID_R);
				Usb_ReleaseKeys();
			}
			else{
				Usb_SendKeyPress(0x00,USB_USAGE_ID_R);
				Usb_ReleaseKeys();
			}
			break;

		case BUTTON_2_3_4_PRESSED:
			if(caps_LckPressed){
				Usb_SendKeyPress(LEFT_SHIFT,USB_USAGE_ID_S);
				Usb_ReleaseKeys();
			}
			else{
				Usb_SendKeyPress(0x00,USB_USAGE_ID_S);
				Usb_ReleaseKeys();
			}
			break;

		case BUTTON_2_3_4_5_PRESSED:
			if(caps_LckPressed){
				Usb_SendKeyPress(LEFT_SHIFT,USB_USAGE_ID_T);
				Usb_ReleaseKeys();
			}
			else{
				Usb_SendKeyPress(0x00,USB_USAGE_ID_T);
				Usb_ReleaseKeys();
			}
			break;

		case BUTTON_1_3_6_PRESSED:
			if(caps_LckPressed){
				Usb_SendKeyPress(LEFT_SHIFT,USB_USAGE_ID_U);
				Usb_ReleaseKeys();
			}
			else{
				Usb_SendKeyPress(0x00,USB_USAGE_ID_U);
				Usb_ReleaseKeys();
			}
			break;

		case BUTTON_1_2_3_6_PRESSED:
			if(caps_LckPressed){
				Usb_SendKeyPress(LEFT_SHIFT,USB_USAGE_ID_V);
				Usb_ReleaseKeys();
			}
			else{
				Usb_SendKeyPress(0x00,USB_USAGE_ID_V);
				Usb_ReleaseKeys();
			}
			break;

		case BUTTON_2_4_5_6_PRESSED:
			if(caps_LckPressed){
				Usb_SendKeyPress(LEFT_SHIFT,USB_USAGE_ID_W);
				Usb_ReleaseKeys();
			}
			else{
				Usb_SendKeyPress(0x00,USB_USAGE_ID_W);
				Usb_ReleaseKeys();
			}
			break;

		case BUTTON_1_3_4_6_PRESSED:
			if(caps_LckPressed){
				Usb_SendKeyPress(LEFT_SHIFT,USB_USAGE_ID_X);
				Usb_ReleaseKeys();
			}
			else{
				Usb_SendKeyPress(0x00,USB_USAGE_ID_X);
				Usb_ReleaseKeys();
			}
			break;

		case BUTTON_1_3_4_5_6_PRESSED:
			if(caps_LckPressed){
				Usb_SendKeyPress(LEFT_SHIFT,USB_USAGE_ID_Y);
				Usb_ReleaseKeys();
			}
			else{
				Usb_SendKeyPress(0x00,USB_USAGE_ID_Y);
				Usb_ReleaseKeys();
			}
			break;

		 case BUTTON_1_3_5_6_PRESSED:
			 if(caps_LckPressed){
				Usb_SendKeyPress(LEFT_SHIFT,USB_USAGE_ID_Z);
				Usb_ReleaseKeys();
			}
			else{
				Usb_SendKeyPress(0x00,USB_USAGE_ID_Z);
				Usb_ReleaseKeys();
			}
			break;

		  case BUTTON_SPACE_PRESSED:
			  Usb_SendKeyPress(0x00,USB_USAGE_ID_SPACE);
			  Usb_ReleaseKeys();
			  break;

		  case BUTTON_BACKSPACE_PRESSED:
			  Usb_SendKeyPress(0x00,USB_USAGE_ID_BACKSPACE);
			  Usb_ReleaseKeys();
			  break;

		  case CAPS_LCK_PRESSED:
			  caps_LckPressed ^= 1;
			  break;

		  default:
			 // buttonRegister = 0;
			  Usb_ReleaseKeys();
			  Button_pressTimeElapsed = 0;
			  break;
		  }
		  //Usb_ReleaseKeys();
		  buttonRegister = 0;
		  //Button_pressTimeElapsed = 0;
	  }

    /* USER CODE BEGIN 3 */
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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 96;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV6;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin : PA0 */
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

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
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
