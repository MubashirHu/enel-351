#include "systick.h"

void SysTick_Init(uint32_t reload_val)
{
	SysTick->CTRL = 0x0;
	SysTick->VAL = 0x0;
	SysTick->LOAD = reload_val;
	SysTick->CTRL |= SysTick_CTRL_CLKSOURCE | SysTick_CTRL_ENABLE | SysTick_CTRL_TICKINT;
		
}



