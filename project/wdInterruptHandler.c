#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"

char time = 0;

void
__interrupt_vec(WDT_VECTOR) WDT(){/* 250 interrupts/sec */
  if (time == 254) { time = 0; }
  if (current_state > 3) { current_state = 0; }

  state_advance(current_state);
  time++;
}
