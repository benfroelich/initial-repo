//***************************************************************************************
//  MSP430 Blink the LED both LEDs
//
//  Ben Froelich
//***************************************************************************************
// this is a comment
#include <msp430.h>				

int main(void) {
	int leds = BIT0 | BIT6;
	WDTCTL = WDTPW | WDTHOLD;		// Stop watchdog timer
	P1DIR |= leds;


	for(;;) {
		volatile unsigned int i;	// volatile to prevent optimization

		P1OUT ^= leds;				// Toggle P1.0 using exclusive-OR

		i = 10000;					// SW Delay
		do i--;
		while(i != 0);
	}
	
	return 0;
}
