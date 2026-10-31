//lcd_defines1.h

//HD44780 COMMANDS

// Define CLEAR_LCD as a constant or configuration value used by the firmware.
#define CLEAR_LCD 0X01
// Define RET_CUR_HOME as a constant or configuration value used by the firmware.
#define RET_CUR_HOME 0X02
// Define SHIFT_CUR_RIGHT as a constant or configuration value used by the firmware.
#define SHIFT_CUR_RIGHT 0X06
// Define SHIFT_CUR_LEFT as a constant or configuration value used by the firmware.
#define SHIFT_CUR_LEFT  0X07
// Define DSP_OFF as a constant or configuration value used by the firmware.
#define DSP_OFF 0X08
// Define DSP_ON_CUR_OFF as a constant or configuration value used by the firmware.
#define DSP_ON_CUR_OFF 0X0C
// Define DSP_ON_CUR_ON as a constant or configuration value used by the firmware.
#define DSP_ON_CUR_ON 0X0E
// Define DSP_ON_CUR_BLINK as a constant or configuration value used by the firmware.
#define DSP_ON_CUR_BLINK 0X0F
// Define SHIFT_DISP_LEFT as a constant or configuration value used by the firmware.
#define SHIFT_DISP_LEFT 0X10
// Define SHIFT_DISP_RIGHT as a constant or configuration value used by the firmware.
#define SHIFT_DISP_RIGHT 0X14
// Define MODE_8BIT_1LINE as a constant or configuration value used by the firmware.
#define MODE_8BIT_1LINE 0X30
// Define MODE_4BIT_1LINE as a constant or configuration value used by the firmware.
#define MODE_4BIT_1LINE 0X20
// Define MODE_8BIT_2LINE as a constant or configuration value used by the firmware.
#define MODE_8BIT_2LINE 0X38
// Define MODE_4BIT_2LINE as a constant or configuration value used by the firmware.
#define MODE_4BIT_2LINE 0X28
// Define GOTO_LINE1_POS0 as a constant or configuration value used by the firmware.
#define GOTO_LINE1_POS0 0X80
// Define GOTO_LINE1_POS11 as a constant or configuration value used by the firmware.
#define GOTO_LINE1_POS11 0X8B
// Define GOTO_LINE1_POS13 as a constant or configuration value used by the firmware.
#define GOTO_LINE1_POS13 0X8D
// Define GOTO_LINE1_POS14 as a constant or configuration value used by the firmware.
#define GOTO_LINE1_POS14 0X8E
// Define GOTO_LINE2_POS0 as a constant or configuration value used by the firmware.
#define GOTO_LINE2_POS0 0XC0
// Define GOTO_LINE2_POS12 as a constant or configuration value used by the firmware.
#define GOTO_LINE2_POS12 0XCC
// Define GOTO_LINE3_POS0 as a constant or configuration value used by the firmware.
#define GOTO_LINE3_POS0 0X94
// Define GOTO_LINE4_POS0 as a constant or configuration value used by the firmware.
#define GOTO_LINE4_POS0 0XD4
// Define GOTO_CGRAM_START as a constant or configuration value used by the firmware.
#define GOTO_CGRAM_START 0X40

// Define LCD_DAT as a constant or configuration value used by the firmware.
#define LCD_DAT 0xff//data lines --P0.5-P0.12
// Define RS as a constant or configuration value used by the firmware.
#define RS 13 //P0.13
// Define EN as a constant or configuration value used by the firmware.
#define EN 14 //P0.14
// Define RW as a constant or configuration value used by the firmware.
#define RW 15 //P0.15


// Define rs as a constant or configuration value used by the firmware.
#define rs 1<<RS
// Define en as a constant or configuration value used by the firmware.
#define en 1<<EN
// Define rw as a constant or configuration value used by the firmware.
#define rw 1<<RW
