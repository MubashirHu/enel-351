#include "C:\Users\hussa\Downloads\util.h"
#include "functions.h"
#include "GPIO.h"
#include "ADC.h"
#include "Interrupt.h"

int main(void)
{
	//init
	clockInit();
	led_GPIO_Init();
	sysTickInit();


	//infinite loop
	while(1)
	{
			ISR1();
	
		
	}
}
