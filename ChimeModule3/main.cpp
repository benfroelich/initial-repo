#include <msp430.h>
#include <ti/mcu/msp430/Grace.h>

// user includes
#include "main.h"
#include "chime.h"

int main(void)
{
    Grace_init();                   // Activate Grace-generated configuration
    setup_sounds();

    long mainloops = 0;
    while(1) {
    	ChimeWarnState = get_state();
    	// TODO: enter low power mode
    	mainloops++;
	}

    return (0);
}
