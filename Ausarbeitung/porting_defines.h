//---------------------------------------------------
//
//
//    Easy MS430 to SoC porting Header
//
//
//
//---------------------------------------------------


//accessing the TxCTl register
#define DIV_1   0x0000
#define DIV_8   0x0004
#define DIV_32  0x0008
#define DIV_128 0x000C

#define SUSPEND 0x0000
#define FREERUN 0x0001
#define MODULO  0x0002
#define UPDOWN  0x0003


//accessing the Timer 1 
//Channel 3 Capture/Compare Control
#define RFIRQ   0x80
#define T3IM    0x40
#define FECYCLE 0x28      // falling cycling edge
#define RECYCLE 0x30      // rising cycling edge
#define INITOUT 0x38      // Initialize output pin
#define CMPMODE 0x04      // Set for output Compare 


//accessing the Clock Registers

//Use with CLKCONCMD to change main-clock-source
#define HXOSC  0x40  
//Use with CLKCONSTA to check 
//if clock-source has changed
#define HRCOSC 0x40     

//accessing the Portconfig

#define PALT2 0x40