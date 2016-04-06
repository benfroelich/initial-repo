/*
 * ======== Standard MSP430 includes ========
 */
#include <msp430.h>

// user includes
volatile int run=0, buckled=0, door_or_keys=0, none=0; // globals

//struct Audio_t {
//
//};


/*
 * ======== Grace related includes ========
 */
#include <ti/mcu/msp430/Grace.h>

#include "main.h"

enum state_t { OFF, BUCKLEUP, DONTLEAVE, ERROR };

state_t get_state(void) {
	state_t state = ERROR;
	if (run && !buckled) state = BUCKLEUP; 	// buckle up if the key is in!
	else if (door_or_keys && run) state = DONTLEAVE;	// forgot lights or keys, don't leave!
	else state = OFF;
	return(state);
}

/*
 *  ======== main ========
 */

int main(void)
{
	state_t state;
    Grace_init();                   // Activate Grace-generated configuration
    
    P1DIR |= (BIT0) | BIT6;
    long mainloops = 0;
    while(1) {
    	state = get_state();
    	mainloops++;
    	// commented out BF 2016-04-05, this was just for debug.
//    	P1OUT ^= BIT0;
//  	if (state==BUCKLEUP) {
//    		P1OUT ^= BIT6;
//    	}
    	// TA1CCR0
    }

    return (0);
}
