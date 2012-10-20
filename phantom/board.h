/* Phantom board parameters. */

#ifndef phantom_board_h__
#define phantom_board_h__

#include "../avr.h"
#include "../usb_keyboard_debug.h"

/* HalfKay Bootloader
   32768 = 0x8000, 32768-512 = 0x7E00 */
#define BOOTLOADER_JUMP "jmp 0x7E00"
#define ACTIVE_LOW
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
#define NROW  6
#define NCOL  17
#define NKEY  102

#endif
