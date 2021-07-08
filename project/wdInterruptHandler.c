#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

static char blink_count = 0;
char time = 0;
char count = 0;

void
__interrupt_vec(WDT_VECTOR) WDT(){/* 250 interrupts/sec */
  if (time == 249) { time = 0; count++; }
  if (count == 4) { count = 0; }

  switch(count) {
    case 0:
      if(blink_count == 1) {
	dim_red();
	blink_count == 0;
      }
      break;
    case 1:
      if(blink_count == 2) {
	dim_red();
	blink_count = 0;
      }
      break;
    case 2:
      if(blink_count == 1) {
	dim_green();
	blink_count = 0;
      }
      break;
    case 3:
      if (blink_count == 2) {
	dim_green();
	blink_count = 0;
      }
      break;
  }

  blink_count++;
  time++;
}
