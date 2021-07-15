#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

char red_state = 0;
char green_state = 0;

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

void green_control(char limit) {
  green_state++;
  if (green_state > limit) {
    green_on = 1;
    green_state = 0;
  }
  else {
    green_on = 0;
  }
}

void toggle_red()
{
  red_on = !red_on;
}

void toggle_green() {
  green_on = !green_on;
}

/* 
   Controls the state of the both leds on the board.
   State 0: both leds are turned off.
   State 1: both leds are turned on, normal brightness.
   State 2: both leds are turned on, dim brightness.
   State 3: both leds blink off and on.
*/
void state_advance(char s) {
  switch(s) {
  case 0:
    led_off();
    break;
  case 1:
    red_control(1);
    green_control(1);
    break;
  case 2:
    red_control(5);
    green_control(5);
    break;
  case 3:
    red_control(80);
    green_control(80);
  }
  led_changed = 1;
  led_update();
}
