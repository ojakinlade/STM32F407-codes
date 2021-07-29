#include "stm32f4xx.h"                  // Device header
#include <stdbool.h>
#include <stdint.h>
#include "SysTimer_Struct.h"
#include "system.h"
#include "gpio.h"



int main(void)
{
	System_Init();
	
	GPIO_Input_Init(GPIOA, GPIO_PIN0, false);
	GPIO_Output_Init(GPIOD, GPIO_PIN15_GEN_PUR_OUTPUT);

	while(1)
	{
		if(GPIO_Input_Read(GPIOA, GPIO_PIN0))
		{
			GPIO_Output_Write(GPIOD, GPIO_PIN15, true);
		}
		else
			GPIO_Output_Write(GPIOD, GPIO_PIN15, false);
		
		
	}
}
