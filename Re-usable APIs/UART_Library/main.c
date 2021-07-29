#include "stm32f4xx.h"                  // Device header
#include <stdint.h>
#include <stdbool.h>
#include "clocks.h"
#include "gpio.h"
#include "uart.h"
#include "SysTimer_Struct.h"
#include "systick.h"





int main(void)
{
	Clocks_Init();
	SysTick_Init();
	GPIO_Init();
	UART_Init();

	
	
	while(1)
	{
		UART_Send('T');
		UART_Send('E');
		UART_Send('L');
		UART_Send('L');
		UART_Send('\n');
	
	
		
	}
	
}
