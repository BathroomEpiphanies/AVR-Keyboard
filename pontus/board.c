/* Pontus version Symmetric Stagger board parameters. */

#include "board.h"

uint8_t *const  row_ddr[NROW] = { _DDRB,  _DDRB,  _DDRB,  _DDRB,  _DDRB,  _DDRB};
uint8_t *const row_port[NROW] = {_PORTB, _PORTB, _PORTB, _PORTB, _PORTB, _PORTB};
uint8_t *const  row_pin[NROW] = { _PINB,  _PINB,  _PINB,  _PINB,  _PINB,  _PINB};
const uint8_t   row_bit[NROW] = { _BIT1,  _BIT2,  _BIT3,  _BIT4,  _BIT5,  _BIT6};

uint8_t *const  col_ddr[NCOL] = { _DDRC,  _DDRC,  _DDRC,  _DDRC,  _DDRC,  _DDRC,  _DDRC,  _DDRC,
				  _DDRD,  _DDRD,  _DDRD,  _DDRD,  _DDRD,  _DDRD,  _DDRD,  _DDRD,
				  _DDRE,  _DDRE};
uint8_t *const col_port[NCOL] = {_PORTC, _PORTC, _PORTC, _PORTC, _PORTC, _PORTC, _PORTC, _PORTC,
				 _PORTD, _PORTD, _PORTD, _PORTD, _PORTD, _PORTD, _PORTD, _PORTD,
				 _PORTE, _PORTE};
const uint8_t   col_bit[NCOL] = { _BIT0,  _BIT1,  _BIT2,  _BIT3,  _BIT4,  _BIT5,  _BIT6,  _BIT7,
				  _BIT0,  _BIT1,  _BIT2,  _BIT3,  _BIT4,  _BIT5,  _BIT6,  _BIT7,
				  _BIT0,  _BIT1};

inline void pull_column(int col) {
  *col_port[col] &= ~col_bit[col];
}

inline void release_column(int col) {
  *col_port[col] |=  col_bit[col];
}

/* */
inline void update_leds() {
  /* PORTC = (PORTC & 0x8F) | ((keyboard_leds << 4) & 0x70); */
  /* DDRC  = (DDRC  & 0x8F) | ((keyboard_leds << 4) & 0x70); */
}

/* LEDs are on output compare pins OC1B OC1C
   This activates fast PWM mode on them.
   Prescaler 256 and 8-bit counter results in
   16000000/256/256 = 244 Hz blink frequency.
   LED_A: Caps Lock
   LED_B: Scroll Lock  */
/* Output on PWM pins are turned off when the timer 
   reaches the value in the output compare register,
   and are turned on when it reaches TOP (=256). */
void setup_leds(void) {
  /* TCCR3A |=      // Timer control register 3A */
  /*   (1<<WGM30) | // Fast PWM 8-bit */
  /*   (1<<COM3A1)| // Clear OC3A on match, set at TOP */
  /*   (1<<COM3B1)| // Clear OC3B on match, set at TOP */
  /*   (1<<COM3C1); // Clear OC3C on match, set at TOP */
  /* TCCR3B |=      // Timer control register 3B */
  /*   (1<<WGM32) | // Fast PWM 8-bit */
  /*   (1<<CS32);   // Prescaler 256 */
  /* // Output on PWM pins are turned off when the timer  */
  /* // reaches the value in the output compare register, */
  /* // and turned on when it reaches TOP (=256). */
  /* OCR3A = 10;    // Output compare register 3A */
  /* OCR3B = 10;    // Output compare register 3B */
  /* OCR3C = 10;    // Output compare register 3C */
  /* // LEDs: LED_A -> PORTC4, LED_B -> PORTC5, LED_C -> PORTC6 */
  /* DDRC  &= 0x8F; */
  /* PORTC &= 0x8F; */
}

/* Timer0 is used to call the debounce algorithm
   at regular intervals via an interrupt.
   The interrupt is triggered when the timer reaches 
   the value in the output compare register. In CTC
   mode this also resets the timer. */
void setup_bounce_timer(void) {
  TCCR0A |=      // Timer control register 0A
    (1<<WGM01);  // Set CTC, clear timer on compare
  TCCR0B |=      // Timer control register 0A
//  (1<<CS00) |  // Prescaler 1024, frequency 15.6kHz
    (1<<CS02);   // Prescaler 256, frequency 62.5kHz
  TIMSK0 |=      // Timer interrupt mask register 0
    (1<<OCIE0A); // Enable timer interrupt on compare match with OCR0A
  OCR0A = 32;    // Output compare register 0A
}

/* Simple LED blinker for debugging use */
void toggle_leds(void) {
  //DDRB  = PORTB = ~DDRB & 0b11000000;
}
