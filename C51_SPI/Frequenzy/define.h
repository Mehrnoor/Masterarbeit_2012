//SMBus states:
// MT = Master Transmitter
// MR = Master Receiver
// ST = Slave Transmitter
// SR = Slave Receiver

#define  SMB_BUS_ERROR  0x00              // (all modes) BUS ERROR
#define  SMB_START      0x08              // (MT & MR) START transmitted
#define  SMB_RP_START   0x10              // (MT & MR) repeated START
#define  SMB_MTADDACK   0x18              // (MT) Slave address + W transmitted;
                                          //  ACK received
#define  SMB_MTADDNACK  0x20              // (MT) Slave address + W transmitted;
                                          //  NACK received
#define  SMB_MTDBACK    0x28              // (MT) data byte transmitted; ACK rec'vd
#define  SMB_MTDBNACK   0x30              // (MT) data byte transmitted; NACK rec'vd
#define  SMB_MTARBLOST  0x38              // (MT) arbitration lost
#define  SMB_MRADDACK   0x40              // (MR) Slave address + R transmitted;
                                          //  ACK received
#define  SMB_MRADDNACK  0x48              // (MR) Slave address + R transmitted;
                                          //  NACK received
#define  SMB_MRDBACK    0x50              // (MR) data byte rec'vd; ACK transmitted
#define  SMB_MRDBNACK   0x58              // (MR) data byte rec'vd; NACK transmitted
#define  SMB_SROADACK   0x60              // (SR) SMB's own slave address + W rec'vd;
                                          //  ACK transmitted
#define  SMB_SROARBLOST 0x68              // (SR) SMB's own slave address + W rec'vd;
                                          //  arbitration lost
#define  SMB_SRGADACK   0x70              // (SR) general call address rec'vd;
                                          //  ACK transmitted
#define  SMB_SRGARBLOST 0x78              // (SR) arbitration lost when transmitting
                                          //  slave addr + R/W as master; general
                                          //  call address rec'vd; ACK transmitted
#define  SMB_SRODBACK   0x80              // (SR) data byte received under own slave
                                          //  address; ACK returned
#define  SMB_SRODBNACK  0x88              // (SR) data byte received under own slave
                                          //  address; NACK returned
#define  SMB_SRGDBACK   0x90              // (SR) data byte received under general
                                          //  call address; ACK returned
#define  SMB_SRGDBNACK  0x98              // (SR) data byte received under general
                                          //  call address; NACK returned
#define  SMB_SRSTOP     0xa0              // (SR) STOP or repeated START received
                                          //  while addressed as a slave
#define  SMB_STOADACK   0xa8              // (ST) SMB's own slave address + R rec'vd;
                                          //  ACK transmitted
#define  SMB_STOARBLOST 0xb0              // (ST) arbitration lost in transmitting
                                          //  slave address + R/W as master; own
                                          //  slave address rec'vd; ACK transmitted
#define  SMB_STDBACK    0xb8              // (ST) data byte transmitted; ACK rec'ed
#define  SMB_STDBNACK   0xc0              // (ST) data byte transmitted; NACK rec'ed
#define  SMB_STDBLAST   0xc8              // (ST) last data byte transmitted (AA=0);
                                          //  ACK received
#define  SMB_SCLHIGHTO  0xd0              // (ST & SR) SCL clock high timer per
                                          //  SMB0CR timed out (FTE=1)
#define  SMB_IDLE       0xf8              // (all modes) Idle

#define ADR_LCD 0x74
#define Zeile1 0x80
#define Zeile2 0xA0
#define Zeile3 0xC0

#define SMB_START 0x08		  		
#define SMB_CTRL_SEND 0x18
#define SMB_DATA_SEND 0x28




