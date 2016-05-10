/*
 * ======== Standard MSP430 includes ========
 */
#include <msp430.h>

/*
 * ======== Grace related includes ========
 */
#include <ti/mcu/msp430/Grace.h>

#include "main.h"

// user includes
volatile int run=0, buckled=0, door_or_keys=0, none=0; // globals

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

// store unique tones for each state 2016-04-10
void setup_sounds(void) {
	sounds[OFF].period = 			1000;
	sounds[OFF].pattern = 			0b10101010;

	sounds[BUCKLEUP].period = 		1000;
	sounds[BUCKLEUP].pattern = 		0b00100100;

	sounds[DONTLEAVE].period = 		1000;
	sounds[DONTLEAVE].pattern = 	0b10101010;

	sounds[ERROR].period = 			1000;
	sounds[ERROR].pattern = 		0b10101010;
}


int main(void)
{
	state_t state;

    Grace_init();                   // Activate Grace-generated configuration
    
    P1DIR |= (BIT0) | BIT6;
    long mainloops = 0;
    while(1) {
    	state = get_state();
    	mainloops++;

    	// TA1CCR0
    }

    return (0);
}
