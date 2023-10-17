#include "pin.h"
#include "stm32f10x.h"
#include <stdint.h>
uint32_t lookup_set(uint8_t a);
uint32_t lookup_reset(uint8_t a);

void A_set_high(uint8_t a)
{
	GPIOA->BSRR |= lookup_set(a);
}

void A_set_low(uint8_t a)
{
	GPIOA->BSRR |= lookup_reset(a);
}


void B_set_high(uint8_t a)
{
	GPIOB->BSRR |= lookup_set(a);
}

void B_set_low(uint8_t a)
{
	GPIOB->BSRR |= lookup_reset(a);
}

void C_set_high(uint8_t a)
{
	GPIOC->BSRR |= lookup_set(a);
}

void C_set_low(uint8_t a)
{
	GPIOC->BSRR |= lookup_reset(a);
}

uint32_t lookup_set(uint8_t a)
{
	if (a < 16)
		return 0x00000001 << a;
	else
		return 0;
}

uint32_t lookup_reset(uint8_t a)
{
	if (a < 16)
		return 0x00000001 << (a + 16);
	else
		return 0;
}	
