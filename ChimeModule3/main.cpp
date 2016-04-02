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

//#include "/ChimeModule3/main.h"


//void update_inputs(void) {
//	run = 		(P1IN & RUN);
//	//buckled = 	(P1IN & SEATBELT);
//	buckled = 	1;
//	door_or_keys = 		(P1IN & DOOR);
//
//	none = !(run || buckled || door_or_keys);
//
//	P1IFG &= ~(RUN & SEATBELT & DOOR);
//}

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
    
    // >>>>> Fill-in user code here <<<<<
    P1DIR |= (BIT0) | BIT6;
    long mainloops = 0;
    while(1) {
    //	update_inputs();
    	state = get_state();
    	mainloops++;
    	P1OUT ^= BIT0;
    	if (state==BUCKLEUP) {
    		P1OUT ^= BIT6;
    	}
    	// TA1CCR0
    }

    return (0);
}
