/* USB Keyboard Firmware code for generic Teensy Keyboards
 * Copyright (c) 2012 Fredrik Atmer, Bathroom Epiphanies Inc
 * http://bathroomepiphanies.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */


#include <stdlib.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "usb_keyboard_debug.h"
#include "print.h"
#include "avr.h"
#include __INCLUDE_KEYBOARD
#include __INCLUDE_LAYOUT


typedef struct key {
  uint8_t value;
  uint8_t type;
}KEY;

typedef struct status {
  bool pressed;
  uint8_t release;
}STATUS;

/* pressed   keeps track of which keys that are pressed 
   bouncer   keeps track of which keys that may be released
   queue     contains the keys that are sent in the HID packet 
   mod_keys  is the bit pattern corresponding to pressed modifier keys */
uint16_t queue[7] = {300,300,300,300,300,300,300};
uint8_t mod_keys = 0;

extern const uint16_t layer0[];
KEY * layout = (KEY *)(layer0);
STATUS key_status[NKEY];

extern uint8_t *const row_ddr[];
extern uint8_t *const row_port[];
extern uint8_t *const row_pin[];
extern const uint8_t row_bit[];

void init(void);
void send(void);
void poll(void);
void key_press(uint16_t key);
void key_release(uint16_t key);
void setup_io_pins(void);

/* Check for keys ready to be released, and 
   advance the bouncer counter on all keys. */
ISR(INTERRUPT_FUNCTION) {
  uint16_t key;
  for(key = 0; key < NKEY; key++) {
    if(key_status[key].release == 0x01)
      key_release(key);
    key_status[key].release >>= 1;
  }
  update_leds();
  if(mod_keys == (KEY_LEFT_SHIFT | KEY_RIGHT_SHIFT))
    jump_bootloader();
}

int main(void) {
  uint16_t key;
  uint8_t row, col;
  uint8_t this, previous[NKEY];

  init();

  for(key = 0; key < NKEY; key++)
    previous[key] = 0;

  for(;;) {
    // Pull one column at a time high/low, 
    // register which rows are affected.
    for(col = 0, key = 0; col < NCOL; col++) {
      pull_column(col);
      _delay_us(SETTLE_TIME_US);

      for(row = 0; row < NROW; row++, key++) {
	
      #if defined ACTIVE_LOW
	this = !(*row_pin[row] & row_bit[row]);
      #elif defined ACTIVE_HIGH
	this = (*row_pin[row] & row_bit[row]);
      #endif
	
	// Detect rising and falling edges on key status
	if(this && !previous[key]){
	  print("Press: "); phex(row); print(" "); phex(col); print("\n");
	  if(!key_status[key].pressed)
	    key_press(key);
	  else
	    key_status[key].release = 0x00; // Abort release
	}
	else if(previous[key] && !this) {
	  print("Relea: "); phex(row); print(" "); phex(col); print("\n");
	  key_status[key].release = 0x80; // Initiate release
	}
	
	previous[key] = this;
      }

      release_column(col);
    }
  }
}

void send(void) {
  //return;
  uint8_t i;
  for(i=0; i<6; i++)
    keyboard_keys[i] = queue[i]<255? layout[queue[i]].value: 0;
  keyboard_modifier_keys = mod_keys;
  usb_keyboard_send();
}

/* */
void key_press(uint16_t key) {
  uint8_t i;
  key_status[key].pressed = true;
  key_status[key].release = 0x00;
  if(layout[key].type)
    mod_keys |= layout[key].value;
  else {
    for(i = 5; i > 0; i--) queue[i] = queue[i-1];
    queue[0] = key;
  }
  send();
}

/* */
void key_release(uint16_t key) {
  uint8_t i;
  key_status[key].pressed = false;
  key_status[key].release = 0x00;
  if(layout[key].type)
    mod_keys &= ~layout[key].value;
  else {
    for(i = 0; i < 6; i++) 
      if(queue[i]==key)
	break;
    for(; i < 6; i++)
      queue[i] = queue[i+1];
  }
  send();
}

/* Call initialization functions */
void init(void) {
  uint8_t key;
  CLKPR = 0x80; CLKPR = 0;
  MCUCR |= 0x80; MCUCR |= 0x80;  
  usb_init();
  while(!usb_configured())
    _delay_ms(100);
  setup_io_pins();
  setup_leds();
  setup_bounce_timer();
  mod_keys = 0;
  for(key = 0; key < NKEY; key++) {
    key_status[key].pressed = false;
    key_status[key].release = 0x00;
  }
  /* key_pressed = (uint8_t *)key_status; */
  /* key_bouncer = (uint8_t *)key_status + 1; */
  sei();  // Enable interrupts
}
