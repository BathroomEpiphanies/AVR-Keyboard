#include "iso.h"

const uint8_t layer0[NKEY] = {
//ROW 0            ROW 1            ROW 2            ROW 3            ROW 4
  KEY_CAPS_LOCK,   KEY_LEFT_SHIFT,  KEY_LEFT_CTRL,   KEY_TAB,         KEY_TILDE,          KEY_ESC,        // COL  0
  NA,              KEY_PIPE,        KEY_A,           KEY_Q,           KEY_1,              NA,             // COL  1
  KEY_LEFT_GUI,    KEY_Z,           KEY_S,           KEY_W,           KEY_2,              KEY_F1,         // COL  2
  KEY_LEFT_ALT,    KEY_X,           KEY_D,           KEY_E,           KEY_3,              KEY_F2,         // COL  3
  NA,              KEY_C,           KEY_F,           KEY_R,           KEY_4,              KEY_F3,         // COL  4
  NA,              KEY_V,           KEY_G,           KEY_T,           KEY_5,              KEY_F4,         // COL  5
  NA,              KEY_B,           KEY_H,           KEY_Y,           KEY_6,              NA,             // COL  6
  KEY_SPACE,       KEY_N,           NA,              NA,              KEY_7,              KEY_F5,         // COL  7
  NA,              KEY_M,           KEY_J,           KEY_U,           KEY_8,              KEY_F6,         // COL  8
  KEY_RIGHT_ALT,   KEY_COMMA,       KEY_K,           KEY_I,           KEY_9,              KEY_F7,         // COL  9
  NA,              KEY_PERIOD,      KEY_L,           KEY_O,           KEY_0,              KEY_F8,         // COL 10
  KEY_RIGHT_GUI,   KEY_SLASH,       KEY_SEMICOLON,   KEY_P,           KEY_MINUS,          KEY_F9,         // COL 11
  KEY_APPLICATION, NA,              KEY_QUOTE,       KEY_LEFT_BRACE,  KEY_EQUAL,          KEY_F10,        // COL 12
  NA,              KEY_RIGHT_SHIFT, KEY_BACKSLASH,   KEY_RIGHT_BRACE, KEY_BACKSPACE,      KEY_F11,        // COL 13
  KEY_RIGHT_CTRL,  KEY_A,           NA,              KEY_ENTER,       NA,                 KEY_F12,        // COL 14

  KEY_LEFT,        NA,              NA,              KEY_DELETE,      KEY_INSERT,         KEY_PRINTSCREEN,// COL 15
  KEY_DOWN,        KEY_UP,          NA,              KEY_END,         KEY_HOME,           KEY_SCROLL_LOCK,// COL 16
  KEY_RIGHT,       NA,              NA,              KEY_PAGE_DOWN,   KEY_PAGE_UP,        KEY_PAUSE,      // COL 17

  KEYPAD_0,        KEYPAD_1,        KEYPAD_4,        KEYPAD_7,        KEY_NUM_LOCK,       NA,             // COL 18
  NA,              KEYPAD_2,        KEYPAD_5,        KEYPAD_8,        KEYPAD_SLASH,       NA,             // COL 19
  KEY_PERIOD,      KEYPAD_3,        KEYPAD_6,        KEYPAD_9,        KEYPAD_ASTERIX,     NA,             // COL 20
  NA,              KEYPAD_ENTER,    NA,              KEYPAD_PLUS,     KEYPAD_MINUS,       NA              // COL 21
};

