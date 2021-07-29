#include <stdbool.h>
#include <stdint.h>
#include "SysTimer_Struct.h"
#include "system.h"

static sysTimer_t delayTimer1;
static sysTimer_t delayTimer2;
volatile uint8_t a;
volatile uint8_t b;

int main(void)
{
	System_Init();
	System_Alarm_Init(&delayTimer1, 1000);
	System_Alarm_Init (&delayTimer2, 2000);
	
	
	while(1)
	{
		if(System_Alarm_Ready(&delayTimer1))
		{
			a++; //increments a every 1s
		}
		if(System_Alarm_Ready(&delayTimer2))
		{
			b++; //increments b every 2s
		}
		
	}
}
