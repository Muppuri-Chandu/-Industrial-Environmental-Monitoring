//uart_defines1.h

// Define TXD0_PIN as a constant or configuration value used by the firmware.
#define TXD0_PIN 0x00000001 

// Define RXD0_PIN as a constant or configuration value used by the firmware.
#define RXD0_PIN 0x00000004 


// Define FOSC as a constant or configuration value used by the firmware.
#define FOSC 12000000

// Define CCLK as a constant or configuration value used by the firmware.
#define CCLK (FOSC*5)

// Define PCLK as a constant or configuration value used by the firmware.
#define PCLK (CCLK/4)

// Define BAUD as a constant or configuration value used by the firmware.
#define BAUD 9600

// Define DIVISOR as a constant or configuration value used by the firmware.
#define DIVISOR (PCLK/(16*BAUD))


//defines for UxLCR

// Define _8BIT as a constant or configuration value used by the firmware.
#define _8BIT 3

// Define WORD_LEN as a constant or configuration value used by the firmware.
#define WORD_LEN _8BIT

// Define WORD_LEN_SEL_BITS as a constant or configuration value used by the firmware.
#define WORD_LEN_SEL_BITS 0

// Define DLAB_BIT as a constant or configuration value used by the firmware.
#define DLAB_BIT 7


//defines for UxLSR

// Define DR_BIT as a constant or configuration value used by the firmware.
#define DR_BIT   0

// Define TEMT_BIT as a constant or configuration value used by the firmware.
#define TEMT_BIT 6


// Define U0_TX_INT_EN as a constant or configuration value used by the firmware.
#define U0_TX_INT_EN 0

// Define U0_RX_INT_EN as a constant or configuration value used by the firmware.
#define U0_RX_INT_EN 0

// Define U0_TX_RX_INT_EN as a constant or configuration value used by the firmware.
#define U0_TX_RX_INT_EN 0


//define for UxIER sfr

// Define RDA_INT_EN_BIT as a constant or configuration value used by the firmware.
#define RDA_INT_EN_BIT  0

// Define THRE_INT_EN_BIT as a constant or configuration value used by the firmware.
#define THRE_INT_EN_BIT 1


//defines for UxIIR sfr

// Define THRE_INT as a constant or configuration value used by the firmware.
#define THRE_INT 1

// Define RDA_INT as a constant or configuration value used by the firmware.
#define RDA_INT  2


//defines for status of interrupt

// Define U0_TX_STATUS_LED as a constant or configuration value used by the firmware.
#define U0_TX_STATUS_LED 8//p0.8

// Define U0_RX_STATUS_LED as a constant or configuration value used by the firmware.
#define U0_RX_STATUS_LED 9//p0.9


// Define U0_VIC_CHNO as a constant or configuration value used by the firmware.
#define U0_VIC_CHNO 6

