//MAIN.c

// Include main.h so this file can use its declarations and definitions.
#include "main.h"

//Threshold Temparature SET to 35C 
u32 TT=35;

// temporary variable to hold current temparature
f32 tt;


// Declare and initialize rtc_config_requested with the value or expression shown.
volatile unsigned char rtc_config_requested = 0;

// Define the main function and its parameter list.


int main()
{
    
    // Configure GPIO direction bits for the pins used by this peripheral.
    SETBIT(IODIR0,BUZZER); //BUZZER as Output direction
		// Drive the selected GPIO output pin(s) low.
		SETBIT(IOCLR0,BUZZER);

    all_init();

    // Set the initial time (hours, minutes, seconds)
    SetRTCTimeInfo(15,37,00);
    SetRTCDateInfo(29,10,2026);      
		SetRTCDay(4);

		//UARTTxStr("Temparature   Time    Date\t");
		CmdLCD(DSP_ON_CUR_OFF);
	
	
    // Repeat this loop continuously while the embedded application is running.
    while(1)
    {
				// Read the LM35 temperature sensor and use the returned temperature value.
				tt=Read_LM35('C');
       //if tt TEMPERATURE is >35C

       // Check the condition (tt>TT; execute the following block only when it is true.
       if(tt>TT)
       // Send the specified command to the LCD controller.
       {  
						alert_info();
			 }

       //if SWITCH is pressed
       // Check this alternative condition when the preceding condition was false.
       else if(rtc_config_requested)//SW press
       {         	 
          	menu_edit_mode();
          
       }
         //During NORMAL OPERATION
         // Check this alternative condition when the preceding condition was false.
        else if(flag==0)
        {
            disp_info();   
        }
     }
}
          
