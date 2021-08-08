#include "stm32f4xx.h"                  // Device header
#include "clocks.h"

void Clocks_Init(void)
{
	while( (RCC->CR & RCC_CR_HSIRDY) != RCC_CR_HSIRDY); /* Wait till HSI clock becomes ready */
	RCC->CFGR |= RCC_CFGR_HPRE_DIV2;
	//Enable clock for USART2
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
  //Enable for clock for GPIOA
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
		
}
