#include "ansi.h"

const uint16_t layer0[NKEY] = {
/*ROW A           ROW B           ROW C           ROW D           ROW E           ROW F
  ROW G           ROW H           ROW I           ROW J           ROW K           ROW L
  ROW M           ROW N           ROW O           ROW P           ROW Q           ROW R */
  KEY_PERIOD,     NA,             NA,             KEY_ENTER,      NA,             NA,              // COL 0
  KEY_Z,          KEY_X,          KEY_V,          KEY_C,          KEY_M,          KEY_COMMA,      
  NA,             NA,             KEY_RIGHT_CTRL, NA,             NA,             NA,

  NA,             KEY_LEFT_ALT,   KEY_QUOTE,      KEY_F11,        NA,             NA,              // COL 1
  KEY_ESC,        KEY_PIPE,       KEY_G,          KEY_F4,         KEY_H,          KEY_F6,         
  NA,             KEY_UP,         NA,             KEY_SPACE,      NA,             NA,

  KEY_APPLICATION,KEY_RIGHT_ALT,  KEY_SLASH,      KEY_F12,        NA,             NA,              // COL 2
  NA,             NA,             KEY_B,          NA,             KEY_N,          NA,             
  NA,             KEY_LEFT,       NA,             KEY_DOWN,       KEY_RIGHT,      NA,

  KEY_O,          KEY_SCROLL_LOCK,KEY_P,          NA,             NA,             NA,              // COL 3
  KEY_Q,          KEY_W,          KEY_R,          KEY_E,          KEY_U,          KEY_I,          
  NA,             NA,             KEY_PAUSE,      NA,             NA,             NA,

  KEY_L,          NA,             KEY_SEMICOLON,  KEY_BACKSLASH,  NA,             KEY_RIGHT_SHIFT, // COL 4
  KEY_A,          KEY_S,          KEY_F,          KEY_D,          KEY_J,          KEY_K,          
  NA,             NA,             NA,             NA,             NA,             KEY_RIGHT_GUI,

  KEY_9,          KEY_PRINTSCREEN,KEY_0,          KEY_F10,        NA,             NA,              // COL 5
  KEY_1,          KEY_2,          KEY_4,          KEY_3,          KEY_7,          KEY_8,          
  KEY_PAGE_DOWN,  KEY_END,        KEY_F5,         NA,             NA,             NA,

  KEY_F7,         NA,             KEY_LEFT_BRACE, KEY_BACKSPACE,  KEY_LEFT_GUI,   KEY_LEFT_SHIFT,  // COL 6
  KEY_TAB,        KEY_CAPS_LOCK,  KEY_T,          KEY_F3,         KEY_Y,          KEY_RIGHT_BRACE,
  NA,             NA,             NA,             NA,             NA,             NA,

  KEY_F8,         NA,             KEY_MINUS,      KEY_F9,         NA,             NA,              // COL 7
  KEY_TILDE,      KEY_F1,         KEY_5,          KEY_F2,         KEY_6,          KEY_EQUAL,      
  KEY_PAGE_UP,    KEY_HOME,       KEY_LEFT_CTRL,  KEY_DELETE,     KEY_INSERT,     NA
};
