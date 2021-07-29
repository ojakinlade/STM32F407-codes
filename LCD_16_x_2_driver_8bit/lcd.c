#include "stm32f4xx.h"                  // Device header
#include <stdint.h>
#include <stdbool.h>
#include "lcd.h"
#include "SysTimer_Struct.h"
#include "systick.h"
#include "gpio.h"

#define LCD_CMD_SELECT										false
#define LCD_DATA_SELECT										true

#define LCD_RS														GPIO_PIN5
#define LCD_EN														GPIO_PIN6
#define LCD_D0														GPIO_PIN0
#define LCD_D1														GPIO_PIN1
#define LCD_D2														GPIO_PIN2
#define LCD_D3														GPIO_PIN3									
#define LCD_D4														GPIO_PIN4
#define LCD_D5														GPIO_PIN5
#define LCD_D6														GPIO_PIN6
#define LCD_D7														GPIO_PIN7

#define CMD_FUNCTION_SET_8BIT									0x30  
#define CMD_FUNCTION_SET_2LINE_5X8_DOT				0x38 
#define CMD_CLEAR_DISPLAY											0x01
#define CMD_DISPLAY_ON_CURSOR_ON							0x0E
#define CMD_DISPLAY_ON_CURSOR_OFF							0x0C
#define CMD_ENTRY_MODE_INCREMENT_CURSOR				0x06

/*Two-dimensional array to map column and row
combinations to 16x2 LCD DDRAM addresses. (see HD44780 datasheet)
*/
const uint8_t ddramAddr[2][16] = {{0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F},
																	{0x40,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4A,0x4B,0x4C,0x4D,0x4E,0x4F}};


static void LCD_Write(bool regSelect, uint8_t byte)
{
	/*
	@brief:
	@param:
	@return:
	*/
	
	//Select instruction register or data register
	GPIO_Output_Write(GPIOB, LCD_RS, regSelect);
	
	//Send DATA
	GPIO_Output_Clear_Reg(GPIOC,
														 (1<<LCD_D0)|
														 (1<<LCD_D1)|
														 (1<<LCD_D2)|
														 (1<<LCD_D3)|
														 (1<<LCD_D4)|
														 (1<<LCD_D5)|
														 (1<<LCD_D6)|
														 (1<<LCD_D7));
	
	GPIO_Output_Reg_Write(GPIOC, byte);
	
	//High to low pulse
	GPIO_Output_Write(GPIOB, LCD_EN, LCD_DATA_SELECT);
	SysTick_DelayMs(1);
	GPIO_Output_Write(GPIOB, LCD_EN, LCD_CMD_SELECT);
	SysTick_DelayMs(1);
	
		
}


void LCD_Init(void)
{
	/*
	@brief:
	@param:
	@return:
	*/
	
	//Configure PB5 and PB6 as output
	GPIO_Output_Init(GPIOB, (GPIO_PIN6_GEN_PUR_OUTPUT | GPIO_PIN5_GEN_PUR_OUTPUT));
	//Configure PC0...7 as output
	GPIO_Output_Init(GPIOC, ( GPIO_PIN0_GEN_PUR_OUTPUT | GPIO_PIN1_GEN_PUR_OUTPUT |
														GPIO_PIN2_GEN_PUR_OUTPUT | GPIO_PIN3_GEN_PUR_OUTPUT |
														GPIO_PIN4_GEN_PUR_OUTPUT | GPIO_PIN5_GEN_PUR_OUTPUT |
														GPIO_PIN6_GEN_PUR_OUTPUT | GPIO_PIN7_GEN_PUR_OUTPUT));
	
	//Initialization sequence
	SysTick_DelayMs(16); //wait for more than 15ms after power-on
	LCD_Write(LCD_CMD_SELECT, CMD_FUNCTION_SET_8BIT);
	SysTick_DelayMs(5);	 //Wait for more than 4.1ms
	LCD_Write(LCD_CMD_SELECT, CMD_FUNCTION_SET_8BIT);
	SysTick_DelayMs(1);	 //Wait for more than 100us
	LCD_Write(LCD_CMD_SELECT, CMD_FUNCTION_SET_8BIT);
	
	//Select all init commands for 8-bit interface
	LCD_Write(LCD_CMD_SELECT,CMD_FUNCTION_SET_2LINE_5X8_DOT); 
	LCD_Write(LCD_CMD_SELECT,CMD_CLEAR_DISPLAY);
	LCD_Write(LCD_CMD_SELECT,CMD_DISPLAY_ON_CURSOR_OFF); 
	LCD_Write(LCD_CMD_SELECT,CMD_ENTRY_MODE_INCREMENT_CURSOR);
	
}

void LCD_Write_Data(char data)
{
	/*
	@brief: Selects data register and sends data
	@param:
	@return:
	*/
	
	
	LCD_Write(LCD_DATA_SELECT, data);
}

void LCD_Write_String(char* pData)
{
	/*
	@brief: Selects data register and sends string
	@param:
	@return:
	*/
	
	while(*pData != '\0')
	{
		LCD_Write(LCD_DATA_SELECT, *pData);
		pData++;
	}
	
}

void LCD_Clear(void)
{
	/*
	@brief: Clears the display
	@param: None
	@return: None
	*/
	
	LCD_Write(LCD_CMD_SELECT, CMD_CLEAR_DISPLAY);
}

void LCD_Set_Cursor(uint8_t row, uint8_t column)
{
	//row number cannot be greater than 1
	//and column number cannot be greater than 16
	if((row > 1) || (column > 16))
	{
		return;
	}
	
	LCD_Write(LCD_CMD_SELECT, ((1<<7) | ddramAddr[row][column]));
}
