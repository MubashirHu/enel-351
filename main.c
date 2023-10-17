#include "util.h"
#include "stm32f10x.h"
#include "clock.h"
#include "pin.h"
#include "adc.h"
#include "systick.h"
#include "interrupt.h"
int main()
{
	clockInit();
	enable_port('A');
	led_IO_init();
	SysTick_Init(0xB71B00);
	init_interrupt();
	A_set_low(1);
	while(1)
	{
		if((GPIOA->IDR & GPIO_IDR_IDR1) != 0)
		{
			delay(270000);
			A_set_low(1);
		}
	}
}

void SysTick_Handler(void)
{
	GPIOA->ODR ^= GPIO_ODR_ODR5;
}

void EXTI0_IRQHandler(void)
{
	EXTI->PR |= EXTI_PR_PR0;
	A_set_high(1);
	
}
