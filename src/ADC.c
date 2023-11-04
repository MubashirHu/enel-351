#include "../headers/ADC.h"
#include "stm32f10x.h"

void initializeADC(void)
{
	//Enable ADC1, AFIO, PORT A
	RCC->APB2ENR |= (RCC_APB2ENR_ADC1EN | RCC_APB2ENR_AFIOEN | RCC_APB2ENR_IOPAEN);
	
	// configure port as an analog input 
	GPIOA->CRL |= GPIO_CRL_CNF0_0;
	GPIOA->CRL &= 0xFFFFFFF0;
	
	// turn ADC on
	ADC1->CR2 = ADC_CR2_ADON;
}

uint16_t adc_Read(void)
{
	ADC1->SQR3 = 0x00000000;
	ADC1->CR2 = 0x00000001;
	
	while(ADC1->SR == 0)
		{
			//nothing
		}
		
		return ADC1->DR;

}
