#include "C8051F020.h" 
 


void wandlascii(unsigned int e,char k);




extern unsigned char ken1[12];
extern unsigned char ken2[12];
extern unsigned char ken3[12];
extern unsigned char ken4[12];
extern unsigned char ken5[12];

//union
//{
//	unsigned char c[2];
//	unsigned int  i;
//}cw;
//
//
//
//
//void AD_Wand (bit w,char k)
//{
//	unsigned int temp,sp;
//	AMX0SL=k;
//	AD0LJST=w;
//	AD0BUSY=1;	     //ADWandlung läuft
//	while(AD0INT==0); //prüf ob ADWandlung(-> mit Flag AD0INT==1)
//	cw.c[0]=ADC0H;	  //übername der gewandelten werte (highbyte)
//	cw.c[1]=ADC0L;	  //übername der gewandelten werte (lowbyte)
//	AD0INT=0;
//	if(w==1)
//	{
//		temp=(cw.i-21190)*10/78;  //berechnung des Temperaturwertes in °C
//		wandlascii(temp,1);
//	}
//	else 
//	{
//		sp=((unsigned long)cw.i*2400)/4096;	//berechnung des Spannungswertes in mV (unsigned long wird benötigt da großer zwischen wert)
//		wandlascii(sp,2);		  
//	}
//}







void wandlascii(unsigned int e,char k)
{	

	switch (k)
	{
	case 1: //temp
		{
			ken1[6]=e/100+0x30;
			e=e%100;
			ken1[7]=e/10+0x30;
			e=e%10;
			ken1[9]=e/1+0x30;
			break;

		}
	case 2:   // poti
		{
  			ken2[7]=e/1000+ 0x30;
  			e = e % 1000;
   			ken2[9]=e/100+ 0x30;
   			e = e % 100;
  			ken2[10]=e/10 + 0x30;
			break; 
		}
	case 3:	 //frequenz1
		{
  			ken3[5]=(e/10000)+ 0x30;
  			e = e % 10000;
   			ken3[6]=(e/1000)+ 0x30;
   			e = e % 1000;
  			ken3[8]=(e/100) + 0x30;
			break; 
		}
	case 4:	 //frequenz2
		{
			ken4[6]=(e/10)+0x30;
			e=e%10;	
			ken4[7]=e+0x30;
			break;
		}
	}
} 