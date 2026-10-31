//main_defintion.c

// Include main.h so this file can use its declarations and definitions.
#include "main.h"
// Declare variable with the specified type for use by this module.
		s32 hour,min,sec,date,month,year,day;
// Declare and initialize flag with the value or expression shown.
    u32 flag=0;
// Declare variable with the specified type for use by this module.
		f32 Temp;
// Declare variable with the specified type for use by this module.
		u8 key;
void all_init(void)
{
	// Initialize RTC 
    // Execute the operation in this statement as part of the current function.
    RTC_Init();	
																										
    // Initialize the LCD
    // Execute the operation in this statement as part of the current function.
    InitLCD();

    //Initialize UART
    // Execute the operation in this statement as part of the current function.
    InitUART();

    // Initialize ADC 
    // Execute the operation in this statement as part of the current function.
    Init_ADC(CH1);

    // Initialize KPM 
    // Execute the operation in this statement as part of the current function.
    KeyPdInit();				  
	// Execute the operation in this statement as part of the current function.
	EINT1_Init();
}

void alert_info(void)
{
					CmdLCD(CLEAR_LCD);
					// Drive the selected GPIO output pin(s) high.
					SETBIT(IOSET0,BUZZER);																																																																																																																																																																											  
          // Execute the operation in this statement as part of the current function.
          Alert_Info_On_LCD();
          // Execute the operation in this statement as part of the current function.
          ALERT_Info_On_UART();
					// Wait for the specified delay to allow hardware timing or user-interface settling.
					delay_ms(500);
					// Send the specified command to the LCD controller.
					CmdLCD(CLEAR_LCD);
}

void disp_info(void)
{
						// Drive the selected GPIO output pin(s) low.
            SETBIT(IOCLR0,BUZZER);
						//CmdLCD(CLEAR_LCD);
            // Get and display the current time on LCD
            // Execute the operation in this statement as part of the current function.
            Info_On_LCD(); 
						// Execute the operation in this statement as part of the current function.
						Info_On_UART();
}
void menu_edit_mode(void)
{
		// Assign the computed value to flag; the expression on the right defines the operation.
          flag=1;
					// Transmit the specified text message over UART.
					UARTTxStr(" ***Main Menu Mode Activated***\n\r");
          		  
					// Repeat the following statement or block while (flag remains true.
					while(flag)
          {
						
							//       u8 key;
							// Execute the operation in this statement as part of the current function.
							MAIN_MENU();
              // Repeat the following statement or block while (ColStat()); //wait for sw press remains true.
              while(ColStat()); //wait for sw press
              // Wait for the specified delay to allow hardware timing or user-interface settling.
              delay_ms(10);     //for avoiding keybouncing time.
              // Read the key currently pressed on the matrix keypad.
              key=KeyVal();
              // Repeat the following statement or block while (!ColStat());//wait for sw release remains true.
              while(!ColStat());//wait for sw release

								// Send the specified command to the LCD controller.
								CmdLCD(CLEAR_LCD);
							// Display the numeric value on the LCD.
							IntLCD(key);
							// Wait for the specified delay to allow hardware timing or user-interface settling.
							delay_ms(500);
              // Check the condition (key==1; execute the following block only when it is true.
              if(key==1)
              {
                  // Transmit the specified text message over UART.
                  UARTTxStr(" ***Time Editing Mode Activated***\n\r");
                  // This line contributes to the declaration or expression shown below.
                  RTC_MENU();        // show RTC menu
                  // Execute the operation in this statement as part of the current function.
                  Edit_RTC_Info();
                  //MAIN_MENU();        // show main menu
               }
               // Check this alternative condition when the preceding condition was false.
               else if(key==2)
               {
                   // Transmit the specified text message over UART.
                   UARTTxStr(" ***Threshold Temp Editing Mode Activated***\n\r");
                   // Execute the operation in this statement as part of the current function.
                   EDIT_TT();
                   //MAIN_MENU();        // show main menu
                }
                // Check this alternative condition when the preceding condition was false.
                else if(key==3)
                {
                   // Assign the computed value to flag; the expression on the right defines the operation.
                   flag=0;
										// Assign the computed value to rtc_config_requested; the expression on the right defines the operation.
										rtc_config_requested=0;
                   // Transmit the specified text message over UART.
                   UARTTxStr(" ***Exit From Editing Mode***\n\r");
                   // Send the specified command to the LCD controller.
                   CmdLCD(CLEAR_LCD);
                   // Wait for the specified delay to allow hardware timing or user-interface settling.
                   delay_ms(10);
                 }
						}
       
}
// Define the EINT1_ISR function and its parameter list.
void __irq EINT1_ISR(void)
{
	// Clear the external-interrupt flag by writing the corresponding bit to the interrupt register.
	EXTINT = (1U<<1);     //Clear EINT0 interrupt flag

	// Assign the computed value to rtc_config_requested; the expression on the right defines the operation.
	rtc_config_requested = 1 ;

	// Configure the Vectored Interrupt Controller for the external interrupt handler.
	VICVectAddr = 0;   //Signal end of interrupt

}

// Define the EINT1_Init function and its parameter list.
void EINT1_Init(void)
{
	// Configure the LPC2148 pin-function selection register while preserving unrelated pin settings where the expression uses a mask.
	PINSEL0 &= ~(3U<<6);
	// Configure the LPC2148 pin-function selection register while preserving unrelated pin settings where the expression uses a mask.
	PINSEL0 |= 0x000000C0;

	// Assign the computed value to EXTMODE |; the expression on the right defines the operation.
	EXTMODE |= (1U<<1);

	// Assign the computed value to EXTPOLAR &; the expression on the right defines the operation.
	EXTPOLAR &= ~(1U<<1);

	// Clear the external-interrupt flag by writing the corresponding bit to the interrupt register.
	EXTINT = (1U<<1);

	// Configure the Vectored Interrupt Controller for the external interrupt handler.
	VICIntSelect &= ~(1U<<EINT1_VIC_CHNO);

	// Configure the Vectored Interrupt Controller for the external interrupt handler.
	VICVectAddr1 = (u32)EINT1_ISR;


	// Configure the Vectored Interrupt Controller for the external interrupt handler.
	VICVectCntl1 = (1U<<5)|EINT1_VIC_CHNO;

	// Configure the Vectored Interrupt Controller for the external interrupt handler.
	VICIntEnable = (1U<<EINT1_VIC_CHNO);	
}

// Define the Alert_Info_On_LCD function and its parameter list.
void Alert_Info_On_LCD(void)
{
	// Send the specified command to the LCD controller.
	CmdLCD(GOTO_LINE1_POS0);
	// Display the specified text string on the LCD.
	StrLCD("-Over Temp!");
	// Send the specified command to the LCD controller.
	CmdLCD(GOTO_LINE2_POS0);
	// Display the numeric value on the LCD.
	IntLCD(Read_LM35('C'));
	// Display the specified text string on the LCD.
	StrLCD("  >  ");
	// Display the numeric value on the LCD.
	IntLCD(tt);
	
	
}
// Define the ALERT_Info_On_UART function and its parameter list.
void ALERT_Info_On_UART(void)
{
        {
        // Transmit the specified text message over UART.
        UARTTxStr("Temp: ");
        // Transmit the floating-point value over UART using the module's formatting routine.
        UARTTxF32(tt);
		// Transmit one character over UART.
		UARTTxChar(223);
        // Transmit one character over UART.
        UARTTxStr("C @");
        // Transmit the current RTC date and time over UART.
        UARTTx_SendRTC();
        // Transmit the specified text message over UART.
        UARTTxStr(" -OVER TEMP!\r\n");
        }
}

// Define the Info_On_LCD function and its parameter list.
void Info_On_LCD(void)
{
        // Get and display the current time on LCD
				
                // Execute the operation in this statement as part of the current function.
                GetRTCTimeInfo(&hour,&min,&sec);
                // Execute the operation in this statement as part of the current function.
                DisplayRTCTime(hour,min,sec);
                // Execute the operation in this statement as part of the current function.
                DisplayTemp();
                // Execute the operation in this statement as part of the current function.
                GetRTCDateInfo(&date,&month,&year);
                // Execute the operation in this statement as part of the current function.
                DisplayRTCDate(date,month,year);
                // Execute the operation in this statement as part of the current function.
                GetRTCDay(&day);
                // Execute the operation in this statement as part of the current function.
                DisplayRTCDay(day);
}
// Define the Info_On_UART function and its parameter list.
void Info_On_UART(void)
// Read or update the LPC2148 RTC register identified in this expression.
{		 if(SEC==59){
        // Wait for the specified delay to allow hardware timing or user-interface settling.
        delay_ms(1000);
		//Date     Time    Temparature
        //15/10/2026    19:30:11    29.032923�C
		// Transmit the current RTC date and time over UART.
		UARTTx_SendRTC();
		// Transmit the specified text message over UART.
		UARTTxStr("     ");		
        // Transmit the floating-point value over UART using the module's formatting routine.
        UARTTxF32(Read_LM35('C'));
		// Transmit one character over UART.
		UARTTxChar(223);
		// Transmit one character over UART.
		UARTTxChar('C');	
        // Transmit the specified text message over UART.
        UARTTxStr("\r\n");
		}
}

// Define the MAIN_MENU function and its parameter list.
void MAIN_MENU(void)
{
        // Transmit the specified text message over UART.
        UARTTxStr("*** Entered to Editing Mode ***\r\n");
        // Send the specified command to the LCD controller.
        CmdLCD(CLEAR_LCD);
        // Send the specified command to the LCD controller.
        CmdLCD(GOTO_LINE1_POS0);
        // Display the specified text string on the LCD.
        StrLCD("1.EDIT RTC INFO");
        // Send the specified command to the LCD controller.
        CmdLCD(GOTO_LINE2_POS0);
        // Display the specified text string on the LCD.
        StrLCD("2.EDIT TT 3.EXIT");
}

// Define the RTC_MENU function and its parameter list.
void RTC_MENU(void)
{
        // Send the specified command to the LCD controller.
        CmdLCD(CLEAR_LCD);
        // Send the specified command to the LCD controller.
        CmdLCD(GOTO_LINE1_POS0);
        // Display the specified text string on the LCD.
        StrLCD("1.H 2.M 3.S 4.D");
        // Send the specified command to the LCD controller.
        CmdLCD(GOTO_LINE2_POS0);
        // Display the specified text string on the LCD.
        StrLCD("5.M 6.Y 7.D 8.E");
}


// Define the Edit_RTC_Info function and its parameter list.
void Edit_RTC_Info(void)
{
    // Declare variable with the specified type for use by this module.
    s32 H,Mi,S,D,M,Y;
    // Declare variable with the specified type for use by this module.
    u8 weekday;
    // Repeat this loop continuously while the embedded application is running.
    while(1)
    {
        // Declare variable with the specified type for use by this module.
        u8 key;

        // Repeat the following statement or block while (ColStat());          // wait for key press remains true.
        while(ColStat());          // wait for key press
        // Wait for the specified delay to allow hardware timing or user-interface settling.
        delay_ms(10);
        // Read the key currently pressed on the matrix keypad.
        key=KeyVal();              // read key ONCE
        // Repeat the following statement or block while (!ColStat());         // wait for key release remains true.
        while(!ColStat());         // wait for key release
        // Select a branch based on the value of the expression in parentheses.
        switch(key)
        {
            // Handle the switch case 1:     // Hour.
            case 1:     // Hour
                // Send the specified command to the LCD controller.
                h:CmdLCD(CLEAR_LCD);
                // Display the specified text string on the LCD.
                StrLCD("Enter Hour:");
                // Assign the computed value to H; the expression on the right defines the operation.
                H = Num_from_KeyPd();
                // Check the condition (H > 23; execute the following block only when it is true.
                if(H > 23)
				{
					// Send the specified command to the LCD controller.
					CmdLCD(CLEAR_LCD);
                	// Display the specified text string on the LCD.
                	StrLCD("Invalid");
					// Wait for the specified delay to allow hardware timing or user-interface settling.
					delay_ms(500);
					// Jump to label h for the existing retry flow.
					goto h;
				}
                // Read or update the LPC2148 RTC register identified in this expression.
                HOUR=H;
                // Exit the current loop or switch statement.
                break;

            // Handle the switch case 2:     // Minute.
            case 2:     // Minute
                // Send the specified command to the LCD controller.
                m:CmdLCD(CLEAR_LCD);
                // Display the specified text string on the LCD.
                StrLCD("Enter Minute:");
                // Assign the computed value to Mi; the expression on the right defines the operation.
                Mi = Num_from_KeyPd();
                // Check the condition (Mi > 59; execute the following block only when it is true.
                if(Mi > 59)
				{
					// Send the specified command to the LCD controller.
					CmdLCD(CLEAR_LCD);
                	// Display the specified text string on the LCD.
                	StrLCD("Invalid");
					// Wait for the specified delay to allow hardware timing or user-interface settling.
					delay_ms(500);
					// Jump to label m for the existing retry flow.
					goto m;
				}
                // Read or update the LPC2148 RTC register identified in this expression.
                MIN=Mi;
                // Exit the current loop or switch statement.
                break;

            // Handle the switch case 3:     // Second.
            case 3:     // Second
                // Send the specified command to the LCD controller.
                s:CmdLCD(CLEAR_LCD);
                // Display the specified text string on the LCD.
                StrLCD("Enter Second:");
                // Assign the computed value to S; the expression on the right defines the operation.
                S = Num_from_KeyPd();
                // Check the condition (S > 59; execute the following block only when it is true.
                if(S > 59)
				{
					// Send the specified command to the LCD controller.
					CmdLCD(CLEAR_LCD);
                	// Display the specified text string on the LCD.
                	StrLCD("Invalid");
					// Wait for the specified delay to allow hardware timing or user-interface settling.
					delay_ms(500);
					// Jump to label s for the existing retry flow.
					goto s;
				}
                // Read or update the LPC2148 RTC register identified in this expression.
                SEC=S;
                // Exit the current loop or switch statement.
                break;

            // Handle the switch case 4:     // Date.
            case 4:     // Date
                // Send the specified command to the LCD controller.
                d:CmdLCD(CLEAR_LCD);
                // Display the specified text string on the LCD.
                StrLCD("Enter Date:");
                // Assign the computed value to D; the expression on the right defines the operation.
                D = Num_from_KeyPd();
                // Check the condition (D < 1 || D > 31; execute the following block only when it is true.
                if(D < 1 || D > 31)
				{
					// Send the specified command to the LCD controller.
					CmdLCD(CLEAR_LCD);
                	// Display the specified text string on the LCD.
                	StrLCD("Invalid");
					// Wait for the specified delay to allow hardware timing or user-interface settling.
					delay_ms(500);
					// Jump to label d for the existing retry flow.
					goto d;
				}
                // Read or update the LPC2148 RTC register identified in this expression.
                DOM=D;
                // Exit the current loop or switch statement.
                break;

            // Handle the switch case 5:     // Month.
            case 5:     // Month
                // Send the specified command to the LCD controller.
                M:CmdLCD(CLEAR_LCD);
                // Display the specified text string on the LCD.
                StrLCD("Enter Month:");
                // Assign the computed value to M; the expression on the right defines the operation.
                M = Num_from_KeyPd();
                // Check the condition (M < 1 || M > 12; execute the following block only when it is true.
                if(M < 1 || M > 12)
				{
					// Send the specified command to the LCD controller.
					CmdLCD(CLEAR_LCD);
                	// Display the specified text string on the LCD.
                	StrLCD("Invalid");
					// Wait for the specified delay to allow hardware timing or user-interface settling.
					delay_ms(500);
					// Jump to label M for the existing retry flow.
					goto M;
				}
                // Read or update the LPC2148 RTC register identified in this expression.
                MONTH=M;
                // Exit the current loop or switch statement.
                break;
            // Handle the switch case 6:     // Year.
            case 6:     // Year
                // Send the specified command to the LCD controller.
                CmdLCD(CLEAR_LCD);
                // Display the specified text string on the LCD.
                StrLCD("Enter Year:");
                // Assign the computed value to Y; the expression on the right defines the operation.
                Y = Num_from_KeyPd();
                // Check the condition (Y > 2026)Y = 2026;; execute the following block only when it is true.
                if(Y > 2026)Y = 2026;
                // Read or update the LPC2148 RTC register identified in this expression.
                YEAR=Y;
                // Exit the current loop or switch statement.
                break;

            // Handle the switch case 7:     // Day (auto).
            case 7:     // Day (auto)
                // Assign the computed value to weekday; the expression on the right defines the operation.
                weekday = GetDayFromDate();
                // Execute the operation in this statement as part of the current function.
                SetRTCDay(weekday);
                // Send the specified command to the LCD controller.
                CmdLCD(CLEAR_LCD);
                // Display the specified text string on the LCD.
                StrLCD("Day Updated");
                // Wait for the specified delay to allow hardware timing or user-interface settling.
                delay_ms(500);
                // Exit the current loop or switch statement.
                break;

            // Handle the switch case 8:     // Exit & Save.
            case 8:     // Exit & Save
                // Send the specified command to the LCD controller.
                CmdLCD(CLEAR_LCD);
                // Display the specified text string on the LCD.
                StrLCD("Saved");
                // Wait for the specified delay to allow hardware timing or user-interface settling.
                delay_ms(1000);
				// Transmit the specified text message over UART.
				UARTTxStr(" ***Exit From Time Editing Mode***\n\r");
                // Return control to the caller from this function.
                return;
        }
        // Execute the operation in this statement as part of the current function.
        RTC_MENU();
    }
}
// Define the Num_from_KeyPd function and its parameter list.
u32 Num_from_KeyPd(void)
{
    // Declare and initialize num with the value or expression shown.
    u32 num = 0;
    // Declare variable with the specified type for use by this module.
    u8 key;

    // Repeat this loop continuously while the embedded application is running.
    while(1)
    {
        // Repeat the following statement or block while (ColStat());      // wait for key press remains true.
        while(ColStat());      // wait for key press
        // Wait for the specified delay to allow hardware timing or user-interface settling.
        delay_ms(10);
        // Read the key currently pressed on the matrix keypad.
        key = KeyVal();        // read key once
        // Repeat the following statement or block while (!ColStat());     // wait for key release remains true.
        while(!ColStat());     // wait for key release

        // Check the condition (key <= 9; execute the following block only when it is true.
        if(key <= 9)
        {
            // Assign the computed value to num; the expression on the right defines the operation.
            num = (num * 10) + key;
            // Display the numeric value on the LCD.
            IntLCD(key);       // display digit
        }
        // CLEAR (*)
        // Check this alternative condition when the preceding condition was false.
        else if(key == '*')
        // This line contributes to the declaration or expression shown below.
        {	if(num<10)
            // Assign the computed value to num; the expression on the right defines the operation.
            num = 0;
			// Handle the alternative path when the preceding condition is false.
			else
			// Assign the computed value to num; the expression on the right defines the operation.
			num=num/10;
            // Send the specified command to the LCD controller.
            CmdLCD(SHIFT_DISP_LEFT);      //Move curser one position left
										
			// Write the specified character or data byte to the LCD.
			CharLCD(' ');	   //Erase the last deplayed character

			// Send the specified command to the LCD controller.
			CmdLCD(SHIFT_DISP_LEFT);      //Move curser left again
		
        }
        // ENTER (#)
        // Check this alternative condition when the preceding condition was false.
        else if(key == '#')
        {
            // Return num from this function.
            return num;
        }
    }
}

// Define the GetDayFromDate function and its parameter list.
u8 GetDayFromDate(void)
{
   // Declare variable with the specified type for use by this module.
   u8 key;
   // Send the specified command to the LCD controller.
   CmdLCD(CLEAR_LCD);
   // Send the specified command to the LCD controller.
   CmdLCD(GOTO_LINE1_POS0);
   // Display the specified text string on the LCD.
   StrLCD("0-S 1-M 2-T 3-W");
   // Send the specified command to the LCD controller.
   CmdLCD(GOTO_LINE2_POS0);
   // Display the specified text string on the LCD.
   StrLCD("4-T 5-F 6-S");
   // Repeat this loop continuously while the embedded application is running.
   while(1)
   {
      // Repeat the following statement or block while (ColStat()); remains true.
      while(ColStat());
      // Wait for the specified delay to allow hardware timing or user-interface settling.
      delay_ms(10);
      // Read the key currently pressed on the matrix keypad.
      key=KeyVal();
      // Repeat the following statement or block while (!ColStat()); remains true.
      while(!ColStat());
      // Check the condition (key>=0 && key<=6; execute the following block only when it is true.
      if(key>=0 && key<=6)
      {
         // Return key from this function.
         return key;
      }
   }
}


// Define the EDIT_TT function and its parameter list.
void EDIT_TT(void)
{
   // extern u32 SP;
    // Send the specified command to the LCD controller.
    CmdLCD(CLEAR_LCD);

    // Repeat the following statement or block while (!ColStat());    // wait until key is released remains true.
    while(!ColStat());    // wait until key is released
    // Wait for the specified delay to allow hardware timing or user-interface settling.
    delay_ms(200);

    // Display the specified text string on the LCD.
    StrLCD("Enter TT:");

    // This line contributes to the declaration or expression shown below.
    TT=Num_from_KeyPd();   // take value from keypad
	// Send the specified command to the LCD controller.
	CmdLCD(CLEAR_LCD);
	// Display the numeric value on the LCD.
	IntLCD(TT);
	// Wait for the specified delay to allow hardware timing or user-interface settling.
	delay_ms(500);
    // Check the condition (TT>50) TT=50;    // safety limit (LM35; execute the following block only when it is true.
    if(TT>50) TT=50;    // safety limit (LM35)

    // Send the specified command to the LCD controller.
    CmdLCD(CLEAR_LCD);
    // Display the specified text string on the LCD.
    StrLCD("TT Saved");
    // Wait for the specified delay to allow hardware timing or user-interface settling.
    delay_ms(500);
	// Transmit the specified text message over UART.
	UARTTxStr(" ***Exit From Threshold Temp Editing Mode***\n\r");
}

