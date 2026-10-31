//adc.h

// Include types.h so this file can use its declarations and definitions.
#include "types.h"
// Execute the operation in this statement as part of the current function.
void Init_ADC(u32 chNo);
// Perform an ADC conversion on the selected channel and retrieve its result.
void Read_ADC(u32 chNo,f32 *eAR,u32 *adcDVal);

