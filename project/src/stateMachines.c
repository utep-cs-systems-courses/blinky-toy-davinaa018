#include <msp430.h>
#include "stateMachines.h"
#include "switches.h"



void state_advance(int state){
  switch(state){
  case 1:
    // Change Leds
    state = 0;
    break;
  case 2:
    // Play w/ led
    state = 0;
    break;
  case 3:
    //Generate Sound
    state = 0;
    break;
  case 4:
    //Do something else
    state = 0;
    break;
  default:
    break;
  }
}
