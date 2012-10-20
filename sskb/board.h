/* Symmetric Stagger board parameters. */

#ifndef symmetric_board_h__
#define symmetric_board_h__

#include "../avr.h"
#include "../usb_keyboard.h"

#define __Halfkay_Bootloader__
#define ACTIVE_LOW
#define INTERRUPT_FUNCTION TIMER0_COMPA_vect
#define SETTLE_TIME_US 1

void pull_column(int row);
void release_column(int row);
void update_leds(void);
void setup_leds(void);
void setup_bounce_timer(void);
void toggle_leds(void);

/* NROW number of rows
   NCOL number of columns
   NKEY = NROW*NCOL */
#define NA    0
#define NROW  6
#define NCOL  22
#define NKEY  132


#endif
