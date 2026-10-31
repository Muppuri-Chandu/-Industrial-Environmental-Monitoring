
//adc_defines.h


// Include rtc_defines.h so this file can use its declarations and definitions.
#include "rtc_defines.h"

// Define FOSC as a constant or configuration value used by the firmware.
#define FOSC 12000000
//#define CCLK (FOSC*5)
//#define PCLK (CCLK/4)
// Define ADCCLK as a constant or configuration value used by the firmware.
#define ADCCLK 3000000
// Define CLKDIV as a constant or configuration value used by the firmware.
#define CLKDIV ((PCLK/ADCCLK)-1)

//defines for ADCR sfr
// Define CLKDIV_BITS as a constant or configuration value used by the firmware.
#define CLKDIV_BITS        8 //@8-15
// Define PDN_BIT as a constant or configuration value used by the firmware.
#define PDN_BIT            21
// Define ADC_CONV_START_BIT as a constant or configuration value used by the firmware.
#define ADC_CONV_START_BIT 24

//defines for ADDR sfr
// Define DIGITAL_DATA_BITS as a constant or configuration value used by the firmware.
#define DIGITAL_DATA_BITS 6//@6-15
// Define DONE_BIT as a constant or configuration value used by the firmware.
#define DONE_BIT          31

// Define AIN0_PIN_0_27 as a constant or configuration value used by the firmware.
#define AIN0_PIN_0_27 0x00400000
// Define AIN1_PIN_0_28 as a constant or configuration value used by the firmware.
#define AIN1_PIN_0_28 0x01000000
// Define AIN2_PIN_0_29 as a constant or configuration value used by the firmware.
#define AIN2_PIN_0_29 0x04000000
// Define AIN3_PIN_0_30 as a constant or configuration value used by the firmware.
#define AIN3_PIN_0_30 0x10000000

// Define CH0 as a constant or configuration value used by the firmware.
#define CH0 0
// Define CH1 as a constant or configuration value used by the firmware.
#define CH1 1
// Define CH2 as a constant or configuration value used by the firmware.
#define CH2 2
// Define CH3 as a constant or configuration value used by the firmware.
#define CH3 3
//add mores defines as & when required
