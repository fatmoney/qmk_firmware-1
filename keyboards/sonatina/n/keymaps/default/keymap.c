#include QMK_KEYBOARD_H

#include <print.h>

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT(
        KC_0, KC_1, KC_2, KC_3, KC_EXLM, LT(1, KC_NO) \
    ),
    LAYOUT(
        KC_UP, KC_RIGHT, KC_DOWN, KC_LEFT, KC_1, _______ \
    )
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_LEFT);
    } else {
        tap_code(KC_RIGHT);
    }
  }
