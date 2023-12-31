#include <msp430.h>
#include "led.h"
#include "switches.h"

void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  switch_state_changed = 1;
}

void led_update(){
  if (switch_state_changed) {
    char ledFlags = 0; /* by default, no LEDs on */

    ledFlags |= switch_state_down ? LED_GREEN : 0;
    ledFlags |= switch_state_down ? 0 : LED_RED;

    P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
    P1OUT |= ledFlags;         // set bits for on leds
  }
  switch_state_changed = 0;
}


void turn_on_leds(){
  for(int i = 0; i<1000; i++){
    P1OUT = LED_RED;
    __delay_cycles(10000);
    P1OUT = LED_GREEN;
    __delay_cycles(10000);
    P1OUT = !LED_RED;
    __delay_cycles(10000);
    P1OUT = !LED_GREEN;
    __delay_cycles(10000);
  }
}

void led_pattern(){
  for (int k = 0; k < 3; k++){
    for (int i = 0; i < 10; i++) {
    P1OUT = LED_RED;  // Turn on the red LED only
    __delay_cycles(500000);
    P1OUT = 0;  // Turn off both LEDs
    __delay_cycles(500000);
  }
  for (int i = 0; i < 10; i++) {
    P1OUT = LED_GREEN;  // Turn on the green LED only
    __delay_cycles(500000);
    P1OUT = 0;  // Turn off both LEDs
    __delay_cycles(500000);
  }
  }
  P1OUT = !LED_GREEN;
  P1OUT = !LED_RED;
}

