#include "C8051F020.h"

#include "define.h"

#include "dependences.h"





void Init_Device(void);

void LCD_write();
void show_display (unsigned char Zeile, unsigned char Message[12]);
void send(unsigned char ken[12]);
void AD_Wand(bit w,char k);
void freq();
void wandlascii(unsigned int e,char k);
void PCA();
unsigned long SPI_read();


bit LCD_init = 0;			//bei 0x18 entscheidet sich ob initialisierung (3 byte) oder Datenbyte
bit SM_BUSY; 			/* = 1 I2C-Bus belegt */
bit TMR_BUSY;



unsigned char CONTROL_LCD;
unsigned char flag=0;
unsigned char ken0[12]={"Projekt SS09"};
//unsigned char ken1[12]={"Temp:   ,  C"};
//unsigned char ken1[12]={"S:-0000000uV"};
unsigned char ken1[12]={"            "};
unsigned char ken2[12]={"AIN:    ,  V"};
unsigned char ken3[12]={"Freq:  , kHz"};
unsigned char ken4[12]={"cmd :    kHz"};
extern unsigned char ken5[12];	
unsigned char Text_RAM[14];
unsigned int exchange;

unsigned char k;
unsigned char in = 0;


void main (void)
{
	Init_Device();
	SPI0CFG |= 0x07;	//8 Bits pro Master-SPI-Transfer
	EA=1;
	LCD_init = 1;  // Bit zur Verzweigung in der ISR
	P5=0x0F;
	CONTROL_LCD = SMB_BUS_ERROR;

	LCD_write();

	P2_0 = 1;

	while(1)
	{
//		switch(P5)
//		{
//			case 0x07:
//			{
			
					SPI_read();
					show_display(1,ken5);
//					break;
//			}
//
//			default:
//			{
//					break;
//			}
//		}
	}
}
