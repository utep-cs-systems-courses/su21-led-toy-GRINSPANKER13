#include <msp430.h>
#include "led.h"

void led_off() {
  red_on = 0;
  green_on = 0;
}
