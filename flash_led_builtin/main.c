#include "LPC17xx.h" // Device header

void delay(void) //function to define delay
{
	int i,j;
	for (i = 0; i < 1000; i++)
	{
		for(j = 0; j< 2000; j++);
	}
}

int main()
{
	LPC_PINCON->PINSEL0 = 0x00000000; //configure all port 0  pins as GPIO
	LPC_GPIO0->FIODIR = 0x0000000F; //configure pin 0,1,2,3 of port 0 as output
	
	while(1)
	{
		LPC_GPIO0->FIOSET = 0x0000000F; //set pin 0,1,2,3 of port 0 as high
		delay(); //wait for 1 second
		LPC_GPIO0->FIOCLR = 0x0000000F; //set pin 0,1,2,3 of port 0 as low
		delay(); //wait for 1 secondd
	}
}