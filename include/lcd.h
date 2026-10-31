//lcd.h

// Include types.h so this file can use its declarations and definitions.
#include"types.h"
// Execute the operation in this statement as part of the current function.
void InitLCD(void);
// Send the specified command to the LCD controller.
void CmdLCD(u8);
// Write the specified character or data byte to the LCD.
void CharLCD(u8);
// Execute the operation in this statement as part of the current function.
void DispLCD(u8);
// Display the specified text string on the LCD.
void StrLCD(u8 *);
// Display the numeric value on the LCD.
void IntLCD(s32);
// Execute the operation in this statement as part of the current function.
void FltLCD(f32);
// Execute the operation in this statement as part of the current function.
void StoreCustCharFont(void);
