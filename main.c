#include "C:\Users\hussa\Downloads\util.h"
#include "functions.h"
#include "GPIO.h"
#include "ADC.h"
#include "Interrupt.h"
#include "PWM.h"
#include "UART.h"

char c;

int main(void)
{
	//init
	clockInit();
	// Initialize USART1
  init_UART1();
	sysTickInit();
    
    // Send 'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!' characters
    USART1_SendChar('H');
    USART1_SendChar('e');
    USART1_SendChar('l');
    USART1_SendChar('l');
    USART1_SendChar('o');
    USART1_SendChar(' ');
    USART1_SendChar('W');
    USART1_SendChar('o');
    USART1_SendChar('r');
    USART1_SendChar('l');
    USART1_SendChar('d');
    USART1_SendChar('!');
    
    // Receive a character and echo it back
    c = USART1_ReceiveChar();
    USART1_SendChar(c);
    
    while (1)
    {
        // Your main code here
		c = USART1_ReceiveChar();
    USART1_SendChar(c);
    }
}
