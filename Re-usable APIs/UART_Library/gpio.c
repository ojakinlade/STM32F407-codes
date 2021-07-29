#include "stm32f4xx.h"                  // Device header
#include "gpio.h"

void GPIO_Init(void)
{
	GPIOD->MODER |= GPIO_MODER_MODE12_0;
	//set PA2 and PA3 as alternate function
	GPIOA->MODER |= ( (GPIO_MODER_MODE2_1) | (GPIO_MODER_MODE3_1) ); //SETS PA2 and PA3 to alternate function mode
	GPIOA->AFR[0] |= 0x700;  //Sets USART2 as the alternate function
}
