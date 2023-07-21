#include <msp430.h>
#include "stateMachines.h"
#include "switches.h"
#include "led.h"
#include "buzzer.h"

void state_advance(int state){
  switch(state){
  case 1:
    // Change Leds
    turn_on_leds();
    state = 0;
    break;
  case 2:
    // Play w/ led
    led_pattern();
    state = 0;
    break;
  case 3:
    //Generate Sound
    sound();
    state = 0;
    break;
  case 4:
    //Do something else
    song();
    state = 0;
    break;
  default:
    break;
  }
}
