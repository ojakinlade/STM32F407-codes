#include "Button.h"
#include "stm32f4xx.h"
#include "Timer.h"


/*
 * Pin assignments for buttons
 * Button       |   Pin[STM32]
 * 1            |   PB4
 * 2            |   PB3
 * 3            |   PB1		//PB2 on the discovery is not available as its connected to the boot pin
 * CAPS_LCK		|	PB0
 * 4            |   PC1
 * 5            |   PC2
 * 6            |   PC3
 * SPACE        |   PC0
 * SLIDE_SW		|	PC5
 * BACKSPACE    |   PC4
*/


volatile uint8_t Button_debounced = 0;
volatile uint8_t Timer_counting = 0;
volatile uint8_t Button_pressTimeElapsed = 0;

void Button_Init(void){
	RCC->AHB1ENR |= (1<<1) | (1<<2) | (1<<3); //Enables clock for GPIOB AND GPIOC
	GPIOB->MODER &= ~((3UL<<8) | (3UL<<6) | (3UL<<2) | (3UL<<0)); //sets PB4,PB3,PB1,PB0 as input
	GPIOB->PUPDR |= (1<<8) | (1<<6) | (1<<2) | (1<<0); //Enables PULL-UP resistor for PB4,PB3,PB1,PB0
	GPIOC->MODER &= ~((3UL<<2) | (3UL<<4) | (3UL<<0) | (3UL<<6) | (3UL<<8) | (3UL<<10));		//Sets PC1,PC2,PC0,PC3,PC4,PC5 as input
	GPIOC->PUPDR |= (1<<2) | (1<<4) | (1<<0) | (1<<6) | (1<<8);		//Enables PULL-UP resistor for PC1,PC2,PC0,PC3,PC4
	GPIOD->MODER |= (1<<26) | (1<<24) | (1<<28);

}

bool Button_Debounce(uint8_t buttonStatus){
	if(buttonStatus){
		Button_debounced = 0;
		TIM3->CR1 |= 1;		//Start TIMER3
		while(!(Button_debounced)){/*wait for 45ms*/}
		if(buttonStatus){
			return true;
		}

	}
	return false;

}

void Button_Poll(Button_t *button, uint16_t *p_buttonRegister){
	if(Button_Debounce(button->pressed) && !button->prevPressed)
		{
			if(!Timer_counting)
			{
				TIM2->CR1 |= 1;		//enables timer 2
				Timer_counting = 1;
			}
			*p_buttonRegister |= (1 << button->bitLocation);
			button->prevPressed = 1;
		}
		else if(!Button_Debounce(button->pressed) && button->prevPressed)
			button->prevPressed = 0;

}

void TIM2_IRQHandler(void){
	TIM2->SR = 0;		//Clears interrupt flag
	Button_pressTimeElapsed = 1;
	Timer_counting = 0;
}

void TIM3_IRQHandler(void){
	TIM3->SR = 0;		//clears interrupt flag
	Button_debounced = 1;
}

