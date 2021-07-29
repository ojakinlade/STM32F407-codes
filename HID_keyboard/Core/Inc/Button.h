#ifndef _BUTTON_H
#define _BUTTON_H

#include "stdint.h"
#include "stdbool.h"

extern void Button_Init(void);
extern uint8_t slide_Switch;

//Button Pin
#define BUTTON1       (1<<4)
#define BUTTON2       (1<<3)
#define BUTTON3       (1<<1)
#define BUTTON4       (1<<1)
#define BUTTON5       (1<<2)
#define BUTTON6       (1<<3)
#define SPACE         (1<<0)
#define BACKSPACE     (1<<4)
#define SLIDE_SW	  (1<<5)
#define CAPS_LCK      (1<<0)

//Button(s) pressed singly / simultaneously
#define BUTTON_1_PRESSED            (1<<0)
#define BUTTON_2_PRESSED            (1<<1)
#define BUTTON_3_PRESSED            (1<<2)
#define BUTTON_4_PRESSED            (1<<3)
#define BUTTON_5_PRESSED            (1<<4)
#define BUTTON_6_PRESSED            (1<<5)
#define BUTTON_SPACE_PRESSED        (1<<6)
#define BUTTON_BACKSPACE_PRESSED    (1<<7)
#define CAPS_LCK_PRESSED			(1<<8)
#define BUTTON_1_2_PRESSED          (1<<0)|(1<<1)
#define BUTTON_1_4_PRESSED          (1<<0)|(1<<3)
#define BUTTON_1_4_5_PRESSED        (1<<0)|(1<<3)|(1<<4)
#define BUTTON_1_5_PRESSED          (1<<0)|(1<<4)
#define BUTTON_1_2_4_PRESSED        (1<<0)|(1<<1)|(1<<3)
#define BUTTON_1_2_4_5_PRESSED      (1<<0)|(1<<1)|(1<<3)|(1<<4)
#define BUTTON_1_2_5_PRESSED        (1<<0)|(1<<1)|(1<<4)
#define BUTTON_2_4_PRESSED          (1<<1)|(1<<3)
#define BUTTON_2_4_5_PRESSED        (1<<1)|(1<<3)|(1<<4)
#define BUTTON_1_3_PRESSED          (1<<0)|(1<<2)
#define BUTTON_1_2_3_PRESSED        (1<<0)|(1<<1)|(1<<2)
#define BUTTON_1_3_4_PRESSED        (1<<0)|(1<<2)|(1<<3)
#define BUTTON_1_3_4_5_PRESSED      (1<<0)|(1<<2)|(1<<3)|(1<<4)
#define BUTTON_1_3_5_PRESSED        (1<<0)|(1<<2)|(1<<4)
#define BUTTON_1_2_3_4_PRESSED      (1<<0)|(1<<1)|(1<<2)|(1<<3)
#define BUTTON_1_2_3_4_5_PRESSED    (1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)
#define BUTTON_1_2_3_5_PRESSED      (1<<0)|(1<<1)|(1<<2)|(1<<4)
#define BUTTON_2_3_4_PRESSED        (1<<1)|(1<<2)|(1<<3)
#define BUTTON_2_3_4_5_PRESSED      (1<<1)|(1<<2)|(1<<3)|(1<<4)
#define BUTTON_1_3_6_PRESSED        (1<<0)|(1<<2)|(1<<5)
#define BUTTON_1_2_3_6_PRESSED      (1<<0)|(1<<1)|(1<<2)|(1<<5)
#define BUTTON_2_4_5_6_PRESSED      (1<<1)|(1<<3)|(1<<4)|(1<<5)
#define BUTTON_1_3_4_6_PRESSED      (1<<0)|(1<<2)|(1<<3)|(1<<5)
#define BUTTON_1_3_4_5_6_PRESSED    (1<<0)|(1<<2)|(1<<3)|(1<<4)|(1<<5)
#define BUTTON_1_3_5_6_PRESSED      (1<<0)|(1<<2)|(1<<4)|(1<<5)

extern volatile uint8_t Button_pressTimeElapsed;

typedef struct{
	uint8_t pressed;
	uint8_t prevPressed;
	uint8_t bitLocation;

}Button_t;

extern volatile uint8_t Button_debounced;
extern uint16_t buttonRegister;

extern bool Button_Debounce(uint8_t buttonStatus);
extern void Button_Poll(Button_t *button, uint16_t *p_buttonRegister);

#endif//_BUTTON_H
