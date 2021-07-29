#include "stm32f4xx.h"                  // Device header
#include <stdbool.h>
#include "SysTimer_Struct.h"
#include "system.h"
#include "systick.h"
#include "clocks.h"

void System_Init(void)
{
	/*
	Description:
	
	Parameters:
	
	Return:
	
	*/
	
	Clocks_Init();
	SysTick_Init();
}

void System_Timer_DelayMs(uint32_t delayTime)
{
	/*
	Description:
	
	Parameters:
	
	Return:
	
	*/
	SysTick_DelayMs(delayTime);
	
}

void System_Alarm_Init(sysTimer_t* pSysTimer, uint32_t timerRepTime)
{
	/*
	Description:
	
	Parameters:
	
	Return:
	
	*/
	
	pSysTimer->start = 0;
	pSysTimer->isCounting = false;
	pSysTimer->ticksToWait = timerRepTime;
}

bool System_Alarm_Ready(sysTimer_t* pSysTimer)
{
	bool countingComplete = false;
	
	if (!pSysTimer->isCounting)
	{
		pSysTimer->start = SysTick_GetTick();
		pSysTimer->isCounting = true;
	}
	
	else
	{
		if ( SysTick_Timer_Done_Counting(pSysTimer) )
		{
			countingComplete = true;
			pSysTimer->start = 0;
			pSysTimer->isCounting = false;
		}
	}
	
	return countingComplete;
}
