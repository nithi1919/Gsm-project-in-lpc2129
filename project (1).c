#include <LPC21xx.h>
#include<string.h>
#include "lcd.h"
#include "uart0.h"
#include "gsmsim.h"

#define EINTO 1<<0;
#define LED1 1<<5
#define LED2 1<<6
#define BUZZ 1<<7

char str[100];
unsigned char flag=1;

	void EXT_INTO_isr(void)__irq
{
	EXTINT=0x01;
	flag= !flag;
	VICVectAddr=0;

}


int main()
{
		unsigned char ch;
		unsigned int i=0;
		unsigned int j=0;
	
	PINSEL1=EINTO;
	VICIntSelect=0x00000000;
	VICVectCntl0=(0x20)|14;
	VICVectAddr0= (int)EXT_INTO_isr;
	EXTMODE=0x00;
	EXTPOLAR=0x00;
	VICIntEnable=1<<14;		 
while(1)
 {
	if(flag)
	
	{

		LCD_INIT();
		LCD_COMMAND(0x80);
		LCD_STRING("WEATER");
		UART0_CONFIG();
	    UART0_SEND_STRING("testing");

	delay_ms(2000);
	GSM_INIT();
	while(1)
	{
	do
	{
 	ch=UART0_RX();
	}
	while(ch!='*');
	i=0;
	do
	{
	str[i++]=UART0_RX();
	}
	while(str[i-1]!='#');
	str[i-1]='\0';
					}

	if((strstr(str,"URGENT"))!=NULL)
	 {
	 			UART0_SEND_STRING(str);
	 			IOSET0=LED1|LED2|BUZZ;
				IOCLR0=BUZZ;
				LCD_STRING(str);
				while(j<=25)
				{
					IOCLR0=LED1;
					delay_milliseconds(500);
					IOSET0=LED2;
					delay_milliseconds(500);
					j++;
				}
	}
		
	else
		{
			IOSET0=LED1|LED2|BUZZ;
			IOCLR0=LED2;
			LCD_COMMAND(0x80);
			LCD_STRING(str);
		}
		}
		else
		{
		IOSET0=LED1|LED2|BUZZ;
		LCD_COMMAND(0x01);
		}
		}
		}



	

