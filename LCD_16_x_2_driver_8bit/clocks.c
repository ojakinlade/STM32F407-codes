#include "stm32f4xx.h"                  // Device header
#include "clocks.h"

void Clocks_Init(void)
{
	/*
	Description:
	Initializes all required device peripherals clocks.
	
	Parameters:
	None
	
	Return:
	None
	
	*/
	
	while((RCC->CR & RCC_CR_HSIRDY) != RCC_CR_HSIRDY); //wait till HSI clock stabilizes
	RCC->CFGR |= RCC_CFGR_HPRE_DIV2;
	RCC->AHB1ENR |= ( RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOBEN | RCC_AHB1ENR_GPIOCEN | RCC_AHB1ENR_GPIODEN);
	
}

