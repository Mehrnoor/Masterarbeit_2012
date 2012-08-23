#include "C8051F020.h" 
#include "dependences.h"



unsigned char ken5[12]={"SPI:      mV"};

union
{
	unsigned char 	c[4];
	unsigned int 	i[2];
	unsigned long	longre;
}analog;



#ifndef TEMP
void wandlascii_signed(unsigned int e)
{
	unsigned int reference = REFERENCE;
/*Folgender Codeausschnitt bewirkt nur eine laufende Animation auf dem LCD-EA T123-I2C*/
#ifdef EVAL_BOARD
	static unsigned char inc = 0x8F;

	switch(inc)
	{
		case 0x94:
					inc = 0xBD;
					break;
		case 0xBD:
					inc = 0x90;
					break;
		default:
					inc++;
					break;
	}

#endif	 //#ifdef EVAL_BOARD

#ifdef MV_OUT

	ken5[0] = inc;
	ken5[1] = ':';
	ken5[2] = ' ';	
	ken5[3] = ' ';
	ken5[4] = ' ';

	/*Erkennen des Vorzeichenbits und Auswertung als Symbol*/
	ken5[5] = (e > 0x7FFF) ? 0x2D : 0x2B;

	e = e << 1;			   //Entfernung des Vorzeichenbits
	e = e >> 1;

	e =((unsigned long)e * reference)/65536;
	ken5[6]=e/1000+ 0x30;
	e = e % 1000;
	ken5[7]=e/100+ 0x30;
	e = e % 100;
	ken5[8]=e/10 + 0x30; 
	e = e % 10;
	ken5[9]=e + 0x30;
	ken5[10]= 'm';
#endif  //#ifdef MV_OUT
 
#ifdef UV_OUT
	
	ken5[0] = inc;
	ken5[1]= ':';
	
	/*Erkennen des Vorzeichenbits und Auswertung als Symbol*/
 	ken5[2] = (e > 0x7FFF) ? 0x2D : 0x2B;

	e = e << 1;			   //Entfernung des Vorzeichenbits
	e = e >> 1;

	e =(((unsigned long)e * reference*100))>>16;

	/* Ganzzahl-in-String Umwandlung */
	ken5[3]=e/100000 + 0x30;
	e = e % 100000;
	ken5[4]=e/10000 + 0x30; 
	e = e % 10000;
	ken5[5]=e/1000 + 0x30;
	e = e % 1000;
	ken5[6]=e/100 + 0x30;
	e = e % 100;
	ken5[7]=e/10 + 0x30;
	e = e % 10;
	ken5[8]=e + 0x30;
	ken5[9]= '5';
	ken5[10]= 'u';

#endif //#ifdef UV_OUT
} 
#endif //#ifndef TEMP

#ifdef TEMP
void wandlascii_signed(unsigned long e)
{
	unsigned long	subb  = SUBB;
	unsigned long 	div = DIV;
	unsigned int step = STEP;

/*Folgender Codeausschnitt bewirkt nur eine laufende Animation auf dem LCD-EA T123-I2C*/	
#ifdef EVAL_BOARD
	static unsigned char inc = 0x8F;

	switch(inc)
	{
		case 0x94:
					inc = 0xBD;
					break;
		case 0xBD:
					inc = 0x90;
					break;
		default:
					inc++;
					break;
	}
#endif	 //EVAL_BOARD
	
	ken5[0] = inc;
	ken5[1]= ':';
	ken5[2]= ' ';

	/*Kürzen des 32Bit ulong Wertes auf den 24Bit-Inhalt.*/
	/*Beispiel: 34 45 B4 00h --> 34 45 B4h 				 */
	e = e >> 8;
		
	/*Erkennen des Vorzeichenbits und Auswertung als Symbol*/
	ken5[3] = (e > 0x7FFFFF) ? 0x2D : 0x2B;

	e = e << 1;			   //Entfernung des Vorzeichenbits
	e = e >> 1;

	/*Berechnung nach Kalibrationswerten*/
	e =(e-subb)*10/div;

	/* Ganzzahl-in-String Umwandlung */
	ken5[5]=e/1000 + 0x30;
	e = e % 1000;
	ken5[6]=e/100 + 0x30;
	e = e % 100;

	ken5[7]= ',';

	ken5[8]=e/10 + 0x30;
	e = e % 10;
	ken5[9]= e + 0x30;
	ken5[10]= ' ';
	ken5[11]= 'C';
}
#endif


void SPI_read(void)
{
	unsigned char 	i = 0;

	/*eventuell muss zum Pollen des DATAREADY-Zustands der SPI-MODE der GPIO ausgeschalten werden!*/
	//SPI0CN &= 0xFE;

	while(MISO_PIN);   /*warten bis DATAREADY anliegt*/

	//SPI0CN |= 0x01;

	for(i = 0; i < 4; i++)
	{
		SPI0DAT = 0xAA;
		while(!SPIF);
		SPIF = 0;
		analog.c[i] = SPI0DAT;
	}
	analog.c[3] = 0x00;

#ifdef TEMP
	wandlascii_signed(analog.longre);
#else
   wandlascii_signed(analog.i[0]);
#endif
}