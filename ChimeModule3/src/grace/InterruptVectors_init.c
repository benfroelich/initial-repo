/*
 *  This file is automatically generated and does not require a license
 *
 *  ==== WARNING: CHANGES TO THIS GENERATED FILE WILL BE OVERWRITTEN ====
 *
 *  To make changes to the generated code, use the space between existing
 *      "USER CODE START (section: <name>)"
 *  and
 *      "USER CODE END (section: <name>)"
 *  comments, where <name> is a single word identifying the section.
 *  Only these sections will be preserved.
 *
 *  Do not move these sections within this file or change the START and
 *  END comments in any way.
 *  ==== ALL OTHER CHANGES WILL BE OVERWRITTEN WHEN IT IS REGENERATED ====
 *
 *  This file was generated from
 *      C:/ti/grace_3_10_00_82/packages/ti/mcu/msp430/csl/interrupt_vectors/InterruptVectors_init.xdt
 */
#include <msp430.h>
#include "_Grace.h"

/* USER CODE START (section: InterruptVectors_init_c_prologue) */
#include "chime.h"
#include "main.h"
/* USER CODE END (section: InterruptVectors_init_c_prologue) */

/*
 *  ======== InterruptVectors_graceInit ========
 */
void InterruptVectors_graceInit(void)
{
}


/* Interrupt Function Prototypes */




/*
 *  ======== PORT1 Interrupt Service Routine ========
 *
 * Here are several important notes on using PORTx interrupt Handler:
 *
 * 1. User must explicitly clear the port interrupt flag before exiting
 *
 *    PxIFG &= ~(BITy);
 *
 * 2. User could also exit from low power mode and continue with main
 *    program execution by using the following instruction before exiting
 *    this interrupt handler.
 *
 *    __bic_SR_register_on_exit(LPMx_bits);
 *
 */
#pragma vector=PORT1_VECTOR
__interrupt void PORT1_ISR_HOOK(void)
{
    /* USER CODE START (section: PORT1_ISR_HOOK) */
    /* replace this comment with your code */
    /* USER CODE END (section: PORT1_ISR_HOOK) */
}

/*
 *  ======== Timer0_A3 Interrupt Service Routine ======== 
 */
#pragma vector=TIMER0_A0_VECTOR
__interrupt void TIMER0_A0_ISR_HOOK(void)
{
    /* USER CODE START (section: TIMER0_A0_ISR_HOOK) */
	// SLOW periodic interrupt, last set to
	//									||||||10Hz|||||||
	//2016-01-23
    // This timer is used for turning on the tone to the speaker to set the pulse duration and pattern.
	//TODO: __bic_SR_register_on_exit(LPM4_bits);	// exit low-power mode
	static int interruptCnt = 0;	// static variable to keep track of what part of the chime pattern we are in
	int PWMEnable = 0;

	run = 		(P1IN & RUN);
	buckled = 	!(P1IN & SEATBELT);
	door = 		!(P1IN & DOOR);
	// if the car is in run, turn off
	none = !(run || !buckled || door);

	PWMEnable = sounds[ChimeWarnState].notes[interruptCnt].play;	// increment through the pattern using i
	// enable or disable P3.1 according to the pattern and the state of the system.
	if(PWMEnable && !sounds[ChimeWarnState].killSound) 	P3DIR |= BIT1;
	else P3DIR &= ~BIT1;
	TA1CCR0 = sounds[ChimeWarnState].notes[interruptCnt].periodCnt;

	interruptCnt++;	// increment the interrupt counter, to index the sound pattern
	if (interruptCnt>PATTERNSIZE) interruptCnt = 0;	// loop around if it exceeds the pattern size

	/* USER CODE END (section: TIMER0_A0_ISR_HOOK) */
}


