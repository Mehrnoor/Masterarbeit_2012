#include "C8051F020.h"
#include "define.h"





extern bit LCD_init;			//bei 0x18 entscheidet sich ob initialisierung (3 byte) oder Datenbyte
extern bit SM_BUSY; 			/* = 1 I2C-Bus belegt */
extern unsigned char CONTROL_LCD;
extern unsigned char Text_RAM[14];
extern unsigned char k;
extern unsigned char in;


void Init_LCD();
void LCD_write();

void SMBus_ISR(void) interrupt 7
{
	switch (SMB0STA)
	{
		case SMB_START : 
		{
							SMB0DAT=ADR_LCD;	 		//(slave-Addresse + WR)
							STA=0;							//Clear START-Bit
		}break;
		case SMB_CTRL_SEND:
		{
							SMB0DAT=CONTROL_LCD;				//Config-Byte wird gesendet
		}break;
		case SMB_DATA_SEND:
							if (LCD_init==1) 
							{
								Init_LCD();
							}
							else 
							{
								unsigned char x = 0;
								if (k >= 2) x = 1;
								SMB0DAT = (Text_RAM[k]+(x*0x80));
								k++;	
								if (k == 15)
								{
									SM_BUSY = 0;
									STO = 1;
									k = 0;
								}
							}break;
								
		default:	
							//SM_BUSY = 0; // SMBus freigeben
							break;
		}
		SI=0;
}

void show_display (unsigned char Zeile, unsigned char Message[12])
{
	unsigned char k;
	LCD_init = 0; // Text ausgeben
	CONTROL_LCD = SMB_SRODBACK; 
	switch (Zeile)
	{
		case 1:
				Text_RAM[0] = Zeile1;
				break;
		case 2:
				Text_RAM[0] = Zeile2;
				break;
		case 3: 
				Text_RAM[0] = Zeile3;
				break;
		default:
				break;
	}
	Text_RAM[1] = SMB_MRADDACK;
	for (k=0; k<=11; k++)
		Text_RAM[k+2] = (Message[k]);	//Text_RAM[k+2] = Textfeld[Zeile-1][k];
	LCD_write();
}


void Init_LCD()	 /*Teil der LCD_ISR*/  //fertig!!   
{
	switch (in)
	{
		case 0:	
		{		SMB0DAT=0x3E;		//Function_Set
				in++;
		}break;

		case 1:				
		{		SMB0DAT=0x0F;		//Display-control  
				in++;
		}break;

		case 2:			
		{		SMB0DAT=0x06;		//Entry mode 
				in++;
		}break;

		case 3:				
		{		SM_BUSY = 0;
				STO=1;
				in=0;
		}break;
	}
}


void LCD_write()
{
	while (SM_BUSY);
	SM_BUSY=1;
	EIE1 |= 0x02;				  //Datentransfer gestartet
	STO=0;
	STA=1;
	while (SM_BUSY);			  
	EIE1 &=0xFD;
}
