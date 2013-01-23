#include <ioCC2541.h>
#include "porting_defines.h"

int main( void )
{
  //Setting Chipclock-Source
  CLKCONCMD =0x00;// HXOSC;
  while((CLKCONSTA &= HRCOSC));
  
  //Setting Port-configuration
  PERCFG |= PALT2;
  P0SEL |= 0x80;
  P0DIR |= 0x80;
  
  T1CTL |= MODULO;
  
 // T1CNTL = 0x01;
  
//  T1CCTL3 |= INITOUT;
  T1CCTL3 = FECYCLE | CMPMODE;
  
  // Set Countermax @ 32Mhz/4kHz = 8000dec = 0x1F40
  T1CC0H = 0x1F;
  T1CC0L = 0x40;
  
  // Set Duty-Cycle half of Countermax 4000dec = 0x0FA0
  T1CC3H = 0x0F;
  T1CC3L = 0xA0;
  
  while(1); 
  
  return 0;
}
