//uart.h

// Include types.h so this file can use its declarations and definitions.
#include"types.h"
// Execute the operation in this statement as part of the current function.
void InitUART(void);
// Transmit one character over UART.
void UARTTxChar(s8);
// Transmit the specified text message over UART.
void UARTTxStr(s8 *);
// Declare variable with the specified type for use by this module.
s8 UARTRxChar(void);
// Execute the operation in this statement as part of the current function.
void UARTTxU32(u32);
// Transmit the floating-point value over UART using the module's formatting routine.
void UARTTxF32(f32);
// Transmit the current RTC date and time over UART.
void UARTTx_SendRTC(void);

