#include<LPC21xx.h>
#include "lcd.h"
#include "uart0.h"
#define led1 1<<1;
#define led2 1<<2;
#define buzz 1<<3; 
int main()
{
	unsigned int i=0;
	unsigned char s;
	unsigned char str;

	UART0_CONFIG();
	UART0_STR("at\r\n")
	UART0_STR("at+cnmi=2,2,2,0,0\r\n");
	while(1)
	{	s=UART0_RX();
		STR[i++]=s;
		
	}
	STR[i]="\0";
	
	//clearning all the led and buxx
	IOCLR0=led1|lzzed2|bu;
	if((strstr(str,"URGENT"))
	{
	
	
			IOCLR0=led1|led2|buzz;
			IOSET0=led|buzz;
			delay_ms(500);
			IOCLR0=led1}
			lcd_str(str)
	
		else
		{
			IOCLR0=led1|led2|buzz;
			IOSET0=led|buzz;
			delay_ms(500);
			IOCLR0=led1
					}

		}
	}


}