//KeyPd_Defines.h
// Include LPC21xx.h so this file can use its declarations and definitions.
#include<LPC21xx.h>
// Include types.h so this file can use its declarations and definitions.
#include"types.h"
// Define R0 as a constant or configuration value used by the firmware.
#define R0 16//p1.16
// Define R1 as a constant or configuration value used by the firmware.
#define R1 17
// Define R2 as a constant or configuration value used by the firmware.
#define R2 18
// Define R3 as a constant or configuration value used by the firmware.
#define R3 19
// Define C0 as a constant or configuration value used by the firmware.
#define C0 20
// Define C1 as a constant or configuration value used by the firmware.
#define C1 21
// Define C2 as a constant or configuration value used by the firmware.
#define C2 22
// Define C3 as a constant or configuration value used by the firmware.
#define C3 23//p1.23

// Declare variable with the specified type for use by this module.
extern u8 rtc_menu[8][15];
