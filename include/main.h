//main.h

// Include LPC21xx.h so this file can use its declarations and definitions.
#include<LPC21xx.h>
// Include types.h so this file can use its declarations and definitions.
#include "types.h"
// Include delay.h so this file can use its declarations and definitions.
#include "delay.h"
// Include defines.h so this file can use its declarations and definitions.
#include "defines.h"
// Include lcd_defines.h so this file can use its declarations and definitions.
#include "lcd_defines.h"
// Include lcd.h so this file can use its declarations and definitions.
#include "lcd.h"
// Include rtc_defines.h so this file can use its declarations and definitions.
#include "rtc_defines.h"
// Include rtc.h so this file can use its declarations and definitions.
#include "rtc.h"
// Include uart_defines.h so this file can use its declarations and definitions.
#include "uart_defines.h"
// Include uart.h so this file can use its declarations and definitions.
#include "uart.h"
// Include adc_defines.h so this file can use its declarations and definitions.
#include "adc_defines.h"
// Include adc.h so this file can use its declarations and definitions.
#include "adc.h"
// Include lm35.h so this file can use its declarations and definitions.
#include "lm35.h"
// Include KeyPd_Defines.h so this file can use its declarations and definitions.
#include "KeyPd_Defines.h"
// Include KeyPd.h so this file can use its declarations and definitions.
#include "KeyPd.h"
// Declare variable with the specified type for use by this module.
extern u32 TT;
// Declare variable with the specified type for use by this module.
extern f32 tt;
extern u32 flag;
// Declare variable with the specified type for use by this module.
extern volatile unsigned char rtc_config_requested;
void all_init(void);
void menu_edit_mode(void);
void alert_info(void);
void disp_info(void);
// Execute the operation in this statement as part of the current function.
void Alert_Info_On_LCD(void);
// Execute the operation in this statement as part of the current function.
void Info_On_UART(void);
// Execute the operation in this statement as part of the current function.
void Info_On_LCD(void);
// Execute the operation in this statement as part of the current function.
void ALERT_Info_On_UART(void);
// Execute the operation in this statement as part of the current function.
void __irq EINT1_ISR(void);

// Execute the operation in this statement as part of the current function.
void EINT1_Init(void);
// Execute the operation in this statement as part of the current function.
void MAIN_MENU(void);
// Execute the operation in this statement as part of the current function.
void RTC_MENU(void);

// Execute the operation in this statement as part of the current function.
void Edit_RTC_Info(void);
// Declare variable with the specified type for use by this module.
u8 GetDayFromDate(void);
// Declare variable with the specified type for use by this module.
u32 Num_from_KeyPd(void);
// Execute the operation in this statement as part of the current function.
void EDIT_TT(void);

