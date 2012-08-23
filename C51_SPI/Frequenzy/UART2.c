//------------------------------------------------------------------------------------------------------------------------------
//Deklarationen und Konstanten
//-----------------------------------------------------------------------------------------------------------------------------*/
#include "C8051F020.h" // Registersatz verwenden

void send(unsigned char ken[12]);

extern unsigned char flag;
extern unsigned char ken0[12];
extern unsigned char ken1[12];
extern unsigned char ken2[12];
extern unsigned char ken3[12];
extern unsigned char ken4[12];
extern unsigned int exchange;


//void Empf_ISR(void) interrupt 20
//{
//	static bit empf=0;
//	static unsigned char date=0;
//
//	
//
//
//
//	switch(SBUF1)
//	{
//
//		case 0x1B:
//					if (empf==0) empf=1;
//					break;
//		case 0xE0:
//					if (empf) flag=1;
//					break;
//		case 0xE1:
//					if (empf) flag=2;	
//					break;
//		case 0xE2:
//					if (empf) flag=3;
//					break;
//		case 0xE3:
//					if (empf) flag=4;
//					break;
//		case 0xE4:
//					if (empf) date=1;
//					break;
//		case 0x01:
//					if (date==1) date=2;
//					break;
//
//		default:
//
//
//					if(date==2) 
//					{
//		
//						exchange=(10*(SBUF1/16)+(SBUF1%16));
//						empf=0;
//						date=0;
//						flag=5;
//						break;
//					} 
//
//
//					empf=0;
//					date=0;
//					break;
//		}
//			
//		
//		SCON1 &= 0xFE;
//	
//}
//
//void send(unsigned char ken[12])				
//{		
//		unsigned char i;
//		for(i=0;i<12;i++)					
//		{
//			 				
//			while((SCON1 & 0x02) != 0x02); // Senden beendet?
//			SBUF1 = ken[i];
//			SCON1 &= 0xfd; // Wenn ja: Sendeflag löschen
//		}	
//}
