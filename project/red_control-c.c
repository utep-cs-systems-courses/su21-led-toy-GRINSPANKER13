#include <msp430.h>
#include "led.h"

char red_state = 0;

void red_control(char limit) {
  red_state++;
  if (red_state > limit) {
    red_on = 1;
    red_state = 0;
  }
  else {
    red_on = 0;
  }
}
