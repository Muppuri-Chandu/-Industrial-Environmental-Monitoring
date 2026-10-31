//LCD.c

// Include LPC21xx.h so this file can use its declarations and definitions.
#include<LPC21xx.h>
// Include delay.h so this file can use its declarations and definitions.
#include"delay.h"
// Include lcd_defines.h so this file can use its declarations and definitions.
#include"lcd_defines.h"
// Include types.h so this file can use its declarations and definitions.
#include"types.h"
// Include defines.h so this file can use its declarations and definitions.
#include"defines.h"
// Define the DispLCD function and its parameter list.
void DispLCD(u8 val)
{
        // Drive the selected GPIO output pin(s) low.
        IOCLR0=rw;//clear P0.14--->RW of LCD
        // Read or update the GPIO pin state used by this input/output operation.
        WRITEBYTE(IOPIN0,5,val);//write cmd to P0.5-P0.12
        // Drive the selected GPIO output pin(s) high.
        IOSET0=en;//make (P0.15)En high
        // Wait for the specified delay to allow hardware timing or user-interface settling.
        delay_ms(2);//min. of 450 nsec expected
        // Drive the selected GPIO output pin(s) low.
        IOCLR0=en;//clear P0.15--->EN of LCD
        // Wait for the specified delay to allow hardware timing or user-interface settling.
        delay_ms(5);
}
// Define the CmdLCD function and its parameter list.
void CmdLCD(u8 cmd)
{
        // Drive the selected GPIO output pin(s) low.
        IOCLR0=rs;//clear P0.13-->RS of LCD
        // Execute the operation in this statement as part of the current function.
        DispLCD(cmd);
}
// Define the InitLCD function and its parameter list.
void InitLCD(void)
{
        //P0.5-P0.15--By default GPIO pins
        // Configure GPIO direction bits for the pins used by this peripheral.
        IODIR0|=((LCD_DAT<<5)|(rs)|(rw)|(en));

        // Wait for the specified delay to allow hardware timing or user-interface settling.
        delay_ms(20);//min 15 msec required
        // Send the specified command to the LCD controller.
        CmdLCD(MODE_8BIT_1LINE);//8-bit mode enabling
        // Wait for the specified delay to allow hardware timing or user-interface settling.
        delay_ms(10);//min. of 5 msec
        // Send the specified command to the LCD controller.
        CmdLCD(MODE_8BIT_1LINE);//8-bit mode enabling
        // Wait for the specified delay to allow hardware timing or user-interface settling.
        delay_ms(1);//min. of 160 usec
        // Send the specified command to the LCD controller.
        CmdLCD(MODE_8BIT_1LINE);//8-bit mode enabling
        // Wait for the specified delay to allow hardware timing or user-interface settling.
        delay_ms(1);//min. of 160 usec
        // Send the specified command to the LCD controller.
        CmdLCD(MODE_8BIT_2LINE);//8-bit with 5*7 font 1 lines disp
        // Send the specified command to the LCD controller.
        CmdLCD(SHIFT_DISP_LEFT);//Display off
        // Send the specified command to the LCD controller.
        CmdLCD(CLEAR_LCD);//Clear display
          // Send the specified command to the LCD controller.
          CmdLCD(SHIFT_CUR_RIGHT);//Set cursor move direction
        // Send the specified command to the LCD controller.
        CmdLCD(DSP_ON_CUR_BLINK);//Disp ON ,cursor ON with Blinking
        //CmdLCD(0x0f);//Disp ON ,cursor & Blinking OFF for battery charge
}

// Define the CharLCD function and its parameter list.
void CharLCD(u8 dat)
{
        // Drive the selected GPIO output pin(s) high.
        IOSET0=rs;//SET P0.13-->RS of LCD
        // Execute the operation in this statement as part of the current function.
        DispLCD(dat);
}

// Define the StrLCD function and its parameter list.
void StrLCD(u8 *ptr)
{
        // Repeat the following statement or block while (*ptr!='\0' remains true.
        while(*ptr!='\0')
                // Write the specified character or data byte to the LCD.
                CharLCD(*ptr++);
}
// Define the IntLCD function and its parameter list.
void IntLCD(s32 num)
{
        // Declare variable with the specified type for use by this module.
        u8 a[10];
        // Declare and initialize i with the value or expression shown.
        s8 i=0;
        //itoa
        // Check the condition (num==0; execute the following block only when it is true.
        if(num==0)
                // Write the specified character or data byte to the LCD.
                CharLCD('0');
        // Handle the alternative path when the preceding condition is false.
        else
        {
                // Check the condition (num<0; execute the following block only when it is true.
                if(num<0)
                {
                        // Assign the computed value to num; the expression on the right defines the operation.
                        num=-num;
                        // Write the specified character or data byte to the LCD.
                        CharLCD('-');
                }
                // Repeat the following statement or block while (num>0 remains true.
                while(num>0)
                {
                        // Assign the computed value to a[i++]; the expression on the right defines the operation.
                        a[i++]=num%10+48;
                        // Assign the computed value to num; the expression on the right defines the operation.
                        num=num/10;
                }
                // Iterate over the range specified by the loop initializer, condition, and update expression.
                for(--i;i>=0;i--)
                        // Write the specified character or data byte to the LCD.
                        CharLCD(a[i]);
        }
}
// Define the FltLCD function and its parameter list.
void FltLCD(f32 val)
{
        // Declare variable with the specified type for use by this module.
        u32 num,i;
        // Check the condition (val<0; execute the following block only when it is true.
        if(val<0)
        {
                // Write the specified character or data byte to the LCD.
                CharLCD('-');
                // Assign the computed value to val; the expression on the right defines the operation.
                val=-val;
        }
        // Assign the computed value to num; the expression on the right defines the operation.
        num=val;
        // Display the numeric value on the LCD.
        IntLCD(num);
        // Write the specified character or data byte to the LCD.
        CharLCD('.');
        // Iterate over the range specified by the loop initializer, condition, and update expression.
        for(i=0;i<6;i++)
        {
                // Assign the computed value to val; the expression on the right defines the operation.
                val=(val-num)*10;
                // Assign the computed value to num; the expression on the right defines the operation.
                num=val;
                // Write the specified character or data byte to the LCD.
                CharLCD(num+48);
        }
}

//degree symbol
// Define the StoreCustCharFont function and its parameter list.
void StoreCustCharFont(void)
{
        // Declare and initialize LUT with the value or expression shown.
        u8 i,LUT[]={0x07,0x09,0x07,0x00,0x00,0x00,0x00,0x00};
        // Iterate over the range specified by the loop initializer, condition, and update expression.
        for(i=0;i<8;i++)
                // Write the specified character or data byte to the LCD.
                CharLCD(LUT[i]);

}
