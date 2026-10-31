//Pin_connect.c
// Include LPC21xx.h so this file can use its declarations and definitions.
#include<LPC21xx.h>


// Define the CfgPinFunc function and its parameter list.
void CfgPinFunc(int PortNo,int PinNo,int Func)

{

	// Check the condition (PortNo==0; execute the following block only when it is true.
	if(PortNo==0)

	{

		// Check the condition (PinNo<16; execute the following block only when it is true.
		if(PinNo<16)

			// Configure the LPC2148 pin-function selection register while preserving unrelated pin settings where the expression uses a mask.
			PINSEL0=((PINSEL0&~(3<<(PinNo*2)))|(Func<<(PinNo*2)));

		// Handle the alternative path when the preceding condition is false.
		else

			// Configure the LPC2148 pin-function selection register while preserving unrelated pin settings where the expression uses a mask.
			PINSEL1=((PINSEL1&~(3<<((PinNo-16)*2)))|(Func<<((PinNo-16)*2)));

	}


}
