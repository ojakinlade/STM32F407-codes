#include "stm32f4xx.h"                  // Device header
#include <stdbool.h>
#include "SysTimer_Struct.h"
#include "system.h"
#include "usart2.h"
#include "gpio.h"

static char* tx_buffer = "Embedded Systems\n";

int main(void)
{
	System_Init();
	USART2_Init();
	GPIO_Input_Init(GPIOA, GPIO_PIN0, false);

	
	while(1)
	{
		//Transmit string when button is pressed
		if(GPIO_Input_Read(GPIOA, GPIO_PIN0))
		{
			//USART2_Transmit_String_With_Null(tx_buffer);
			USART2_Transmit_String(tx_buffer);
		}
		
	}
	
	
}
