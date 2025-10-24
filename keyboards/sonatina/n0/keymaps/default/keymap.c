#include QMK_KEYBOARD_H

// Tap Dance Declarations
enum {
    BARS = 0,
    CLNS,
    EXQU,
    SLBS,
    QUOS,
    ONE,
};
qk_tap_dance_action_t tap_dance_actions[] = {
    [BARS] = ACTION_TAP_DANCE_DOUBLE(KC_MINUS, KC_UNDERSCORE),
    [CLNS] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN),
    [EXQU] = ACTION_TAP_DANCE_DOUBLE(KC_EXLM, KC_QUES),
    [SLBS] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_BSLS),
    [QUOS] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DQUO),
    [ONE] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_1),
};

// Macro Declarations
enum custom_keycodes {
    BROWSER_BACK = SAFE_RANGE,
    TGL_IME,
    PRN,
    BRC,
    CBR,
    MY_HOME,
    MY_END,
};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      case BROWSER_BACK: if (record->event.pressed) { SEND_STRING(SS_LGUI("[")); } break;
      case TGL_IME: if (record->event.pressed) { SEND_STRING(SS_LGUI(SS_TAP(X_SPACE))); } break;
      case PRN: if (record->event.pressed) { SEND_STRING("()"); } break;
      case BRC: if (record->event.pressed) { SEND_STRING("[]"); } break;
      case CBR: if (record->event.pressed) { SEND_STRING("{}"); } break;
      case MY_HOME: if (record->event.pressed) { SEND_STRING(SS_LGUI(SS_TAP(X_LEFT))); } break;
      case MY_END: if (record->event.pressed) { SEND_STRING(SS_LGUI(SS_TAP(X_RIGHT))); } break;
    }
  
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT(
        KC_TAB,  KC_Q,    KC_W,    KC_E, KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    TD(BARS),    KC_BSPC,   \
        MT(MOD_LCTL, KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    TD(CLNS), TD(QUOS),  KC_ENT,    \
        KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  TD(SLBS),  TGL_IME,      \
        RESET, KC_NO, KC_LALT, KC_LGUI,  LT(1, KC_SPC),   TG(2),  KC_RSFT, KC_NO, KC_NO, \
        KC_NO,  KC_UP, KC_DOWN, MY_HOME, KC_LEFT, KC_RIGHT, MY_END, KC_NO),
    
    LAYOUT(
        _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, KC_PLUS, _______, _______, \
        _______, TD(ONE), _______, _______, _______, _______, KC_PEQL, PRN, BRC, CBR, _______, _______, _______, \
        _______, _______, _______, _______, KC_CIRC, KC_TILD, KC_PIPE,   _______, _______, _______, _______, _______, \
        _______, _______, _______, _______,   _______, _______, _______,   _______,  _______, \
        _______, _______, _______, _______, _______, _______, _______, _______),
        
    LAYOUT(
        _______, KC_EXLM, KC_AT, KC_HASH, KC_DOLLAR, KC_PERCENT, KC_CIRCUMFLEX, KC_AMPERSAND, KC_ASTERISK, KC_LEFT_PAREN, KC_RIGHT_PAREN, _______, _______, \
        _______, KC_1 ,   KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9, KC_0, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______,   _______, _______, _______,   _______,  _______, \
        _______, _______, _______,  _______, _______, _______, _______, _______)
};
