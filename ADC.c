#include "adc.h"
#include "stm32f10x.h"
void adc_init(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN |RCC_APB2ENR_ADC1EN;
	
	GPIOA->CRL |= GPIO_CRL_CNF0_0;
	GPIOA->CRL &= 0xFFFFFFF0;
	
	ADC1->CR2 |= ADC_CR2_ADON;
}

int adc_read(int channel_num)
{
	
	ADC1->SQR3 = 0x00000000;
	ADC1->CR2 |= ADC_CR2_ADON;
	while(ADC1->SR & ADC_SR_EOC != 1)
	{
	}
	int read_val = ADC1->DR;
	
	return read_val;
}
	
