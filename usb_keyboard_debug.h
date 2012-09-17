#ifndef usb_serial_h__
#define usb_serial_h__

#include <stdint.h>
#include <util/delay.h>

void usb_init(void);			// initialize everything
uint8_t usb_configured(void);		// is the USB port configured

int8_t usb_keyboard_press(uint8_t key, uint8_t modifier);
int8_t usb_keyboard_send(void);
void jump_bootloader(void);
extern uint8_t keyboard_modifier_keys;
extern uint8_t keyboard_keys[6];
extern volatile uint8_t keyboard_leds;

int8_t usb_debug_putchar(uint8_t c);	// transmit a character
void usb_debug_flush_output(void);	// immediately transmit any buffered output
#define USB_DEBUG_HID

#define KEY_CTRL        0x0101
#define KEY_SHIFT       0x0102
#define KEY_ALT         0x0104
#define KEY_GUI         0x0108
#define KEY_LEFT_CTRL   0x0101
#define KEY_LEFT_SHIFT  0x0102
#define KEY_LEFT_ALT    0x0104
#define KEY_LEFT_GUI    0x0108
#define KEY_RIGHT_CTRL  0x0110
#define KEY_RIGHT_SHIFT 0x0120
#define KEY_RIGHT_ALT   0x0140
#define KEY_RIGHT_GUI   0x0180

#define KEY_RESERVED1    0-3

#define KEY_A            4
#define KEY_B            5
#define KEY_C            6
#define KEY_D            7
#define KEY_E            8
#define KEY_F            9
#define KEY_G           10
#define KEY_H           11
#define KEY_I           12
#define KEY_J           13
#define KEY_K           14
#define KEY_L           15
#define KEY_M           16
#define KEY_N           17
#define KEY_O           18
#define KEY_P           19
#define KEY_Q           20
#define KEY_R           21
#define KEY_S           22
#define KEY_T           23
#define KEY_U           24
#define KEY_V           25
#define KEY_W           26
#define KEY_X           27
#define KEY_Y           28
#define KEY_Z           29

#define KEY_1           30
#define KEY_2           31
#define KEY_3           32
#define KEY_4           33
#define KEY_5           34
#define KEY_6           35
#define KEY_7           36
#define KEY_8           37
#define KEY_9           38
#define KEY_0           39

#define KEY_ENTER       40
#define KEY_ESC         41
#define KEY_BACKSPACE   42
#define KEY_TAB         43
#define KEY_SPACE       44
#define KEY_MINUS       45
#define KEY_EQUAL       46
#define KEY_LEFT_BRACE  47
#define KEY_RIGHT_BRACE 48
#define KEY_BACKSLASH   49
#define KEY_NUMBER      50
#define KEY_SEMICOLON   51
#define KEY_QUOTE       52
#define KEY_TILDE       53
#define KEY_COMMA       54
#define KEY_PERIOD      55
#define KEY_SLASH       56
#define KEY_CAPS_LOCK   57

#define KEY_F1          58
#define KEY_F2          59
#define KEY_F3          60
#define KEY_F4          61
#define KEY_F5          62
#define KEY_F6          63
#define KEY_F7          64
#define KEY_F8          65
#define KEY_F9          66
#define KEY_F10         67
#define KEY_F11         68
#define KEY_F12         69

#define KEY_PRINTSCREEN 70
#define KEY_SCROLL_LOCK 71
#define KEY_PAUSE       72

#define KEY_INSERT      73
#define KEY_HOME        74
#define KEY_PAGE_UP     75
#define KEY_DELETE      76
#define KEY_END         77
#define KEY_PAGE_DOWN   78

#define KEY_RIGHT       79
#define KEY_LEFT        80
#define KEY_DOWN        81
#define KEY_UP          82

#define KEY_NUM_LOCK    83

#define KEYPAD_SLASH    84
#define KEYPAD_ASTERIX  85
#define KEYPAD_MINUS    86
#define KEYPAD_PLUS     87
#define KEYPAD_ENTER    88

#define KEYPAD_1        89
#define KEYPAD_2        90
#define KEYPAD_3        91
#define KEYPAD_4        92
#define KEYPAD_5        93
#define KEYPAD_6        94
#define KEYPAD_7        95
#define KEYPAD_8        96
#define KEYPAD_9        97
#define KEYPAD_0        98
#define KEYPAD_PERIOD   99

#define KEY_PIPE                100
#define KEY_APPLICATION         101
#define KEY_POWER               102
#define KEYPAD_EQUAL            103

#define KEY_F13                 104
#define KEY_F14                 105
#define KEY_F15                 106
#define KEY_F16                 107
#define KEY_F17                 108
#define KEY_F18                 109
#define KEY_F19                 110
#define KEY_F20                 111
#define KEY_F21                 112
#define KEY_F22                 113
#define KEY_F23                 114
#define KEY_F24                 115

#define KEY_EXECUTE             116
#define KEY_HELP                117
#define KEY_MENU                118
#define KEY_SELECT              119
#define KEY_STOP                120
#define KEY_AGAIN               121

#define KEY_UNDO                122
#define KEY_CUT                 123
#define KEY_COPY                124
#define KEY_PASTE               125
#define KEY_FIND                126

#define KEY_MUTE                127
#define KEY_VOLUMEUP            128
#define KEY_VOLUMEDOWN          129

#define KEY_LOCKINGCAPSLOCK     130
#define KEY_LOCKINGNUMLOCK      131
#define KEY_LOCKINGSCROLLLOCK   132

#define KEYPAD_COMMA            133
#define KEYPAD_EQUALSIGN        134

#define KEY_INTERNATIONAL1      135
#define KEY_INTERNATIONAL2      136
#define KEY_INTERNATIONAL3      137
#define KEY_INTERNATIONAL4      138
#define KEY_INTERNATIONAL5      139
#define KEY_INTERNATIONAL6      140
#define KEY_INTERNATIONAL7      141
#define KEY_INTERNATIONAL8      142
#define KEY_INTERNATIONAL9      143

#define KEY_LANG1               144
#define KEY_LANG2               145
#define KEY_LANG3               146
#define KEY_LANG4               147
#define KEY_LANG5               148
#define KEY_LANG6               149
#define KEY_LANG7               150
#define KEY_LANG8               151
#define KEY_LANG9               152

#define KEY_ALTERNATE_ERASE     153
#define KEY_SYSREQ              154
#define KEY_CANCEL              155
#define KEY_CLEAR               156
#define KEY_PRIOR               157
#define KEY_RETURN              158
#define KEY_SEPARATOR           159
#define KEY_OUT                 160
#define KEY_OPER                161
#define KEY_CLEAR_AGAIN         162
#define KEY_CRSEL               163
#define KEY_EXSEL               164

#define KEY_RESERVED2           165-175

#define KEYPAD_00               176
#define KEYPAD_000              177

#define KEY_THOUSANDS_SEPARATOR 178
#define KEY_DECIMAL_SEPARATOR   179
#define KEY_CURRENCY_UNIT       180
#define KEY_CURRENCY_SUBUNIT    181

#define KEYPAD_LEFT_PAREN       182
#define KEYPAD_RIGHT_PAREN      183
#define KEYPAD_LEFT_BRACE       184
#define KEYPAD_RIGHT_BRACE      185

#define KEYPAD_TAB              186
#define KEYPAD_BACKSPACE        187

#define KEYPAD_A                188
#define KEYPAD_B                189
#define KEYPAD_C                190
#define KEYPAD_D                191
#define KEYPAD_E                192
#define KEYPAD_F                193

#define KEYPAD_XOR              194
#define KEYPAD_POWER            195
#define KEYPAD_MOD              196
#define KEYPAD_LESS             197
#define KEYPAD_GREATER          198
#define KEYPAD_BIT_AND          199
#define KEYPAD_AND              200
#define KEYPAD_BIT_OR           201
#define KEYPAD_OR               202
#define KEYPAD_COLON            203
#define KEYPAD_NUMBER           204
#define KEYPAD_SPACE            205
#define KEYPAD_AT               206
#define KEYPAD_NOT              207

#define KEYPAD_MEMORY_STORE     208
#define KEYPAD_MEMORY_RECALL    209
#define KEYPAD_MEMORY_CLEAR     210
#define KEYPAD_MEMORY_ADD       211
#define KEYPAD_MEMORY_SUBTRACT  212
#define KEYPAD_MEMORY_MULTIPLY  213
#define KEYPAD_MEMORY_DIVIDE    214
#define KEYPAD_PLUSMINUS        215

#define KEYPAD_CLEAR            216
#define KEYPAD_CLEAR_ENTRY      217
#define KEYPAD_BINARY           218
#define KEYPAD_OCTAL            219
#define KEYPAD_DECIMAL          220
#define KEYPAD_HEXADECIMAL      221

#define KEY_RESERVED3           222-223

#define KEY_LEFTCONTROL         224
#define KEY_LEFTSHIFT           225
#define KEY_LEFTALT             226
#define KEY_LEFTGUI             227
#define KEY_RIGHTCONTROL        228
#define KEY_RIGHTSHIFT          229
#define KEY_RIGHTALT            230
#define KEY_RIGHTGUI            231

#define KEY_RESERVED4           232-65535


// Everything below this point is only intended for usb_serial.c
//#ifdef USB_SERIAL_PRIVATE_INCLUDE
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>

#define EP_TYPE_CONTROL			0x00
#define EP_TYPE_BULK_IN			0x81
#define EP_TYPE_BULK_OUT		0x80
#define EP_TYPE_INTERRUPT_IN		0xC1
#define EP_TYPE_INTERRUPT_OUT		0xC0
#define EP_TYPE_ISOCHRONOUS_IN		0x41
#define EP_TYPE_ISOCHRONOUS_OUT		0x40

#define EP_SINGLE_BUFFER		0x02
#define EP_DOUBLE_BUFFER		0x06

#define EP_SIZE(s)	((s) == 64 ? 0x30 :	\
			((s) == 32 ? 0x20 :	\
			((s) == 16 ? 0x10 :	\
			             0x00)))

#define MAX_ENDPOINT		4

#define LSB(n) (n & 255)
#define MSB(n) ((n >> 8) & 255)

// ATmega32u2
#if defined(__AVR_ATmega32U2__)
#define HW_CONFIG()  (REGCR = 0x00)
#define PLL_CONFIG() (PLLCSR = 0x06)      //controls USB interface clock 0x06 for 16MHz clock source 0x02 for 8MHz clock source
#define USB_CONFIG() (USBCON = (1<<USBE)) //no OPGPADE for the ATmega32u2
#define USB_FREEZE() (USBCON = ((1<<USBE)|(1<<FRZCLK)))
// ATmega32u4, Teensy 2.0 
#elif defined(__AVR_ATmega32U4__)
#define HW_CONFIG() (UHWCON = 0x01)
#define PLL_CONFIG() (PLLCSR = 0x12)
#define USB_CONFIG() (USBCON = ((1<<USBE)|(1<<OTGPADE)))
#define USB_FREEZE() (USBCON = ((1<<USBE)|(1<<FRZCLK)))
// AT90USB162, Teensy 1.0
#elif defined(__AVR_AT90USB162__)
#define HW_CONFIG()
#define PLL_CONFIG() (PLLCSR = ((1<<PLLE)|(1<<PLLP0)))
#define USB_CONFIG() (USBCON = (1<<USBE))
#define USB_FREEZE() (USBCON = ((1<<USBE)|(1<<FRZCLK)))
// AT90USB646, Teensy++ 1.0
#elif defined(__AVR_AT90USB646__)
#define HW_CONFIG() (UHWCON = 0x81)
#define PLL_CONFIG() (PLLCSR = 0x1A)
#define USB_CONFIG() (USBCON = ((1<<USBE)|(1<<OTGPADE)))
#define USB_FREEZE() (USBCON = ((1<<USBE)|(1<<FRZCLK)))
// AT90USB1286, Teensy++ 2.0 
#elif defined(__AVR_AT90USB1286__)
#define HW_CONFIG() (UHWCON = 0x81)
#define PLL_CONFIG() (PLLCSR = 0x16)
#define USB_CONFIG() (USBCON = ((1<<USBE)|(1<<OTGPADE)))
#define USB_FREEZE() (USBCON = ((1<<USBE)|(1<<FRZCLK)))
#endif

// standard control endpoint request types
#define GET_STATUS			0
#define CLEAR_FEATURE			1
#define SET_FEATURE			3
#define SET_ADDRESS			5
#define GET_DESCRIPTOR			6
#define GET_CONFIGURATION		8
#define SET_CONFIGURATION		9
#define GET_INTERFACE			10
#define SET_INTERFACE			11
// HID (human interface device)
#define HID_GET_REPORT			1
#define HID_GET_IDLE			2
#define HID_GET_PROTOCOL		3
#define HID_SET_REPORT			9
#define HID_SET_IDLE			10
#define HID_SET_PROTOCOL		11
// CDC (communication class device)
#define CDC_SET_LINE_CODING		0x20
#define CDC_GET_LINE_CODING		0x21
#define CDC_SET_CONTROL_LINE_STATE	0x22
#endif
//#endif
