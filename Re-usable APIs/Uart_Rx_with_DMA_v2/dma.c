#include "stm32f4xx.h"                  // Device header
#include <stdbool.h>
#include "dma.h"
#include <string.h>

static volatile bool dma1Stream[No_Of_DMA1_Streams];


void DMA1_Rx_Init(char* uartRxBuffer, uint32_t bufferSize)
{
	RCC->AHB1ENR |= RCC_AHB1ENR_DMA1EN;
	DMA1_Stream5->CR &= ~DMA_SxCR_EN;
	DMA1_Stream5->PAR = (uint32_t)&USART2->DR;
	DMA1_Stream5->M0AR = (uint32_t)uartRxBuffer;
	DMA1_Stream5->NDTR = bufferSize;
	DMA1_Stream5->CR |= DMA_SxCR_CHSEL_2 | DMA_SxCR_MINC | DMA_SxCR_TCIE | DMA_SxCR_CIRC;
	NVIC_EnableIRQ(DMA1_Stream5_IRQn);
	
}

void DMA_Start(void)
{
	DMA1_Stream5->CR |= DMA_SxCR_EN;
}

bool DMA1_Rx_Interrupt_Ready(void)
{
	return dma1Stream[5];
}

void DMA1_Rx_Clear_Interrupt(void)
{
	dma1Stream[5] = false;
}

//void DMA1_Transmit(const char* data)
//{
//	DMA1_Stream6->NDTR = strlen(data);
//	DMA1_Stream6->PAR = (uint32_t)&USART2->DR;
//	DMA1_Stream6->M0AR = (uint32_t)data;
//	DMA1_Stream6->CR |= DMA_SxCR_EN;
//}

bool DMA1_Is_Sending(void)
{
	if((DMA1->HISR & DMA_HISR_TCIF6) == DMA_HISR_TCIF6)
	{
		return false;
	}
	else
		return true;
}

void DMA1_Restart(void)
{
	
		DMA1_Stream6->CR &= ~DMA_SxCR_EN;
}

void DMA1_Stream5_IRQHandler(void)
{
	DMA1->HIFCR |= DMA_HIFCR_CTCIF5;
	dma1Stream[5] = true;
}
