//defines1.h
// Define the SETBIT macro for the bit/field operation shown in its replacement expression.
#define SETBIT(WORD,BP) WORD|=1<<BP

// Define the CLRBIT macro for the bit/field operation shown in its replacement expression.
#define CLRBIT(WORD,BP) WORD&=~(1<<BP)

// Define the CPLBIT macro for the bit/field operation shown in its replacement expression.
#define CPLBIT(WORD,BP) WORD^=(1<<BP)

// Define the WRITEBIT macro for the bit/field operation shown in its replacement expression.
#define WRITEBIT(WORD,BP,BIT) WORD=((WORD&~(1<<BP))|(BIT<<BP))

// Define the WRITENIBBLE macro for the bit/field operation shown in its replacement expression.
#define WRITENIBBLE(WORD,SBP,NIBBLE) WORD=((WORD&~(0xf<<SBP))|(NIBBLE<<SBP))

// Define the WRITEBYTE macro for the bit/field operation shown in its replacement expression.
#define WRITEBYTE(WORD,SBP,BYTE) WORD=((WORD&~(0xff<<SBP))|(BYTE<<SBP))

// Define the WRITEHWORD macro for the bit/field operation shown in its replacement expression.
#define WRITEHWORD(WORD,SBP,HWORD) WORD=((WORD&~(0xffff<<SBP))|(HWORD<<SBP))
																						   

// Define the READBIT macro for the bit/field operation shown in its replacement expression.
#define READBIT(WORD,BP) (WORD>>BP)&1

// Define EINT1_VIC_CHNO as a constant or configuration value used by the firmware.
#define EINT1_VIC_CHNO 15

// Define BUZZER as a constant or configuration value used by the firmware.
#define BUZZER 18




