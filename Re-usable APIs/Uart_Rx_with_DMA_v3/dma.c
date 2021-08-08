#include "stm32f4xx.h"                  // Device header
#include <stdbool.h>
#include "dma.h"
#include <string.h>

#define No_Of_DMA1_Streams			8

static volatile bool dma1Stream[No_Of_DMA1_Streams];

void DMA_USART_Rx_Init(DMA_Stream_TypeDef* dmaStream, 
															USART_TypeDef* uartPort, 
															char* uartRxBuffer, 
															uint32_t bufferSize, 
															uint32_t dmaConfig)
														
{
	dmaStream->PAR = (uint32_t)&uartPort->DR;
	dmaStream->M0AR = (uint32_t)uartRxBuffer;
	dmaStream->NDTR = bufferSize;
	dmaStream->CR |= dmaConfig;
	NVIC_EnableIRQ(DMA1_Stream5_IRQn);
	
}															


void DMA_Start(void)
{
	DMA1_Stream5->CR |= DMA_SxCR_EN;
}

bool DMA_Rx_InterruptReady(DMA_TypeDef* dmaPort, uint8_t streamNumber)
{
	return dma1Stream[streamNumber];
}

void DMA_Rx_Clear_Interrupt(DMA_TypeDef* dmaPort, uint8_t streamNumber)
{
	dma1Stream[streamNumber] = false;
}


void DMA1_Stream5_IRQHandler(void)
{
	DMA1->HIFCR |= DMA_HIFCR_CTCIF5;
	dma1Stream[DMA_STREAM5] = true;
}
