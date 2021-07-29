#ifndef _TIMER_H_
#define _TIMER_H_

#include "stdint.h"
extern void TIMER2_Init(void);
extern void TIMER3_Init(void);
extern volatile uint8_t Timer_counting;

#endif //_TIMER_H_
