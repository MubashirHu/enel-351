#include "../headers/util.h"
#include "../headers/functions.h"
#include "../headers/GPIO.h"
#include "../headers/ADC.h"

int main(void)
{
	clockInit();
	led_GPIO_Init();
	initializeADC();

	while(1)
	{
		int sw_val = adc_Read();
		
		if(sw_val > 0x000 && sw_val <=0x3FF)
		{
			drive_LED_Binary(1);
			
		} else if(sw_val > 0x3FF && sw_val <= 0x7FF)
		{
			drive_LED_Binary(2);
		}
		else if(sw_val > 0x7FF && sw_val <= 0xBFF)
		{
			drive_LED_Binary(4);
		}		
		else if(sw_val > 0xBFF && sw_val <= 0xFFF)
		{
			drive_LED_Binary(8);
		}	
	}
}
