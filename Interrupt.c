#include "Interrupt.h"
#include "stm32f10x.h"


void ISR1(void)
{
	GPIOA->ODR ^= GPIO_ODR_ODR5;
}

void EXTI_Init(void)
{
	
}
	
