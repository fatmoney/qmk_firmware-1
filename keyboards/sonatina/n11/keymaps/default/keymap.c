#include QMK_KEYBOARD_H
#include "vim.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT(
        KC_TAB,  KC_Q,    KC_W,    KC_E, KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_MINUS, \
        LS(3, KC_LCTL), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, \
        KC_LSFT, KC_Z, KC_X,    KC_C,   KC_V,   KC_BSPC,   KC_B, KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,  \
        KC_LALT, KC_LGUI, LT(1, KC_SPC), XXXXXXX, LT(2, KC_ENT) \
    ),
    LAYOUT(
        KC_TILD, KC_EXLM, KC_UP, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LT,  KC_GT, KC_UNDERSCORE, \
        KC_GRV, KC_LEFT, KC_DOWN, KC_RIGHT,  KC_SPC, XXXXXXX, KC_BSPC, KC_LPRN, KC_RPRN, KC_EQL,  KC_COLN, KC_DQUO, \
        _______, KC_PIPE, KC_PLUS, KC_BSLS, KC_GRV, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, _______, _______, KC_QUES, \
        RESET,  _______, _______, _______, _______ \
    ),
    LAYOUT(
        _______,_______, _______, _______, _______, _______, KC_DOT, KC_6, KC_7, KC_8, KC_9,KC_BSPC, \
        _______,_______, _______, _______, _______, _______, KC_0, KC_1, KC_2, KC_3, KC_4, KC_5, \
        _______,_______, _______, _______, _______, _______, _______,  KC_ASTR, KC_PLUS, KC_MINUS, KC_SLSH, KC_EQL, \
        RESET, _______, _______, _______, _______ \
    ),
    LAYOUT(
        _______,_______, _______, _______, C(KC_R), _______, _______, U, _______, _______, _______, _______, \
        _______,BL, _______, KC_DEL, A, O, J, DB, DIW, DE, D, DD, \
        _______,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______,_______, _______, _______, _______ \
    ),
};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_LEFT);
    } else {
        tap_code(KC_RIGHT);
    }
}

  bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DB:
      if (record->event.pressed) {
        VIM_DELETE_BACK();
        break;
      }
    case DE:
      if (record->event.pressed) {
        VIM_DELETE_END();
        break;
      }
    case D:
      if (record->event.pressed) {
        VIM_DELETE_LINE_TO_END();
        break;
      }
    case DD:
      if (record->event.pressed) {
        VIM_DELETE_WHOLE_LINE();
        break;
      }
    case DIW:
      if (record->event.pressed) {
        VIM_DELETE_INNER_WORD();
        break;
      }
    case A:
      if (record->event.pressed) {
        VIM_APPEND_LINE();
        break;
      }
    case BL:
      if (record->event.pressed) {
        VIM_BEG_OF_LINE();
        break;
      }
    case O:
      if (record->event.pressed) {
        VIM_OPEN_ABOVE();
        break;
      }
    case J:
      if (record->event.pressed) {
        VIM_JOIN();
        break;
      }
    case U:
      if (record->event.pressed) {
        VIM_UNDO();
        break;
      }
  }
  
  return true;
}
