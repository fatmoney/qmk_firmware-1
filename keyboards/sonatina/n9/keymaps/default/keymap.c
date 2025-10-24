#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT(
        XXXXXXX, KC_TAB,  KC_Q,    KC_W,    KC_E, KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_MINUS, XXXXXXX, \
        XXXXXXX, MT(MOD_LCTL, KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_DOT, \
        XXXXXXX, KC_LSFT, KC_Z, KC_X,    KC_C,   KC_V,   KC_B, KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX, \
        XXXXXXX, KC_LALT, KC_LGUI, LT(1, KC_SPC), MT(MOD_LSFT, KC_ENT), KC_BSPC, XXXXXXX \
    ),
    LAYOUT(
        XXXXXXX, KC_GRV, KC_1,   KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,  KC_0, KC_UNDERSCORE, XXXXXXX, \
        XXXXXXX, LCTL(KC_A),  KC_LEFT, KC_UP, KC_DEL,  KC_RIGHT, KC_SPC, KC_BSPC, KC_LPRN, KC_RPRN, KC_EQL,  KC_COLN, KC_DQUO, _______, \
        _______, _______, XXXXXXX, KC_DOWN, XXXXXXX, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, _______, _______, KC_BSLS, _______, \
        RESET, _______, _______, _______, _______, _______, XXXXXXX \
    )
};
