#include "stm32f4xx.h"                  // Device header
#include <stdint.h>
#include <stdbool.h>
#include "clocks.h"
#include "gpio.h"
#include "uart.h"
#include "dma.h"
#include "SysTimer_Struct.h"
#include "systick.h"


static char* buffer = "Embedded\n";
//char* uartBuffer;


int main(void)
{
	Clocks_Init();
	SysTick_Init();
	GPIO_Init();
	DMA1_Init();
	UART_Init();
	

	
	
	while(1)
	{
		DMA1_Transmit(buffer);
		while(DMA1_Is_Sending());
		//DMA1_Restart();
	
		
	}
	
}
