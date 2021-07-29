#include "stm32f4xx.h"                  // Device header
#include <stdbool.h>
#include "dma.h"
#include <string.h>


void DMA1_Init(void)
{
	RCC->AHB1ENR |= RCC_AHB1ENR_DMA1EN;
	DMA1_Stream6->CR &= ~DMA_SxCR_EN;
	DMA1_Stream6->CR |= DMA_SxCR_CHSEL_2 | DMA_SxCR_MINC | DMA_SxCR_DIR_0 | DMA_SxCR_TCIE | DMA_SxCR_CIRC;
	NVIC_EnableIRQ(DMA1_Stream6_IRQn);
	
}

void DMA1_Transmit(const char* data)
{
	DMA1_Stream6->NDTR = strlen(data);
	DMA1_Stream6->PAR = (uint32_t)&USART2->DR;
	DMA1_Stream6->M0AR = (uint32_t)data;
	DMA1_Stream6->CR |= DMA_SxCR_EN;
}

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

void DMA1_Stream6_IRQHandler(void)
{
	DMA1->HIFCR |= DMA_HIFCR_CTCIF6;
}
