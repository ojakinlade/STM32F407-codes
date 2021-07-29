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
	LCD_Set_Cursor(0,4);
	LCD_Write_String("EMBEDDED");
	LCD_Set_Cursor(1,5);
	LCD_Write_String("SYSTEMS");

	while(1)
	{
		
		
	}
	
}
