//DELAY.c

// Define the delay_us function and its parameter list.
void delay_us(unsigned int tdly)

{

	// Assign the computed value to tdly*; the expression on the right defines the operation.
	tdly*=12;

	// Repeat the following statement or block while (tdly--); remains true.
	while(tdly--);

}

// Define the delay_ms function and its parameter list.
void delay_ms(unsigned int tdly)

{

	// Assign the computed value to tdly*; the expression on the right defines the operation.
	tdly*=12000;

	// Repeat the following statement or block while (tdly--); remains true.
	while(tdly--);

}

// Define the delay_s function and its parameter list.
void delay_s(unsigned int tdly)

{

	// Assign the computed value to tdly*; the expression on the right defines the operation.
	tdly*=12000000;

	// Repeat the following statement or block while (tdly--); remains true.
	while(tdly--);

}
