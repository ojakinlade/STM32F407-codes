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
	
	while((RCC->CR & RCC_CR_HSIRDY) != RCC_CR_HSIRDY)
	{
		//Put init codes
		
	}
}

