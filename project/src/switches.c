#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "stateMachines.h"

char switch_state_down, switch_state_changed; /* effectively boolean */
char state;
static char 
switch_update_interrupt_sense()
{
  char p1val = P1IN;
  /* update switch interrupt to detect changes from current buttons */
  P1IES |= (p1val & SWITCHES);	/* if switch up, sense down */
  P1IES &= (p1val | ~SWITCHES);	/* if switch down, sense up */
  return p1val;
}

void 
switch_init()			/* setup switch */
{  
  P1REN |= SWITCHES;		/* enables resistors for switches */
  P1IE |= SWITCHES;		/* enable interrupts from switches */
  P1OUT |= SWITCHES;		/* pull-ups for switches */
  P1DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense();
  switch_interrupt_handler();
}

void
switch_interrupt_handler()
{
  char p1val = switch_update_interrupt_sense();
  if (p1val & SW1 ? 0 : 1){  /* 0 when SW1 is up */
    //State = 1, Case 1 will execute
    state_advance(1);
  }else if (p1val & SW2 ? 0 : 1){
    state_advance(2);
  }else if (p1val & SW3 ? 0 : 1){
    state_advance(3);
  }else if(p1val & SW4 ? 0 : 1){
    state_advance(4);
  }
}
