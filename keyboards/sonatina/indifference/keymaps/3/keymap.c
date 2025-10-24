#include QMK_KEYBOARD_H

enum {
    GRV_TILD,
    TGL_IME,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [GRV_TILD] = ACTION_TAP_DANCE_DOUBLE(KC_GRV, KC_TILD),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_3(
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINUS, \
        MT(MOD_LCTL, KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, \
        KC_Q, KC_LSFT, KC_Z, KC_X,  KC_C, KC_V, KC_B, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, \
        KC_LALT, KC_LGUI, LT(1, KC_SPC), KC_BSPC, LT(2, KC_ENT), KC_MEDIA_NEXT_TRACK, KC_QUOT \
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TGL_IME:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL(SS_TAP(X_SPACE)));
            }
            return false;
            break;
    }

    return true;
};
