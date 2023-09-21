#include "util.h"
#include "functions.h"
#include "GPIO.h"

int main(void)
{
	//init
	clockInit();
	led_IO_init();
	switch_IO_Init();
	led_GPIO_Init();

	//infinite loop
	while(1)
	{
		
		uint16_t state = read_DIP();
		
		
		if (state == 1)
		{
			routine1();
		}
		else if( state == 2)
		{
			routine2();
		}
		else if( state == 4)
		{
			routine3();
		}
		else if( state == 8)
		{
			routine4();
		}
		else{
			//nothing
		}
		
	}
	
}
