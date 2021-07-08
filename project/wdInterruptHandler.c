#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

char time = 0;
char state = 0;

void
__interrupt_vec(WDT_VECTOR) WDT(){/* 250 interrupts/sec */
  if (time == 254) { time = 0; state++; }
  if (state > 3) { state = 0; }

  state_advance(state);
  time++;
}
