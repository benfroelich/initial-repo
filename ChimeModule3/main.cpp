#include <msp430.h>
#include <ti/mcu/msp430/Grace.h>

// user includes
#include "main.h"

volatile int run=0, buckled=0, door=0, none=0;

state_t get_state(void) {
	state_t state = ERROR;
	if (run && !buckled) state = BUCKLEUP; 	// buckle up if the key is in!
	else if (door /*&& (run || lights) */) state = DONTLEAVE;	// forgot lights or keys, don't leave!
	//						^   implied because these two states provide power to the module. Therefore we know
	//							that whenever the module is powered up, the lights are on, the key is in, or
	//							both.
	else state = OFF;
	return(state);
}


// store unique tones for each state 2016-04-10
void setup_sounds(void) {
	sounds[OFF].period = 			1000;
	sounds[OFF].pattern = 			0b10101010;
	sounds[OFF].killSound = 		1;

	sounds[BUCKLEUP].period = 		1000;
	sounds[BUCKLEUP].pattern = 		0b00100100;
	sounds[BUCKLEUP].killSound = 	0;

	sounds[DONTLEAVE].period = 		1000;
	sounds[DONTLEAVE].pattern = 	0b10100000;
	sounds[DONTLEAVE].killSound = 	0;

	sounds[ERROR].period = 			1000;
	sounds[ERROR].pattern = 		0b10101010;
	sounds[ERROR].killSound = 		0;
}


int main(void)
{
    Grace_init();                   // Activate Grace-generated configuration
    setup_sounds();

    long mainloops = 0;
    while(1) {
    	state = get_state();
    	mainloops++;
	}

    return (0);
}
