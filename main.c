#include "util.h"
#include "functions.h"
#include "GPIO.h"
#include "ADC.h"
#include "Interrupt.h"
#include "PWM.h"
#include "UART.h"

int main(void)
{
	//init
	clockInit();
	led_IO_init();
  init_UART1();
	sysTickInit();
    
	for(char counter = 0x21; counter <= 0x7e; counter = counter+1)
		{
			USART1_SendChar(counter);
			delay(100000);
		}
			
    while (1)
    {
			char received = USART1_ReceiveChar();
			USART1_SendChar(received);
			
			if( received == '!')
			{
				led_flash();
			}
			else if (received == '~')
			{
				led_flash();
			}
		}
}

