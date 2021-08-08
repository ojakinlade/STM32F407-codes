#include "stm32f4xx.h"                  // Device header
#include <stdbool.h>
#include <string.h>
#include "dma.h"
#include "gpio.h"
#include "uart.h"
#include "hc06.h" 


void HC06_Rx_Init(char* hc06RxBuffer)
{
	GPIO_Alt_Func_Init(GPIOA, GPIO_PIN3_ALT_FUNCTION, GPIO_PIN3, USART_1_2_3);
	USART_Init(USART2, BAUD_9600, USART_DMA_RX_ENABLE, USART_RX_ENABLE);
	
	DMA_USART_Rx_Init(DMA1_Stream5, USART2, hc06RxBuffer, HC06_BUFFER_SIZE, (DMA_STREAM5_CHANNEL4_SELECT | DMA_STREAM5_CIRCULAR_BUFFER |
																																					 DMA_STREAM5_MEMORY_INC_MODE | DMA_STREAM5_TC_INT_ENABLE));
}

void HC06_Begin(void)
{
	DMA_Start();
}

bool HC06_Rx_Done_Receiving(void)
{
	return DMA_Rx_InterruptReady(DMA1, DMA_STREAM5);
}

void HC06_Restart(char* hc06Rxbuffer)
{
	DMA_Rx_Clear_Interrupt(DMA1, DMA_STREAM5);
	memset(hc06Rxbuffer, 0, HC06_BUFFER_SIZE);
}

