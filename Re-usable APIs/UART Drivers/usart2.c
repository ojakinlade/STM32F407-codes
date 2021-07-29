#include "stm32f4xx.h"                  // Device header
#include <stdbool.h>
#include "usart2.h"
#include "gpio.h"
#include "uart.h"



void USART2_Init(void)
{
	//Configure PA2 for alternate function(USART2_TX)
	GPIO_Alt_Func_Init(GPIOA, GPIO_PIN2_ALT_FUNCTION, GPIO_PIN2, USART_1_2_3);
	USART_Init(USART2, BAUD_9600, USART_TX_ENABLE);
}

void USART2_Transmit_Byte(char byte)
{
	USART_Transmit_Byte(USART2, byte);
	
}

void USART2_Transmit_String(char* pString)
{
	USART_Transmit_String(USART2, pString);
}

void USART2_Transmit_String_With_Null(char* pString)
{
	
	USART_Transmit_String_With_Null(USART2, pString);
}
