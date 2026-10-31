//rtc.c
// Include LPC21xx.H so this file can use its declarations and definitions.
#include <LPC21xx.H>

// Include rtc_defines.h so this file can use its declarations and definitions.
#include "rtc_defines.h"
// Include types.h so this file can use its declarations and definitions.
#include "types.h"
// Include lcd.h so this file can use its declarations and definitions.
#include "lcd.h"
// Include lcd_defines.h so this file can use its declarations and definitions.
#include "lcd_defines.h"
// Include lm35.h so this file can use its declarations and definitions.
#include "lm35.h"

// Declare variable with the specified type for use by this module.
extern f32 Temp;

// Array to hold names of days of the week
// Declare and initialize variable with the value or expression shown.
u8 week[][4] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
//extern char week[][4];

/*
// This line contributes to the declaration or expression shown below.
Initialize the Real-Time Clock (RTC)
// This line contributes to the declaration or expression shown below.
This function disables the RTC, sets the prescaler values,
// This line contributes to the declaration or expression shown below.
and then enables the RTC.
*/
// Define the RTC_Init function and its parameter list.
void RTC_Init(void)
{
	
  // Disable and reset the RTC
      //  CCR = RTC_RESET;
		// Read or update the LPC2148 RTC register identified in this expression.
		CCR=RTC_CLKSRC;

  // Set prescaler integer and fractional parts
      //  PREINT = PREINT_VAL;
        //PREFRAC= PREFRAC_VAL;

  // Enable the RTC
        // Read or update the LPC2148 RTC register identified in this expression.
        CCR = RTC_CLKSRC|RTC_ENABLE;
				// CCR = RTC_ENABLE;



}

/*
// This line contributes to the declaration or expression shown below.
Get the current RTC time
// This line contributes to the declaration or expression shown below.
hour Pointer to store the current hour
// This line contributes to the declaration or expression shown below.
minute Pointer to store the current minute
// This line contributes to the declaration or expression shown below.
second Pointer to store the current second
*/
// Define the GetRTCTimeInfo function and its parameter list.
void GetRTCTimeInfo(s32 *hour, s32 *minute, s32 *second)
{
        *hour = HOUR;
        *minute = MIN;
        *second = SEC;
}

/*
// This line contributes to the declaration or expression shown below.
Display the RTC time on LCD
// This line contributes to the declaration or expression shown below.
hour value (0 23)
// This line contributes to the declaration or expression shown below.
minute value (0 59)
// This line contributes to the declaration or expression shown below.
second value (0 59) seperated by ':'
*/
// Define the DisplayRTCTime function and its parameter list.
void DisplayRTCTime(u32 hour, u32 minute, u32 second)
{
                // Send the specified command to the LCD controller.
                CmdLCD(GOTO_LINE1_POS0);
                // Write the specified character or data byte to the LCD.
                CharLCD((hour/10)+48);
                // Write the specified character or data byte to the LCD.
                CharLCD((hour%10)+48);
                // Write the specified character or data byte to the LCD.
                CharLCD(':');
                // Write the specified character or data byte to the LCD.
                CharLCD((minute/10)+48);
                // Write the specified character or data byte to the LCD.
                CharLCD((minute%10)+48);
                // Write the specified character or data byte to the LCD.
                CharLCD(':');
                // Write the specified character or data byte to the LCD.
                CharLCD((second/10)+48);
                // Write the specified character or data byte to the LCD.
                CharLCD((second%10)+48);

}

/*
// This line contributes to the declaration or expression shown below.
Get the current RTC date
// This line contributes to the declaration or expression shown below.
day Pointer to store the current date (1 31)
// This line contributes to the declaration or expression shown below.
month Pointer to store the current month (1 12)
// This line contributes to the declaration or expression shown below.
year Pointer to store the current year (four digits)
*/
// Define the GetRTCDateInfo function and its parameter list.
void GetRTCDateInfo(s32 *date, s32 *month, s32 *year)
{
        *date = DOM;
        *month = MONTH;
        *year = YEAR;
}

/*
// This line contributes to the declaration or expression shown below.
Display the RTC date on LCD
// This line contributes to the declaration or expression shown below.
Day of month (1 31)
// This line contributes to the declaration or expression shown below.
Month (1 12)
// This line contributes to the declaration or expression shown below.
Year (four digits) and seperated by '/'
*/

// Define the DisplayRTCDate function and its parameter list.
void DisplayRTCDate(u32 date, u32 month, u32 year)
{
                // Send the specified command to the LCD controller.
                CmdLCD(GOTO_LINE2_POS0);
                // Write the specified character or data byte to the LCD.
                CharLCD((date/10)+48);
                // Write the specified character or data byte to the LCD.
                CharLCD((date%10)+48);
                // Write the specified character or data byte to the LCD.
                CharLCD('/');
                // Write the specified character or data byte to the LCD.
                CharLCD((month/10)+48);
                // Write the specified character or data byte to the LCD.
                CharLCD((month%10)+48);
                // Write the specified character or data byte to the LCD.
                CharLCD('/');
                // Display the numeric value on the LCD.
                IntLCD(year);
}
/*
// This line contributes to the declaration or expression shown below.
Set the RTC time
// This line contributes to the declaration or expression shown below.
Hour to set (0 23)
// This line contributes to the declaration or expression shown below.
Minute to set (0 59)
// This line contributes to the declaration or expression shown below.
Second to set (0 59)
*/
// Define the SetRTCTimeInfo function and its parameter list.
void SetRTCTimeInfo(u32 hour, u32 minute, u32 second)
{
        // Read or update the LPC2148 RTC register identified in this expression.
        HOUR = hour;
        // Read or update the LPC2148 RTC register identified in this expression.
        MIN = minute;
        // Read or update the LPC2148 RTC register identified in this expression.
        SEC = second;
}

/*
// This line contributes to the declaration or expression shown below.
Set the RTC date
// This line contributes to the declaration or expression shown below.
day of month to set (1 31)
// This line contributes to the declaration or expression shown below.
month to set (1 12)
// This line contributes to the declaration or expression shown below.
year to set (four digits)
*/
// Define the SetRTCDateInfo function and its parameter list.
void SetRTCDateInfo(u32 date, u32 month, u32 year)
{
        // Read or update the LPC2148 RTC register identified in this expression.
        DOM = date;
        // Read or update the LPC2148 RTC register identified in this expression.
        MONTH = month;
        // Read or update the LPC2148 RTC register identified in this expression.
        YEAR = year;
}

/*
// This line contributes to the declaration or expression shown below.
Get the current day of the week
// This line contributes to the declaration or expression shown below.
dow Pointer to store Day of Week (0=Sunday, ..., 6=Saturday)
*/
// Define the GetRTCDay function and its parameter list.
void GetRTCDay(s32 *day)
{
        *day = DOW;
}

/*
// This line contributes to the declaration or expression shown below.
Display the current day of the week on LCD
// This line contributes to the declaration or expression shown below.
dow (Day of Week) (0=Sunday, ..., 6=Saturday)
*/
// Define the DisplayRTCDay function and its parameter list.
void DisplayRTCDay(u32 dow)
{
        // Send the specified command to the LCD controller.
        CmdLCD(GOTO_LINE2_POS12);
        // Display the specified text string on the LCD.
        StrLCD(week[dow]);
}

/*
// This line contributes to the declaration or expression shown below.
Set the day of the week in RTC
// This line contributes to the declaration or expression shown below.
Day of Week to set (0=Sunday, ..., 6=Saturday)
*/
// Define the SetRTCDay function and its parameter list.
void SetRTCDay(u32 day)
{
        // Read or update the LPC2148 RTC register identified in this expression.
        DOW = day;
}

//Temperature info

// Define the DisplayTemp function and its parameter list.
void DisplayTemp(void)
{
        // Send the specified command to the LCD controller.
        CmdLCD(GOTO_LINE1_POS11);
        // Display the numeric value on the LCD.
        IntLCD(Read_LM35('C'));
        // Send the specified command to the LCD controller.
        CmdLCD(0x48);//Cursor is placed at CGRAM loc
        // Execute the operation in this statement as part of the current function.
        StoreCustCharFont();
        // Send the specified command to the LCD controller.
        CmdLCD(GOTO_LINE1_POS13);
        // Write the specified character or data byte to the LCD.
        CharLCD(1);//font is read from 8*1+0x40 loc
        // Send the specified command to the LCD controller.
        CmdLCD(GOTO_LINE1_POS14);
        // Write the specified character or data byte to the LCD.
        CharLCD('C');
}
