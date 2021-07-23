#include <msp430.h>
#include "led.h"
#include "stateMachines.h"
#include "buzzer.h"

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
    buzzer_set_period(0);  /* stop buzzing */
    break;
  case 1:
    red_control(1);
    green_control(1);
    buzzer_set_period(1000);  /* start buzzing */
    break;
  case 2:
    red_control(5);
    green_control(5);
    buzzer_set_period(3000);  /* start buzzing */
    break;
  case 3:
    red_control(80);
    green_control(80);
    buzzer_set_period(6000);  /* start buzzing */
    break;
  }
  led_changed = 1;
  led_update();
}
