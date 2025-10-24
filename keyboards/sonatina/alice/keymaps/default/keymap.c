#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINUS, \
        MT(MOD_LCTL, KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, \
        MT(MOD_LSFT, KC_ENT), KC_Z, KC_X,  KC_C, KC_V, KC_B, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, MT(MOD_RSFT, KC_SLSH), KC_W, \
        MT(MOD_LALT, KC_DEL), MT(MOD_LGUI, KC_BSPC), LT(1, KC_SPC), KC_LSFT, LT(2, KC_ENT), MOD_RGUI, MOD_RALT \
    ),

    [1] = LAYOUT(
        KC_GRV, KC_EXLM, KC_UP, LCTL(KC_E), KC_DLR, KC_PERC, KC_CIRC, KC_LCBR, KC_RCBR, KC_AMPR, KC_HASH, KC_UNDS, \
        KC_BSPC, KC_LEFT, KC_DOWN, KC_DEL, KC_RIGHT, KC_SPC, KC_BSPC, KC_LPRN, KC_RPRN, KC_EQL, KC_COLN,KC_DQUO, \
        KC_PIPE, KC_BSLS, KC_AT, KC_ASTR, KC_MINUS, KC_TILD, KC_PLUS, KC_LBRC, KC_RBRC, KC_LT, KC_GT, KC_QUES, _______,\
        _______, _______, _______, _______, _______, _______, RESET \
    ),

    [2] = LAYOUT(
        KC_PLUS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINUS, \
        KC_ENT, KC_LEFT, KC_DOWN, KC_DEL, KC_RIGHT, KC_SPC, KC_BSPC, KC_ASTR, _______, _______, KC_COMM, KC_ASTR,  \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, KC_DOT, _______, _______, _______, _______ \
    ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch (biton32(layer_state)) {
            default:
                if (clockwise) {
                    tap_code(KC_LEFT);
                } else {
                    tap_code(KC_RIGHT);
                }
                break;

            case 1:
                if (clockwise) {
                    tap_code(KC_UP);
                } else {
                    tap_code(KC_DOWN);
                }
                break;
        }
    }

    return true;
}
