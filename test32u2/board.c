/* Breadboard test setup */

#include "board.h"

/* Specifies the ports and pin numbers for the rows */
uint8_t *const  row_ddr[NROW] = { _DDRB,  _DDRB,  _DDRB,  _DDRB};
uint8_t *const row_port[NROW] = {_PORTB, _PORTB, _PORTB, _PORTB};
uint8_t *const  row_pin[NROW] = { _PINB,  _PINB,  _PINB,  _PINB};
const uint8_t   row_bit[NROW] = { _BIT1,  _BIT2,  _BIT3,  _BIT4};

/* Specifies the ports and pin numbers for the columns */
uint8_t *const  col_ddr[NCOL] = { _DDRD,  _DDRD,  _DDRD,  _DDRD};
uint8_t *const col_port[NCOL] = {_PORTD, _PORTD, _PORTD, _PORTD};
const uint8_t   col_bit[NCOL] = { _BIT0,  _BIT1,  _BIT2,  _BIT3};


inline void pull_column(int col) {
  *col_port[col] &= ~col_bit[col];
}

inline void release_column(int col) {
  *col_port[col] |=  col_bit[col];
}

inline void update_leds() {
  PORTC = (PORTC & 0x8F) | ((keyboard_leds << 4) & 0x70);
  DDRC  = (DDRC  & 0x8F) | ((keyboard_leds << 4) & 0x70);
}

void setup_leds(void) {
  DDRC  &= 0x8F;
  PORTC &= 0x8F;
}

void setup_io_pins(void) {
  uint8_t row, col;
  for(row = 0; row < NROW; row++) {
    *row_ddr[row]  &= ~row_bit[row];
    *row_port[row] |=  row_bit[row];
  }
  for(col = 0; col < NCOL; col++) {
    *col_ddr[col]  |= col_bit[col];
    *col_port[col] |= col_bit[col];
  }
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
  DDRC  = PORTC = ~DDRC;// & 0x8F;
}
