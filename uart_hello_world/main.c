#include "LPC17xx.h"                    // Device header

void UART0_Init(void);

unsigned int i;
unsigned char *ptr, arr[] = "Hello Dunia\n";

int main(void)
{
	UART0_Init();
	
	while(1)
	{
		ptr = arr;
		while (*ptr != '\0')
		{
			LPC_UART0->THR = *ptr++;
		
		}
		for(i=0;i<=60000;i++);
	}
}

void UART0_Init(void)
{
	LPC_SC->PCONP |= 0x00000008; //UART0 peripheral enable
	LPC_PINCON->PINSEL0 = 0x00000050;
	LPC_UART0->LCR = 0x00000083; //enable divisor latch, parity disable, 1 stop bit, 8bit word length
	LPC_UART0->DLM = 0x00;
	LPC_UART0->DLL = 0x1A; //select baud rate 9600 bps for 4Mhz
	LPC_UART0->LCR = 0x00000003; //disable divisor latch
	LPC_UART0->FCR = 0x07; //FIFO enable, RX FIFO reset, TX FIFO reset
	
}
