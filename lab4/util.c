
 #include "stm32f10x.h"
 #include "util.h"
 

//**************************** Utility ************************************************************
// delay = 1800 is approximately 1 ms @ SYSCLK = 24 MHz (ymmv)

void delay(uint32_t delay)
{
  	 while (delay--)
	{
		}
}



//**************************** I/O ************************************************************

void led_IO_init (void)
{
    //Enable Port A and Port C clocks
    
    RCC->APB2ENR |=  RCC_APB2ENR_IOPCEN | RCC_APB2ENR_IOPAEN ;
	
		
	//****************NUCLEO-64*******************************************************************
//    //Set the config and mode bits for Port A bit 5 so it will be a push-pull output (up to 50 MHz)
		GPIOA->CRH |= GPIO_CRH_MODE8 | GPIO_CRH_MODE9 | GPIO_CRH_MODE10;
    GPIOA->CRL |= GPIO_CRL_MODE7;

		GPIOA->CRL |= GPIO_CRL_MODE5;
    GPIOA->CRL &= ~GPIO_CRL_CNF5;
		GPIOA->CRL |= GPIO_CRL_MODE1;
    GPIOA->CRL &= ~GPIO_CRL_CNF1;
	//****************NUCLEO-64*******************************************************************
	
}	
	
void sw2led(void)
{
	
  	// Read the USER button and control the GREEN LED pattern according to its state
  
	
	if ((GPIOC->IDR & GPIO_IDR_IDR13) == 0)
		
  {
     GPIOA->BSRR = NUC_GREEN_ON;
  }
  else
  {
     GPIOA->BSRR = NUC_GREEN_OFF;
  }
}
	
	
void led_flash(void)
{			
	    while(1){
			GPIOA->BSRR = NUC_GREEN_ON;
			delay(1800);
	    GPIOA->BSRR = NUC_GREEN_OFF;
			delay(1800);
			}
}

