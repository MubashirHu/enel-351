#include "stm32f10x.h"
#include "interrupt.h"

void init_interrupt(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN | RCC_APB2ENR_AFIOEN;
	AFIO->EXTICR[0] |= AFIO_EXTICR1_EXTI0_PB;
	EXTI->IMR |= EXTI_IMR_MR0;
	EXTI->FTSR |= EXTI_FTSR_TR0;
	NVIC->ISER[0] |= NVIC_ISER_SETENA_6;
}



