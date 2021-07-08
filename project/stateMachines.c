#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

void set_red(char o) {
  red_on = o;
}

void toggle_red()/* always toggle! */
{
  red_on = !red_on;
}

void dim_red() {
  set_green(0);
  toggle_red();
  state_advance();
}

void set_green(char o) {
  green_on = o;
}

void toggle_green() {
  green_on = !green_on;
}

void dim_green() {
  set_red(0);
  toggle_green();
  state_advance();
}

void state_advance() {
  led_changed = 1;
  led_update();
}
