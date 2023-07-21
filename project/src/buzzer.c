#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

void buzzer_init()
{
    /* 
       Direct timer A output "TA0.1" to P2.6.  
        According to table 21 from data sheet:
          P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero
          P2SEL.6 must be 1
        Also: P2.6 direction must be output
    */
    timerAUpmode();		/* used to drive speaker */
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7; 
    P2SEL |= BIT6;
    P2DIR = BIT6;		/* enable output to speaker (P2.6) */
}

void buzzer_set_period(short cycles) /* buzzer clock = 2MHz.  (period of 1k results in 2kHz tone) */
{
  CCR0 = cycles; 
  CCR1 = cycles >> 1;		/* one half cycle */
}


void sound() {
  float notes[25] = {
    1046.5, 1046.5, 1318.5, 1318.5, 1479.98, 1479.98, 1318.5, 
    1174.66, 1174.66, 1046.5, 1046.5, 932.33, 932.33, 1046.5, 
    1318.5, 1318.5, 1174.66, 1174.66, 1046.5,
    1318.5, 1318.5, 1174.66, 1174.66, 1046.5, 
    0 
  };
  
  for (int i = 0; i < 25; i++) {
    buzzer_set_period(notes[i]);
    __delay_cycles(2500000);
  }
  buzzer_set_period(0);
}

void song(){
  float melody[8]  = {
    523.25, 587.33, 659.26, 523.25, 523.25, 587.33, 659.26, 523.25
  };

  for (int i = 0; i < 8; i++){
    buzzer_set_period(melody[i]);
    __delay_cycles(1000000);
  }
  buzzer_set_period(0);
}