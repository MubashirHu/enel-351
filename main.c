#include "C:\Users\hussa\Downloads\util.h"
#include "functions.h"
#include "GPIO.h"
#include "ADC.h"
#include "Interrupt.h"
#include "PWM.h"

int main(void)
{
	//init
	clockInit();
	initializeADC();
	tim3GpioSetup();
	sysTickInit();


	//infinite loop
	while(1)
	{
		int sw_val = adc_Read();
		
		//between 0 and 0.825V
		if(sw_val > 0x000 && sw_val <=0x3FF)
		{
			updateDutyCycle(40);
			
		} else if(sw_val > 0x3FF && sw_val <= 0x7FF) // between 0.825V and 1.65V
		{
			updateDutyCycle(50);
		}
		else if(sw_val > 0x7FF && sw_val <= 0xBFF) // between 1.65V and 2.475V
		{
			updateDutyCycle(70);
		}		
		else if(sw_val > 0xBFF && sw_val <= 0xFFF) // between 2.475 and 3.3V
		{
			updateDutyCycle(80);
		}	
		
	}
}
