#include "LPC17xx.h"                    // Device header
#define voltage 1024
#define freq 120000


int main(void)
{
	uint32_t m;
	
	LPC_PINCON->PINSEL1 |= (1 << 21);
	while(1)
	{
		LPC_DAC->DACR = (voltage/2 << 6);
		for(m = freq; m > 1; m--)
		LPC_DAC -> DACR = (voltage <<6);
		for(m = freq; m >1; m--);
	}
}