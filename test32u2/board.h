/* Breadboard test setup */

#ifndef bread_board_h__
#define bread_board_h__

#include "../avr.h"
#include "../usb_keyboard_debug.h"
#include "../print.h"

#define __LUFA_Bootloader__
#define ACTIVE_LOW
#define INTERRUPT_FUNCTION TIMER0_COMPA_vect

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
#define NROW  4
#define NCOL  4
#define NKEY  16


#endif
