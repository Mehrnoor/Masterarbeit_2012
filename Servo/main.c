			
#include "C8051F020.h"

//Konfiguration für 1ms Duty Cycle
#define MS1L 0x9A;
#define MS1H 0xF1;


void Init_Device (void);


void main(void)
{
	unsigned short i, j;

	Init_Device();
	
	EA = 1;

	while(1)
	{
		PCA0CPL0  = MS1L;
    	PCA0CPH0  = MS1H;
		for(i=0; i<0x4000; i++)
		{
			for(j=0;j<1012; j++);
		}

		PCA0CPL0  = 0xCC;
    	PCA0CPH0  = 0xF8;
		for(i=0; i<0x4000; i++)
		{
			for(j=0;j<1012; j++);
		}

		PCA0CPL0  = 0x33;
    	PCA0CPH0  = 0xF5;
		for(i=0; i<0x4000; i++)
		{
			for(j=0;j<1012; j++);
		}
			   
	}
}

void PCA_ISR (void) interrupt 9
{
	  PCA0H      = 0x70;
	  PCA0CN	&= 0x7F;
}
