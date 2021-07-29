#include <stdint.h>
#include <stdbool.h>
#include "SysTimer_Struct.h"
#include "system.h"
#include "systick.h"
#include "lcd.h"



int main(void)
{
	System_Init();
	LCD_Init();
	LCD_Clear();
	LCD_Set_Cursor(0,0);
	LCD_Write_String("Embedded");

	while(1)
	{
			
	}
}
