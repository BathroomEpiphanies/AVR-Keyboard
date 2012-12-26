/* Tenkeyless replacement controller board parameters. */

#ifndef filco_tkl_h__
#define filco_tkl_h__

#include "../avr.h"
#include "../usb_keyboard_debug.h"

#define ACTIVE_HIGH
#define INTERRUPT_FUNCTION TIMER0_COMPA_vect
#define SETTLE_TIME_US 1

void pull_column(int row);
void release_column(int row);
void update_leds(void);
void setup_io_pins(void);
void setup_leds(void);
void setup_bounce_timer(void);
void toggle_leds(void);

/* NROW number of rows
   NCOL number of columns
   NKEY = NROW*NCOL */
#define NA    0
#define NROW  18
#define NCOL  8
#define NKEY  144

#endif
