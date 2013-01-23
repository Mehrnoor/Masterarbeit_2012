//******************************************************
//   ADS1232_SPI Project
//
//	 Description: Half (two wire) SPI-interface, 
// 	 specified for use with the TI ADS1232 24-bit 
//	 analog-to-digital converter for bridge sensors. A 
//   single measurement is triggered through a push on 
//   an external piezo buzzer.
//
//	 Warning: no low-power-mode implemented yet. Use 
//	 		  with USB-debugger supply is recommended.
//
//	Built was developed through an code example from 
//  Texas Instruments inc. called "CC430F613x Demo - 
//	USCI_A0, SPI 3-Wire Master Incremented Data" and the
//  "ez430_chronos" standard workspace for an 
//  ez430_Chronos developement tool.
//
//        CC430F6137
//     -----------------
// /|\|                 |
//  | |                 |
//  --|RST          	|
//    |                 |
//    |             P1.6|-> Data Out (UCA0SIMO)
//    |                 |
//    |             P1.5|<- Piezo-interrupt-input
//    |                 |
//	  |	            P1.7|-> Serial Clock Out (UCA0CLK)
//
//
//   sjobstm
//   UAS Landshut
//   August 2012
//******************************************************

#include "cc430x613x.h"

#define ADS_TX_BUFFER         (UCA0TXBUF)
#define ADS_RX_BUFFER         (UCA0RXBUF)
#define ADS_TX_IFG            (UCTXIFG)
#define ADS_RX_IFG            (UCRXIFG)
#define ADS_IRQ_REG           (UCA0IFG)
#define ADS_SPI_CTL0          (UCA0CTL0)
#define ADS_SPI_CTL1          (UCA0CTL1)
#define ADS_SPI_BR0           (UCA0BR0)
#define ADS_SPI_BR1           (UCA0BR1)

unsigned char MST_Data,SLV_Data,check[4];

void main(void)
{
	// Stop watchdog timer
	WDTCTL = WDTPW+WDTHOLD;           		
	// Get write-access to port mapping regs 
	PMAPPWD = 0x02D52; 
    // Map UCA0SOMI output to P1.5           		 
	P1MAP5 = PM_UCA0SOMI;  
    // Map UCA0CLK output to P1.7               
	P1MAP7 = PM_UCA0CLK;  
    // Lock port mapping registers                 
	PMAPPWD = 0;                               

	// ACLK, MCLK, SMCLK set out to pins
	P1DIR |= BIT5 + BIT7;  
    // P2.0,2,4 for debugging purposes.        		
	P1SEL |= BIT5 + BIT7;              		

	// **Put state machine in reset**
	UCA0CTL1 |= UCSWRST;   
    // 3-pin, 8-bit SPI master              
	UCA0CTL0 |= UCMST+UCSYNC+UCCKPH+UCMSB;  
  
	// Clock polarity high, MSB
	// SMCLK
	UCA0CTL1 |= UCSSEL_2; 
    // /120 = 100kHz                
	UCA0BR0 = 0x78;   
    //                    
	UCA0BR1 = 0;   
    // No modulation                       
	UCA0MCTL = 0;    
    // **Initialize USCI state machine** 
	UCA0CTL1 &= ~UCSWRST;       
    // Set acceleration sensor power on          
	PJDIR |= BIT0;							
	PJOUT |= BIT0;

    // Set MISO to input
	P1DIR &= ~(BIT5 + BIT6);	
	// Disable Pull-ups/downs			
	P1REN &= ~(BIT5 + BIT6);					

	// Trigger interrupt on rising edge
	P1IES &= ~BIT6;		
					
	// Reset interrupt flags
	P1IFG &= ~BIT6;							

	// Enable Piezo-interrupt
	P1IE |= BIT6;								

	// Wait for slave to initialize
	__delay_cycles(100);                      
	__enable_interrupt();
	while(1);
}

#pragma vector=PORT1_VECTOR
__interrupt void PORT1_ISR(void)
{
	P1SEL &= ~BIT5;
	while((P1IN & BIT5));
	P1SEL |= BIT5;

	// USCI_A0 TX buffer ready?
	while (!(UCA0IFG&UCTXIFG));               
	// Write dummy data to TX buffer
	ADS_TX_BUFFER = 0;                        
	// Wait until new data was written into RX buffer
	while (!(ADS_IRQ_REG & ADS_RX_IFG)) ;  	
	// Read RX buffer
	check[0] = ADS_RX_BUFFER;                 

	// Write dummy data to TX buffer
	ADS_TX_BUFFER = 0;                        
	// Wait until new data was written into RX buffer
	while (!(ADS_IRQ_REG & ADS_RX_IFG)) ;		
	// Read RX buffer
	check[1] = ADS_RX_BUFFER;                 

	// Write dummy data to TX buffer
	ADS_TX_BUFFER = 0;                        
	// Wait until new data was written into RX buffer
	while (!(ADS_IRQ_REG & ADS_RX_IFG)) ;  	
	// Read RX buffer
	check[2] = ADS_RX_BUFFER;                 

	// Write dummy data to TX buffer
	ADS_TX_BUFFER = 0;                        
	// Wait until new data was written into RX buffer
	while (!(ADS_IRQ_REG & ADS_RX_IFG)) ;  
    // Read RX buffer
	check[3] = ADS_RX_BUFFER;                 
	// No valid value inside, so deleted!
	check[3] = 0x00; 							

	__disable_interrupt();
	P1IFG = 0x00;
	P1IE = BIT6;
	__enable_interrupt();
}
