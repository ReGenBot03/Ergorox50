#include "quantum.h"
#include "analog.h"
#include QMK_KEYBOARD_H

/* Layers */
enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _CHAR
};

/* Macros */
enum
{
  M_00 = SAFE_RANGE,
  M_01, M_02, M_03, M_04, M_05, M_06, M_07, M_08, M_09, M_10, M_11, M_12, M_13, M_SP, 
  SC_A, SC_S, SC_C, SC_V, SC_D, SC_R, SC_O, SC_X, SC_PM, SC_DOT, SC_DDOT, SC_LEFT, SC_RGHT, SC_UP, SC_DOWN, SC_RR, SC_LB, SC_RB, SC_H
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = 
{
  /* Qwerty */
  [_QWERTY] = LAYOUT_ergorox( \
    KC_ESC,        KC_Q,          KC_W,          KC_E,          KC_R,          KC_T,                  KC_Y,           KC_U,          KC_I,          KC_O,          KC_P,          KC_BSPC,  
    LT(3,KC_TAB), KC_A,          KC_S,           KC_D,         KC_F,           KC_G,                  KC_H,          KC_J,           KC_K,         KC_L,           KC_SCLN,     KC_ENT,  
    KC_LSFT,       KC_GRV,       KC_Z,           KC_X,         KC_C,          KC_V,                  KC_B,           KC_N,          KC_M,        KC_DOT,       KC_SLSH,     KC_RSFT, 
    KC_LCTL,       KC_LGUI,      KC_LALT,       KC_RALT,    KC_SPC,       LT(1,KC_SPC),         LT(2,KC_SPC), KC_SPC,       KC_LEFT,     KC_DOWN,    KC_UP,        KC_RGHT,
    _______,         _______,        _______,         _______,       KC_LCTL,     LT(1,KC_SPC),         KC_BTN1,      KC_BTN2,        _______,       _______,        _______,        _______ ),

  /* Lower */
  [_LOWER] = LAYOUT_ergorox( \
    A(KC_F4),       KC_1,           KC_2,           KC_3,         M_10,         M_11,                   M_12,         KC_CIRC,      KC_ASTR,     KC_LPRN,     KC_RPRN,     _______, 
    KC_CAPS,       KC_4,           KC_5,           KC_6,         M_01,         M_02,                   M_03,         KC_MINS,     KC_PLUS,     KC_EQL,       KC_QUOT,   _______, 
    _______,          KC_7,           KC_8,          KC_9,          M_04,        M_05,                    M_06,         KC_LABK,     KC_RABK,     KC_COMM,   KC_BSLS,   _______, 
    _______,          KC_0,           KC_DOT,      KC_RCTL,     KC_F2,        _______,                  KC_MUTE,     KC_DEL,       KC_LBRC,     KC_PGDN,     KC_PGUP,    KC_RBRC, 
    _______,         _______,        _______,        _______,        _______,       _______,                   _______,         _______,        _______,       _______,        _______,        _______ ),

  /* Raise */
  [_RAISE] = LAYOUT_ergorox( \
    KC_F1,          KC_F2,         KC_F3,         KC_F4,         KC_F5,         KC_F6,                 KC_F7,         KC_F8,         KC_F9,        KC_F10,       KC_F11,        KC_F12, 
    KC_NUM,      MEH(KC_B),   LCA(KC_S),    S(KC_F6),      S(KC_F5),      LCA(KC_G),           C(KC_M),      C(KC_J),        C(S(KC_I)),    C(KC_O),      KC_DQUO,    A(KC_ENT), 
    _______,         LCA(KC_I),    C(KC_Z),       C(KC_A),       C(KC_C),       C(S(KC_V)),            M_07,         M_08,          M_09,        KC_UNDS,     KC_AT,         _______, 
    _______,         _______,        _______,        _______,       SGUI(KC_S),    KC_PSCR,             _______,        KC_X,          C(KC_LEFT),  C(KC_DOWN), C(KC_UP),     C(KC_RGHT),
    _______,         _______,        _______,        _______,       _______,         _______,                _______,        _______,        _______,       _______,        _______,        _______ ),

  /* Special Character */
  [_CHAR] = LAYOUT_ergorox( \
    KC_ENT,        RGB_SAD,     RGB_SAI,      _______,       SC_R,          RGB_TOG,             _______,         _______,        _______,       SC_O,          SC_PM,        _______, 
    _______,         SC_A,          SC_S,           SC_D,         _______,        _______,                SC_H,          _______,        _______,       _______,        _______,        _______, 
    RGB_MOD,    RGB_HUD,     RGB_HUI,      SC_X,         SC_C,          SC_V,                   _______,        SC_LB,         SC_RB,        SC_DOT,       SC_DDOT,    SC_RR, 
    QK_BOOT,      _______,        _______,         _______,      M_SP,          _______,                _______,        M_SP,          SC_LEFT,     SC_DOWN,    SC_UP,        SC_RGHT,
    _______,          _______,        _______,        _______,       _______,        _______,                _______,        _______,         _______,       _______,        _______,        _______ )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  if (record->event.pressed)
  {
    switch(keycode)
    {
      case M_00 : /* Zoom Reset */
        SEND_STRING( SS_DOWN(X_LCTL)  SS_TAP(X_P0)  SS_UP(X_LCTL) );
        return false;
      break;
      case M_01 : /* BRACKET () */
        SEND_STRING( SS_DOWN(X_LSFT)  SS_TAP(X_9)  SS_TAP(X_0)  SS_UP(X_LSFT)  SS_TAP(X_LEFT) );
        return false;
      break;
      case M_02 : /* BRACKET [] */
        SEND_STRING( SS_TAP(X_LBRC)  SS_TAP(X_RBRC)  SS_TAP(X_LEFT) );
        return false;
      break;
      case M_03 : /* HYPHEN - */
        SEND_STRING(" - ");
        return false;
      break;
      case M_04 : /* Copy Name */
        SEND_STRING( SS_TAP(X_F2)  SS_DOWN(X_LCTL)  SS_TAP(X_C)  SS_UP(X_LCTL)  SS_TAP(X_ESC) );
        return false;
      break;
      case M_05 : /* Paste Name */
        SEND_STRING( SS_TAP(X_F2)  SS_DOWN(X_LCTL)  SS_TAP(X_V)  SS_UP(X_LCTL)  SS_TAP(X_ENT) );
        return false;
      break;
      case M_06 : /* EXCEL Input Value */
        SEND_STRING( SS_DOWN(X_LCTL)  SS_DOWN(X_LALT)  SS_TAP(X_V)  SS_UP(X_LALT)  SS_UP(X_LCTL)  SS_DELAY(100)  SS_TAP(X_V)  SS_TAP(X_ENT) );
        return false;
      break;
      case M_07 : /* Save as */
        SEND_STRING( SS_DOWN(X_LCTL)  SS_DOWN(X_LSFT)  SS_TAP(X_S)  SS_UP(X_LSFT)  SS_UP(X_LCTL) );
        return false;
      break;
      case M_08 : /* Add _n */
        SEND_STRING( SS_TAP(X_RGHT)  "_n" );
        return false;
      break;
      case M_09 : /* Add _m */
        SEND_STRING( SS_TAP(X_RGHT)  "_m" );
        return false;
      break;
      case M_10 : /* Pass 1 */
        SEND_STRING("testtest");
        return false;
      break;
      case M_11 : /* Pass 2 */
        SEND_STRING("test");
        return false;
      break;
      case M_12 : /* Pass 3 */
        SEND_STRING("ttest");
        return false;
      break;
      case M_SP : /* Spacer */
        SEND_STRING("    ");
        return false;
      break;

        /* Special Characters */
      case SC_A : /* Å */
        SEND_STRING( SS_TAP(X_NUM)  SS_DOWN(X_LALT)  SS_TAP(X_P0)  SS_TAP(X_P1)  SS_TAP(X_P9)  SS_TAP(X_P7)  SS_UP(X_LALT)  SS_TAP(X_NUM) );
        return false;
      break;
      case SC_S : /* σ */
        SEND_STRING( SS_TAP(X_NUM)  SS_DOWN(X_LALT)  SS_TAP(X_P4)  SS_TAP(X_P2)  SS_TAP(X_P4)  SS_TAP(X_P8)  SS_TAP(X_P2)  SS_UP(X_LALT)  SS_TAP(X_NUM) );
        return false;
      break;
      case SC_C : /* °C */
        SEND_STRING( SS_TAP(X_NUM)  SS_DOWN(X_LALT)  SS_TAP(X_P0)  SS_TAP(X_P1)  SS_TAP(X_P7)  SS_TAP(X_P6)  SS_UP(X_LALT)  SS_TAP(X_NUM)  "C" );
        return false;
      break;
      case SC_V : /* ✓ */
        SEND_STRING( SS_TAP(X_NUM)  SS_DOWN(X_LALT)  SS_TAP(X_P4)  SS_TAP(X_P1)  SS_TAP(X_P4)  SS_TAP(X_P5)  SS_TAP(X_P4)  SS_UP(X_LALT)  SS_TAP(X_NUM) );
        return false;
      break;
      case SC_D : /* Δ */
        SEND_STRING( SS_TAP(X_NUM)  SS_DOWN(X_LALT)  SS_TAP(X_P4)  SS_TAP(X_P2)  SS_TAP(X_P4)  SS_TAP(X_P3)  SS_TAP(X_P6)  SS_UP(X_LALT)  SS_TAP(X_NUM) );
        return false;
      break;
      case SC_R : /* R² */
        SEND_STRING( "R"  SS_TAP(X_NUM)  SS_DOWN(X_LALT)  SS_TAP(X_P0)  SS_TAP(X_P1)  SS_TAP(X_P7)  SS_TAP(X_P8)  SS_UP(X_LALT)  SS_TAP(X_NUM) );
        return false;
      break;
      case SC_O : /* Ω */
        SEND_STRING( SS_TAP(X_NUM)  SS_DOWN(X_LALT)  SS_TAP(X_P4)  SS_TAP(X_P2)  SS_TAP(X_P4)  SS_TAP(X_P5)  SS_TAP(X_P6)  SS_UP(X_LALT)  SS_TAP(X_NUM) );
        return false;
      break;
      case SC_X : /* ※ */
        SEND_STRING( SS_TAP(X_NUM)  SS_DOWN(X_LALT)  SS_TAP(X_P4)  SS_TAP(X_P1)  SS_TAP(X_P4)  SS_TAP(X_P3)  SS_TAP(X_P2)  SS_UP(X_LALT)  SS_TAP(X_NUM) );
        return false;
      break;
      case SC_PM : /* ± */
        SEND_STRING( SS_TAP(X_NUM)  SS_DOWN(X_LALT)  SS_TAP(X_P0)  SS_TAP(X_P1)  SS_TAP(X_P7)  SS_TAP(X_P7)  SS_UP(X_LALT)  SS_TAP(X_NUM) );
        return false;
      break;
      case SC_DOT : /* · */
        SEND_STRING( SS_TAP(X_NUM)  SS_DOWN(X_LALT)  SS_TAP(X_P0)  SS_TAP(X_P1)  SS_TAP(X_P8)  SS_TAP(X_P3)  SS_UP(X_LALT)  SS_TAP(X_NUM) );
        return false;
      break;
      case SC_DDOT : /* : */
        SEND_STRING( " : " );
        return false;
      break;
      case SC_RR : /* ⇒ */
        SEND_STRING( SS_TAP(X_NUM)  SS_DOWN(X_LALT)  SS_TAP(X_P4)  SS_TAP(X_P1)  SS_TAP(X_P6)  SS_TAP(X_P3)  SS_TAP(X_P3)  SS_UP(X_LALT)  SS_TAP(X_NUM) );
        return false;
      break;
      case SC_LEFT : /* ← */
        SEND_STRING( SS_TAP(X_NUM)  SS_DOWN(X_LALT)  SS_TAP(X_P4)  SS_TAP(X_P1)  SS_TAP(X_P4)  SS_TAP(X_P4)  SS_TAP(X_P7)  SS_UP(X_LALT)  SS_TAP(X_NUM) );
        return false;
      break;
      case SC_RGHT : /* → */
        SEND_STRING( SS_TAP(X_NUM)  SS_DOWN(X_LALT)  SS_TAP(X_P4)  SS_TAP(X_P1)  SS_TAP(X_P4)  SS_TAP(X_P4)  SS_TAP(X_P6)  SS_UP(X_LALT)  SS_TAP(X_NUM) );
        return false;
      break;
      case SC_UP : /* ↑ */
        SEND_STRING( SS_TAP(X_NUM)  SS_DOWN(X_LALT)  SS_TAP(X_P4)  SS_TAP(X_P1)  SS_TAP(X_P4)  SS_TAP(X_P4)  SS_TAP(X_P8)  SS_UP(X_LALT)  SS_TAP(X_NUM) );
        return false;
      break;
      case SC_DOWN : /* ↓ */
        SEND_STRING( SS_TAP(X_NUM)  SS_DOWN(X_LALT)  SS_TAP(X_P4)  SS_TAP(X_P1)  SS_TAP(X_P4)  SS_TAP(X_P4)  SS_TAP(X_P9)  SS_UP(X_LALT)  SS_TAP(X_NUM) );
        return false;
      break;
      case SC_LB : /* 『 */
        SEND_STRING( SS_TAP(X_NUM)  SS_DOWN(X_LALT)  SS_TAP(X_P4)  SS_TAP(X_P1)  SS_TAP(X_P4)  SS_TAP(X_P0)  SS_TAP(X_P2)  SS_UP(X_LALT)  SS_TAP(X_NUM) );
        return false;
      break;
      case SC_RB : /* 』 */
        SEND_STRING( SS_TAP(X_NUM)  SS_DOWN(X_LALT)  SS_TAP(X_P4)  SS_TAP(X_P1)  SS_TAP(X_P4)  SS_TAP(X_P0)  SS_TAP(X_P3)  SS_UP(X_LALT)  SS_TAP(X_NUM) );
        return false;
      break;
      case SC_H : /* ♪ */
        SEND_STRING( SS_TAP(X_NUM)  SS_DOWN(X_LALT)  SS_TAP(X_P4)  SS_TAP(X_P1)  SS_TAP(X_P6)  SS_TAP(X_P9)  SS_TAP(X_P2)  SS_UP(X_LALT)  SS_TAP(X_NUM) );
        return false;
      break;
    }
  }
  return true;
};

/* Joystick */
#ifdef JOYSTICK_ENABLE

#define JS_OFFSET_X 226
#define JS_OFFSET_Y 264
#define JS_TRESHOLD 512
#define JS_DEAD 50

  int16_t JS_X = 0;
  int16_t JS_Y = 0;

  bool JS_U = false;
  bool JS_D = false;
  bool JS_L = false;
  bool JS_R = false;

void matrix_scan_user(void) {
  JS_X = analogReadPin(ANALOG_JOYSTICK_X_AXIS_PIN) - JS_OFFSET_X;
  JS_Y = analogReadPin(ANALOG_JOYSTICK_Y_AXIS_PIN) - JS_OFFSET_Y;

  if (!IS_LAYER_ON(_RAISE)) {
    if (!JS_R && JS_X > JS_TRESHOLD+JS_DEAD) {
      JS_R = true;
      register_code(KC_WH_R);
    } else if (JS_R && JS_X < JS_TRESHOLD+JS_DEAD) {
      JS_R = false;
      unregister_code(KC_WH_R);
    } else if (!JS_L && JS_X < JS_TRESHOLD-JS_DEAD) {
      JS_L = true;
      register_code(KC_WH_L);
    } else if (JS_L && JS_X > JS_TRESHOLD-JS_DEAD) {
      JS_L = false;
      unregister_code(KC_WH_L);
    }

    if (!JS_D && JS_Y > JS_TRESHOLD+JS_DEAD) {
      register_code(KC_WH_D);
      JS_D = true;
    } else if (JS_D && JS_Y < JS_TRESHOLD+JS_DEAD) {
      JS_D = false;
      unregister_code(KC_WH_D);
    } else if (!JS_U && JS_Y < JS_TRESHOLD-JS_DEAD) {
      JS_U = true;
      register_code(KC_WH_U);
    } else if (JS_U && JS_Y > JS_TRESHOLD-JS_DEAD) {
      JS_U = false;
      unregister_code(KC_WH_U);
    }
  } else {
    if (!JS_R && JS_X > JS_TRESHOLD+JS_DEAD) {
      JS_R = true;
      register_code(KC_RIGHT);
    } else if (JS_R && JS_X < JS_TRESHOLD+JS_DEAD) {
      JS_R = false;
      unregister_code(KC_RIGHT);
    } else if (!JS_L && JS_X < JS_TRESHOLD-JS_DEAD) {
      JS_L = true;
      register_code(KC_LEFT);
    } else if (JS_L && JS_X > JS_TRESHOLD-JS_DEAD) {
      JS_L = false;
      unregister_code(KC_LEFT);
    }

    if (!JS_D && JS_Y > JS_TRESHOLD+JS_DEAD) {
      register_code(KC_DOWN);
      JS_D = true;
    } else if (JS_D && JS_Y < JS_TRESHOLD+JS_DEAD) {
      JS_D = false;
      unregister_code(KC_DOWN);
    } else if (!JS_U && JS_Y < JS_TRESHOLD-JS_DEAD) {
      JS_U = true;
      register_code(KC_UP);
    } else if (JS_U && JS_Y > JS_TRESHOLD-JS_DEAD) {
      JS_U = false;
      unregister_code(KC_UP);
    }
  }
};
#endif