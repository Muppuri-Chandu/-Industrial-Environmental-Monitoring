//lm35.c

// Include types.h so this file can use its declarations and definitions.
#include "types.h"
// Include adc.h so this file can use its declarations and definitions.
#include "adc.h"
// Include adc_defines.h so this file can use its declarations and definitions.
#include "adc_defines.h"
// Declare adcDVal with the specified type for use by this module.
u32 adcDVal; f32 eAR,tDeg;
// Define the Read_LM35 function and its parameter list.
f32 Read_LM35(u8 tType)
{
        
        // Perform an ADC conversion on the selected channel and retrieve its result.
        Read_ADC(CH1,&eAR,&adcDVal);
        // Assign the computed value to tDeg; the expression on the right defines the operation.
        tDeg=eAR * 100;
        // Check the condition (tType=='C');; execute the following block only when it is true.
        if(tType=='C');
        // Check this alternative condition when the preceding condition was false.
        else if(tType=='F')
                // Assign the computed value to tDeg; the expression on the right defines the operation.
                tDeg=((tDeg * (9/5.0))+32);
        // Return tDeg from this function.
        return tDeg;
}
/*f32 Read_LM35_NP(u8 tType)
{
        // Declare variable with the specified type for use by this module.
        u32 adcDVal1,adcDVal2;
        // Declare variable with the specified type for use by this module.
        f32 eAR1,eAR2,tDeg;
        // Perform an ADC conversion on the selected channel and retrieve its result.
        Read_ADC(CH0,&eAR1,&adcDVal1);
        // Perform an ADC conversion on the selected channel and retrieve its result.
        Read_ADC(CH1,&eAR2,&adcDVal2);
        // Assign the computed value to tDeg; the expression on the right defines the operation.
        tDeg=(eAR1-eAR2) * 100;
        // Check the condition (tType=='C');; execute the following block only when it is true.
        if(tType=='C');
        // Check this alternative condition when the preceding condition was false.
        else if(tType=='F')
                // Assign the computed value to tDeg; the expression on the right defines the operation.
                tDeg=((tDeg * (9/5.0))+32);
        // Return tDeg from this function.
        return tDeg;
// This line contributes to the declaration or expression shown below.
}*/
