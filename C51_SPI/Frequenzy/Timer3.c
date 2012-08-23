#include "C8051F020.h"


void wandlascii(unsigned int e,char k);

extern unsigned char ken3[12];
extern bit TMR_BUSY;

 union
 {
 	unsigned char c[2];
	unsigned int i;
}datum;	   




//
//void T3_ISR (void) interrupt 14
//{
//	static unsigned char count = 0;
//	TMR3CN&=0x7F;		 //interrupt flag löschen
//	count++;
//	if(count == 29)		   //war default-mäßig auf 29  hängt ab Werten von 256??!?!?
//	{
//		TR1=0;				  	//Timer1 disabled
//		TMR3CN=TMR3CN & 0xFB;  	//Timer3 stoppen
//								/*setzen des Loadwertes von Timer3*/
//		TMR3L=0x00;				
//		TMR3H=0xE0;				
//
//		datum.c[0]=TH1;			
//		datum.c[1]=TL1;
//		wandlascii(datum.i,3);		
//		TH1=0;
//		TL1=0;
//								/*rücksetzen des "Cache" von Timer1*/
//		P5=0x0F;				//LEDs ausschalten 
//		EIE2&=0xFE;				//Timer3 interrupt disablen
//		count=0;
//		TMR_BUSY=0;
//
//	}
//} 

