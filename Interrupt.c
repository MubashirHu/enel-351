#include "Interrupt.h"
#include "stm32f10x.h"

void sysTickInit(void)
{
	
	SysTick->LOAD |= 0xB71B00;
	SysTick->CTRL |= SysTick_CTRL_CLKSOURCE | SysTick_CTRL_ENABLE;
	
}

void ISR1(void)
{
	GPIOA->ODR ^= GPIO_ODR_ODR5;
}

void EXTI_Init(void)
{
	
}
	
