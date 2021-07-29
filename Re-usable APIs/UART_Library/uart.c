#include "stm32f4xx.h"                  // Device header
#include "uart.h"


void UART_Init(void)
{
	USART2->CR1 |= USART_CR1_UE; //Usart enale
	USART2->BRR = 0x683; //baud-rate of 9600 at 16Mhz clock
	USART2->CR1 |= USART_CR1_TE; //Send IDLE frame as first transmission
}

void UART_Send(uint8_t character)
{
	while( (USART2->SR & USART_SR_TXE) != USART_SR_TXE);
	USART2->DR = character;
}

