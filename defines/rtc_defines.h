//rtc_defines1.h
// Start the include guard for RTC_DEFINES_H to prevent repeated inclusion.
#ifndef RTC_DEFINES_H
// Define RTC_DEFINES_H as a constant or configuration value used by the firmware.
#define RTC_DEFINES_H

// System clock and peripheral clock Macros
// Define FOSC as a constant or configuration value used by the firmware.
#define FOSC 12000000
// Define CCLK as a constant or configuration value used by the firmware.
#define CCLK (5*FOSC)
// Define PCLK as a constant or configuration value used by the firmware.
#define PCLK (CCLK/4)

// RTC Macros
// Define PREINT_VAL as a constant or configuration value used by the firmware.
#define PREINT_VAL ((PCLK/32768)-1)
// Define PREFRAC_VAL as a constant or configuration value used by the firmware.
#define PREFRAC_VAL (PCLK-(PREINT_VAL+1)*32768)

//CCR register bits
// Define RTC_ENABLE as a constant or configuration value used by the firmware.
#define RTC_ENABLE  (1<<0)
// Define RTC_RESET as a constant or configuration value used by the firmware.
#define RTC_RESET   (1<<1)
// Define RTC_CLKSRC as a constant or configuration value used by the firmware.
#define RTC_CLKSRC  (1<<4)

//#define _LPC2148


// End the corresponding include guard or conditional-compilation block.
#endif
