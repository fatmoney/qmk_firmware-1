#include "../../../_/_.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS,
        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
        KC_LALT, CMD_ENT, L1_SPC, KC_P0, SFT_ENT, TG(5), QK_BOOT
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    layer_state_is(0) ? (clockwise ? tap_code(KC_LEFT) : tap_code(KC_RIGHT)) :
    layer_state_is(1) ? (clockwise ? tap_code(KC_UP) : tap_code(KC_DOWN)) :
    NULL;

    return true;
}
