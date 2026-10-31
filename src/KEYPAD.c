//KeyPd.c
// Include LPC21xx.h so this file can use its declarations and definitions.
#include<LPC21xx.h>
// Include KeyPd_Defines.h so this file can use its declarations and definitions.
#include"KeyPd_Defines.h"
// Include types.h so this file can use its declarations and definitions.
#include"types.h"

// Declare and initialize variable with the value or expression shown.
u8 LUT[][4]={1,2,3,'A',
             // This line contributes to the declaration or expression shown below.
             4,5,6,'B',
			 // This line contributes to the declaration or expression shown below.
			       7,8,9,'C',
			 // Execute the operation in this statement as part of the current function.
			       '*',0,'#','D'};

// Define the KeyPdInit function and its parameter list.
void KeyPdInit(void)
{
                // Configure GPIO direction bits for the pins used by this peripheral.
                IODIR1|=((1<<R0)|(1<<R1)|(1<<R2)|(1<<R3));
            //P1.16-P1.19 are for output functionality
                // Drive the selected GPIO output pin(s) low.
                IOCLR1=((1<<R0)|(1<<R1)|(1<<R2)|(1<<R3));
                //Initializing rows to 0

}
// Define the ColStat function and its parameter list.
u8 ColStat(void)
{
        // Check the condition ((((IOPIN1>>20)&0x0f)==0x0f; execute the following block only when it is true.
        if((((IOPIN1>>20)&0x0f)==0x0f))
                // Return 1 from this function.
                return 1;
        // Handle the alternative path when the preceding condition is false.
        else
                // Return 0 from this function.
                return 0;
}
// Define the KeyVal function and its parameter list.
u8 KeyVal(void)
{
                // Declare and initialize row_val with the value or expression shown.
                char row_val=0,col_val=0;
                // Drive the selected GPIO output pin(s) low.
                IOCLR1=(1<<R0);
                // Drive the selected GPIO output pin(s) high.
                IOSET1=((1<<R1)|(1<<R2)|(1<<R3));
                // Check the condition ((((IOPIN1>>20)&0x0f)!=0x0f; execute the following block only when it is true.
                if((((IOPIN1>>20)&0x0f)!=0x0f))
                {
                        // Assign the computed value to row_val; the expression on the right defines the operation.
                        row_val=0;
                        // Jump to label colcheck for the existing retry flow.
                        goto colcheck;
                }
                // Drive the selected GPIO output pin(s) low.
                IOCLR1=(1<<R1);
                // Drive the selected GPIO output pin(s) high.
                IOSET1=((1<<R0)|(1<<R2)|(1<<R3));
                // Check the condition ((((IOPIN1>>20)&0x0f)!=0x0f; execute the following block only when it is true.
                if((((IOPIN1>>20)&0x0f)!=0x0f))
                {
                        // Assign the computed value to row_val; the expression on the right defines the operation.
                        row_val=1;
                        // Jump to label colcheck for the existing retry flow.
                        goto colcheck;
                }
                // Drive the selected GPIO output pin(s) low.
                IOCLR1=(1<<R2);
                // Drive the selected GPIO output pin(s) high.
                IOSET1=((1<<R0)|(1<<R1)|(1<<R3));
                // Check the condition ((((IOPIN1>>20)&0x0f)!=0x0f; execute the following block only when it is true.
                if((((IOPIN1>>20)&0x0f)!=0x0f))
                {
                        // Assign the computed value to row_val; the expression on the right defines the operation.
                        row_val=2;
                        // Jump to label colcheck for the existing retry flow.
                        goto colcheck;
                }
                // Drive the selected GPIO output pin(s) low.
                IOCLR1=(1<<R3);
                // Drive the selected GPIO output pin(s) high.
                IOSET1=((1<<R0)|(1<<R1)|(1<<R2));
                // Check the condition ((((IOPIN1>>20)&0x0f)!=0x0f; execute the following block only when it is true.
                if((((IOPIN1>>20)&0x0f)!=0x0f))
                        // Assign the computed value to row_val; the expression on the right defines the operation.
                        row_val=3;
                // Define label colcheck as a destination for the related goto statement.
                colcheck:
                // Check the condition (((IOPIN1>>C0)&1)==0; execute the following block only when it is true.
                if(((IOPIN1>>C0)&1)==0)
                        // Assign the computed value to col_val; the expression on the right defines the operation.
                        col_val=0;
                // Check this alternative condition when the preceding condition was false.
                else if(((IOPIN1>>C1)&1)==0)
                        // Assign the computed value to col_val; the expression on the right defines the operation.
                        col_val=1;
                // Check this alternative condition when the preceding condition was false.
                else if(((IOPIN1>>C2)&1)==0)
                        // Assign the computed value to col_val; the expression on the right defines the operation.
                        col_val=2;
                // Handle the alternative path when the preceding condition is false.
                else
                        // Assign the computed value to col_val; the expression on the right defines the operation.
                        col_val=3;

                // Drive the selected GPIO output pin(s) low.
                IOCLR1=((1<<R0)|(1<<R1)|(1<<R2)|(1<<R3));
        //Initializing rows to 0

                // Return (LUT[row_val][col_val]) from this function.
                return(LUT[row_val][col_val]);

}
