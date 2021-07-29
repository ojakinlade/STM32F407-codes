#include "Timer.h"
#include "stm32f4xx.h"


void TIMER2_Init(void){//100ms for registering multiple button presses

	RCC->APB1ENR |= 1;	//enable clock for timer 2
	TIM2->PSC = 1600-1;
	TIM2->ARR = 1200-1;		//Time-base of 100ms
	TIM2->CR1 |= (1 << 3);		//one-shot timer mode
	TIM2->DIER = 1;				//ENABLE Update interrupt

}

void TIMER3_Init(void){

		RCC->APB1ENR |= (1 << 1);	//ENABLE clock for timer 3
		TIM3->PSC = 1600-1;			//pre-scaler of 1600
		TIM3->ARR = 64;				//Auto-reload register; Timebase of 6.4ms
		TIM3->CR1 |= (1 << 3);			//one-shot timer mode
		TIM3->DIER = 1;
}
