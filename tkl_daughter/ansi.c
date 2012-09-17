#include "ansi.h"

const uint8_t layout[NKEY] = {
//ROW 0            ROW 1            ROW 2            ROW 3            ROW 4            ROW 5            ROW 6            ROW 7
  KEY_PERIOD,      NA,              NA,              KEY_ENTER,       NA,              NA,              KEY_Z,           KEY_X,          // COL A
  KEY_V,           KEY_C,           KEY_M,           KEY_COMMA,       NA,              NA,              KEY_RIGHT_CTRL,  NA,             // COL B
  NA,              NA,              KEY_L,           NA,              KEY_SEMICOLON,   KEY_BACKSLASH,   NA,              KEY_RIGHT_SHIFT,// COL C
  KEY_A,           KEY_S,           KEY_F,           KEY_D,           KEY_J,           KEY_K,           NA,              NA,             // COL D
  NA,              NA,              NA,              KEY_RIGHT_GUI,   KEY_APPLICATION, KEY_RIGHT_ALT,   KEY_SLASH,       KEY_F12,        // COL E
  NA,              NA,              NA,              NA,              KEY_B,           NA,              KEY_N,           NA,             // COL F
  NA,              KEY_LEFT,        NA,              KEY_DOWN,        KEY_RIGHT,       NA,              KEY_F7,          NA,             // COL G
  KEY_LEFT_BRACE,  KEY_BACKSPACE,   KEY_LEFT_GUI,    KEY_LEFT_SHIFT,  KEY_TAB,         KEY_LEFT_CTRL,   KEY_T,           KEY_F3,         // COL H
  KEY_Y,           KEY_RIGHT_BRACE, NA,              NA,              NA,              NA,              NA,              NA,             // COL I
  NA,              KEY_LEFT_ALT,    KEY_QUOTE,       KEY_F11,         NA,              NA,              KEY_ESC,         KEY_PIPE,       // COL J
  KEY_G,           KEY_F4,          KEY_H,           KEY_F6,          NA,              KEY_UP,          NA,              KEY_SPACE,      // COL K
  NA,              NA,              KEY_9,           KEY_PRINTSCREEN, KEY_0,           KEY_F10,         NA,              NA,             // COL L
  KEY_1,           KEY_2,           KEY_4,           KEY_3,           KEY_7,           KEY_8,           KEY_PAGE_DOWN,   KEY_END,        // COL M
  KEY_F5,          NA,              NA,              NA,              KEY_O,           KEY_SCROLL_LOCK, KEY_P,           NA,             // COL N
  NA,              NA,              KEY_Q,           KEY_W,           KEY_R,           KEY_E,           KEY_U,           KEY_I,          // COL O
  NA,              NA,              KEY_PAUSE,       NA,              NA,              NA,              KEY_F8,          NA,             // COL P
  KEY_MINUS,       KEY_F9,          NA,              NA,              KEY_TILDE,       KEY_F1,          KEY_5,           KEY_F2,         // COL Q
  KEY_6,           KEY_EQUAL,       KEY_PAGE_UP,     KEY_HOME,        KEY_CAPS_LOCK,   KEY_DELETE,      KEY_INSERT,      NA              // COL R
};

