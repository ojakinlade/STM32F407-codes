#include "stm32f4xx.h"                  // Device header
#include <stdbool.h>
#include <string.h>
#include "dma.h"
#include "gpio.h"
#include "uart.h"


void HC06_Rx_Init(char* hc06RxBuffer)
{
	GPIO_Alt_Func_Init(GPIOA, GPIO_PIN3_ALT_FUNCTION, GPIO_PIN3, USART_1_2_3);
	USART_Init(USART2, BAUD_9600, USART_DMA_RX_ENABLE, USART_RX_ENABLE);
	
	DMA1_Rx_Init(hc06RxBuffer, 15);
}

void HC06_Begin(void)
{
	DMA_Start();
}

bool HC06_Rx_Done_Receiving(void)
{
	return DMA1_Rx_Interrupt_Ready();
}

void HC06_Restart(char* hc06Rxbuffer)
{
	DMA1_Rx_Clear_Interrupt();
	memset(hc06Rxbuffer, 0, 15);
}

