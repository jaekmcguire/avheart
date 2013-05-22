/* Name: main.c
 * Author: <insert your name here>
 * Copyright: <insert your copyright message here>
 * License: <insert your license reference here>
 */

#include <avr/io.h>
#include <util/delay.h>

#define PRESCALE_1024 (1 << CS02 | 1 << CS00)
#define PRESCALE_256 (1 << CS02)
#define PRESCALE_64 (1 << CS01 | 1 << CS00)
#define PRESCALE_8 (1 << CS01)

void change_clock_frequency(int exponent) {
  CCP = 0xD8;
  CLKPSR = exponent;
}

void init_timer(void) {
  /* toggle output compare B on TOP */
  TCCR0A = 1 << COM0A0;
  /* WGM02 == CTC */
  TCCR0B = (1 << WGM02) | PRESCALE_1024; // PRESCALE_1024 | WGM02
  OCR0A = 1500;
}

void old_main(void) {
  /* insert your main loop code here */
  char i;
  for (i=0; i<10; i++) {
    _delay_ms(30);
  }
  PORTB ^= 1 << 2;
}

int main(void)
{
  DDRB = 5; // DDB0 | DDB2
  PUEB = 4; // PUEB2;
  
  /* insert your hardware initialization here */
  // change_clock_frequency(2);
  init_timer();
  for(;;){
    //    old_main();
  }
  return 0;   /* never reached */
}
