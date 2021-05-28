#include "LPC17xx.h"   //include LPC17xx.h
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
	//LED connected to pin 29 of port 1
	//set direction first
	LPC_GPIO1 ->FIODIR |= 1 << 29; //setting pin 29 of port 1 as output 
	//LPC_GPIO0 ->FIODIR |= 1 << 0; //setting pin 0 of port 0 as output
	while(1)
	{
		LPC_GPIO1 ->FIOSET = 1 << 29; //set pin 29 of port 1 to high
		delay();
		LPC_GPIO1 ->FIOCLR = 1 << 29; //set pin 29 of port 1 to low
		delay();
	}
}
