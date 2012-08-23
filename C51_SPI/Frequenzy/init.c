/////////////////////////////////////
//  Generated Initialization File  //
/////////////////////////////////////

#include "C8051F020.h"

// Peripheral specific initialization functions,
// Called from the Init_Device() function
void Reset_Sources_Init()
{
    WDTCN     = 0xDE;
    WDTCN     = 0xAD;
}

void Timer_Init()
{
    CKCON     = 0x48;
    TCON      = 0x10;
    TMOD      = 0x51;
    TH0       = 0xFF;
    T4CON     = 0x34;
    RCAP4L    = 0xFA;
    RCAP4H    = 0xFF;
}

void PCA_Init()
{
    PCA0CN    = 0x40;
    PCA0MD    = 0x04;
    PCA0CPM0  = 0x46;
    PCA0CPH0  = 0x6F;
}

void UART_Init()
{
    SCON1     = 0x50;
}

void SMBus_Init()
{
    SMB0CN    = 0x40;
    SMB0CR    = 0x99;
}

void SPI_Init()
{
    SPI0CFG   = 0x80;
    SPI0CN    = 0x03;
    SPI0CKR   = 0x6D;
}

void ADC_Init()
{
    AMX0SL    = 0x02;
    ADC0CN    = 0x80;
}

void Voltage_Reference_Init()
{
    REF0CN    = 0x07;
}

void Port_IO_Init()
{
    // P0.0  -  TX0 (UART0), Push-Pull,  Digital
    // P0.1  -  RX0 (UART0), Open-Drain, Digital
    // P0.2  -  SCK  (SPI0), Push-Pull,  Digital
    // P0.3  -  MISO (SPI0), Open-Drain, Digital
    // P0.4  -  MOSI (SPI0), Push-Pull,  Digital
    // P0.5  -  NSS  (SPI0), Open-Drain, Digital
    // P0.6  -  SDA (SMBus), Open-Drain, Digital
    // P0.7  -  SCL (SMBus), Open-Drain, Digital

    // P1.0  -  TX1 (UART1), Push-Pull,  Digital
    // P1.1  -  RX1 (UART1), Open-Drain, Digital
    // P1.2  -  CEX0 (PCA),  Push-Pull,  Digital
    // P1.3  -  CEX1 (PCA),  Push-Pull,  Digital
    // P1.4  -  CP1 (Cmpr1), Push-Pull,  Digital
    // P1.5  -  INT0 (Tmr0), Open-Drain, Digital
    // P1.6  -  T1 (Timer1), Open-Drain, Digital
    // P1.7  -  INT1 (Tmr1), Open-Drain, Digital

    // P2.0  -  Unassigned,  Push-Pull,  Digital
    // P2.1  -  Unassigned,  Open-Drain, Digital
    // P2.2  -  Unassigned,  Open-Drain, Digital
    // P2.3  -  Unassigned,  Open-Drain, Digital
    // P2.4  -  Unassigned,  Open-Drain, Digital
    // P2.5  -  Unassigned,  Open-Drain, Digital
    // P2.6  -  Unassigned,  Push-Pull,  Digital
    // P2.7  -  Unassigned,  Push-Pull,  Digital

    // P3.0  -  Unassigned,  Open-Drain, Digital
    // P3.1  -  Unassigned,  Open-Drain, Digital
    // P3.2  -  Unassigned,  Open-Drain, Digital
    // P3.3  -  Unassigned,  Open-Drain, Digital
    // P3.4  -  Unassigned,  Open-Drain, Digital
    // P3.5  -  Unassigned,  Open-Drain, Digital
    // P3.6  -  Unassigned,  Open-Drain, Digital
    // P3.7  -  Unassigned,  Open-Drain, Digital

    P0MDOUT   = 0x15;
    P1MDOUT   = 0x1D;
    P2MDOUT   = 0xC1;
    P74OUT    = 0x08;
    XBR0      = 0x17;
    XBR1      = 0x1D;
    XBR2      = 0x44;
}

void Oscillator_Init()
{
    int i = 0;
    OSCXCN    = 0x67;
    for (i = 0; i < 3000; i++);  // Wait 1ms for initialization
    while ((OSCXCN & 0x80) == 0);
    OSCICN    = 0x0C;
}

void Interrupts_Init()
{
    IE        = 0x80;
    EIE2      = 0x40;
}

// Initialization function for device,
// Call Init_Device() from your main program
void Init_Device(void)
{
    Reset_Sources_Init();
    Timer_Init();
    PCA_Init();
    UART_Init();
    SMBus_Init();
    SPI_Init();
    ADC_Init();
    Voltage_Reference_Init();
    Port_IO_Init();
    Oscillator_Init();
    Interrupts_Init();
}
