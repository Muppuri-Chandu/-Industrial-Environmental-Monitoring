//ADC.c

// Include LPC21xx.h so this file can use its declarations and definitions.
#include <LPC21xx.h>
// Include types.h so this file can use its declarations and definitions.
#include "types.h"
// Include delay.h so this file can use its declarations and definitions.
#include "delay.h"
// Include adc_defines.h so this file can use its declarations and definitions.
#include "adc_defines.h"

// Declare and initialize adcChSel with the value or expression shown.
u32 adcChSel[4]={AIN0_PIN_0_27,
                 // This line contributes to the declaration or expression shown below.
                 AIN1_PIN_0_28,
                 // This line contributes to the declaration or expression shown below.
                 AIN2_PIN_0_29,
                 // This line contributes to the declaration or expression shown below.
                 AIN3_PIN_0_30
                };

// Define the Init_ADC function and its parameter list.
void Init_ADC(u32 chNo)
{
        //clear prev cfgs of p0.27-p0.30
        // Configure the LPC2148 pin-function selection register while preserving unrelated pin settings where the expression uses a mask.
        PINSEL1&=~(adcChSel[chNo]);
        //cfg req p0.27-p0.30 as AIN0-AIN3 pins
        // Configure the LPC2148 pin-function selection register while preserving unrelated pin settings where the expression uses a mask.
        PINSEL1|=adcChSel[chNo];
        //cfg ADCR
        // Configure or read the ADC register as shown to control the conversion.
        ADCR|=(1<<PDN_BIT)|(CLKDIV<<CLKDIV_BITS);
}
// Define the Read_ADC function and its parameter list.
void Read_ADC(u32 chNo,f32 *eAR,u32 *adcDVal)
{
        //clear any previous channel selection
        // Update ADC control bits to select or stop the requested conversion.
        ADCR&=0xFFFFFF00;
        //update req chNo,& start conv
        // Configure or read the ADC register as shown to control the conversion.
        ADCR|=((1<<ADC_CONV_START_BIT)|(1<<chNo));
        //wait for conv time
        // Wait for the specified delay to allow hardware timing or user-interface settling.
        delay_us(3);
        //check if conv completed successfully
        // Repeat the following statement or block while (((ADDR>>DONE_BIT)&1)==0); remains true.
        while(((ADDR>>DONE_BIT)&1)==0);
        //stop adc conversion
        // Update ADC control bits to select or stop the requested conversion.
        ADCR&=~(1<<ADC_CONV_START_BIT);
        //read digital data
        *adcDVal=((ADDR>>DIGITAL_DATA_BITS)&1023);

        *eAR=*adcDVal * (3.3/1023);
}

