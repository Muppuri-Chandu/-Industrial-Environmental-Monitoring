//UART.c

// Include LPC21xx.h so this file can use its declarations and definitions.
#include<LPC21xx.h>
// Include defines.h so this file can use its declarations and definitions.
#include"defines.h"
// Include uart_defines.h so this file can use its declarations and definitions.
#include "uart_defines.h"
// Include Pin_connect.h so this file can use its declarations and definitions.
#include"Pin_connect.h"
// Include types.h so this file can use its declarations and definitions.
#include"types.h"
// Define the InitUART function and its parameter list.
void InitUART(void)
{
        //PINSEL0|=0x00000001;
        //CfgPinFunc(0,0,1);//P0.0 for TXD0
        //CfgPinFunc(0,1,1);//P0.1 for RXD0
		// Configure the LPC2148 pin-function selection register while preserving unrelated pin settings where the expression uses a mask.
		PINSEL0&=~((3<<2)|(3<<0));

	 	// Configure the LPC2148 pin-function selection register while preserving unrelated pin settings where the expression uses a mask.
	 	PINSEL0|=TXD0_PIN|RXD0_PIN;
        // This line contributes to the declaration or expression shown below.
        U0LCR=0x03;//8-bit wordlength with1 stop bit
        // This line contributes to the declaration or expression shown below.
        U0LCR|=((1<<DLAB_BIT) |(_8BIT<<WORD_LEN_SEL_BITS));;//DLAB=1
        // Assign the computed value to U0DLL; the expression on the right defines the operation.
        U0DLL=DIVISOR;
        // Assign the computed value to U0DLM; the expression on the right defines the operation.
        U0DLM=DIVISOR>>8;
        // This line contributes to the declaration or expression shown below.
        U0LCR&=~(1<<DLAB_BIT);//DLAB=0

}
// Define the UARTRxChar function and its parameter list.
s8 UARTRxChar(void)
{
                // Repeat the following statement or block while (!READBIT(U0LSR,DR_BIT)); remains true.
                while(!READBIT(U0LSR,DR_BIT));
                // Return (U0RBR) from this function.
                return (U0RBR);

}
// Define the UARTTxChar function and its parameter list.
void UARTTxChar(s8 ch)
{
        // Assign the computed value to U0THR; the expression on the right defines the operation.
        U0THR=ch;
        // Repeat the following statement or block while (!READBIT(U0LSR,TEMT_BIT)); remains true.
        while(!READBIT(U0LSR,TEMT_BIT));
}
// Define the UARTTxStr function and its parameter list.
void UARTTxStr(s8 *ptr)
{
        // Repeat the following statement or block while (*ptr remains true.
        while(*ptr)
                // Transmit one character over UART.
                UARTTxChar(*ptr++);
}

// Define the UARTTxU32 function and its parameter list.
void UARTTxU32(u32 num)
{
        // Declare variable with the specified type for use by this module.
        u8 a[10];
        // Declare and initialize i with the value or expression shown.
        s8 i=0;
        //itoa
        // Check the condition (num==0; execute the following block only when it is true.
        if(num==0)
                // Transmit one character over UART.
                UARTTxChar('0');
        // Handle the alternative path when the preceding condition is false.
        else
        {
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
                        // Transmit one character over UART.
                        UARTTxChar(a[i]);
        }
}
// Define the UARTTxF32 function and its parameter list.
void UARTTxF32(f32 fnum)
{
        // Declare variable with the specified type for use by this module.
        u32 num,i;
        // Check the condition (fnum<0; execute the following block only when it is true.
        if(fnum<0)
        {
                // Transmit one character over UART.
                UARTTxChar('-');
                // Assign the computed value to fnum; the expression on the right defines the operation.
                fnum=-fnum;
        }
        // Assign the computed value to num; the expression on the right defines the operation.
        num=fnum;
        // Execute the operation in this statement as part of the current function.
        UARTTxU32(num);
        // Transmit one character over UART.
        UARTTxChar('.');
        // Iterate over the range specified by the loop initializer, condition, and update expression.
        for(i=0;i<2;i++)
        {
                // Assign the computed value to fnum; the expression on the right defines the operation.
                fnum=(fnum-num)*10;
                // Assign the computed value to num; the expression on the right defines the operation.
                num=fnum;
                // Transmit one character over UART.
                UARTTxChar(num+48);
        }
}
// Define the UARTTx_SendRTC function and its parameter list.
void UARTTx_SendRTC(void)
{
	// Read or update the LPC2148 RTC register identified in this expression.
	UARTTxChar((DOM/10)+48);
    // Read or update the LPC2148 RTC register identified in this expression.
    UARTTxChar((DOM%10)+48);
	// Transmit one character over UART.
	UARTTxChar('/');
    // Read or update the LPC2148 RTC register identified in this expression.
    UARTTxChar((MONTH/10)+48);
	// Read or update the LPC2148 RTC register identified in this expression.
	UARTTxChar((MONTH%10)+48);
    // Transmit one character over UART.
    UARTTxChar('/');

    // Read or update the LPC2148 RTC register identified in this expression.
    UARTTxChar((YEAR/1000)%10 + '0');
    // Read or update the LPC2148 RTC register identified in this expression.
    UARTTxChar((YEAR/100)%10 + '0');
    // Read or update the LPC2148 RTC register identified in this expression.
    UARTTxChar((YEAR/10)%10 + '0');
    // Read or update the LPC2148 RTC register identified in this expression.
    UARTTxChar(YEAR%10 + '0');
	// Transmit the specified text message over UART.
	UARTTxStr("    ");

    // Read or update the LPC2148 RTC register identified in this expression.
    UARTTxChar((HOUR/10)+48);
	// Read or update the LPC2148 RTC register identified in this expression.
	UARTTxChar((HOUR%10)+48);
    // Transmit one character over UART.
    UARTTxChar(':');
    // Read or update the LPC2148 RTC register identified in this expression.
    UARTTxChar((MIN/10)+48);
	// Read or update the LPC2148 RTC register identified in this expression.
	UARTTxChar((MIN%10)+48);
    // Transmit one character over UART.
    UARTTxChar(':');
    // Read or update the LPC2148 RTC register identified in this expression.
    UARTTxChar((SEC/10)+48);
	// Read or update the LPC2148 RTC register identified in this expression.
	UARTTxChar((SEC%10)+48);
   

   

    
}


