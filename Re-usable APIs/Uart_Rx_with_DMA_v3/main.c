#include <stdint.h>
#include <stdbool.h>
#include "system.h"
#include "hc06.h"

char hc06ReceiveBuffer[HC06_BUFFER_SIZE];

int main(void)
{
	System_Init();
	HC06_Rx_Init(hc06ReceiveBuffer);
	
	while(1)
	{
		HC06_Begin();
		while(!HC06_Rx_Done_Receiving());
		HC06_Restart(hc06ReceiveBuffer);
		
	}
}
