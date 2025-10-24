#include "../../../_/_.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS,
        CTR_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, TD1, KC_QUOT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, x, KC_SLSH,
        KC_LALT, CMD_ENT, L1_SPC, KC_P0, L2_ENT, KC_0, SS
    ),

    [1] = LAYOUT(
        KC_DLR, KC_EXLM, KC_UP, KC_DQUO, KC_QUOT, KC_PERC, KC_AT, KC_LCBR, KC_RCBR, KC_AMPR, KC_HASH, TD7,
        LT(2, KC_BSPC), LT(3, KC_LEFT), KC_DOWN, KC_DEL, KC_RIGHT, KC_SPC, KC_BSPC, KC_LPRN, KC_RPRN, KC_PEQL, _, _,
        KC_PMNS, KC_PPLS, KC_ASTR, TD2, KC_SCLN, KC_COLN, KC_UNDS, KC_LBRC, KC_RBRC, KC_LT, KC_GT, x, TD11,
        _, _, x, x, ITP, ITP, KC_CIRC
    ),

    [2] = LAYOUT(
        _, _, KC_ASTR, KC_MINS, _, _,                                 _, _, _, _, _, _,
        _, KC_P1, KC_P2, KC_P3, KC_P4, KC_P5,         KC_P6, KC_P7, KC_P8, KC_P9, KC_P0, _,
        _, _, _, _, _, _,               x, _, _, _, _, _, _,
        KC_CAPS, _, KC_DOT,                        x, _, _, QK_BOOT
    ),

    [3] = LAYOUT(
        _, _, _, _, _, _, _, _, _, _, _, _,
        _, _, _, MS_WHLU, MS_WHLD, _, _, _, _, _, _, _,
        _, _, _, _, _, _, _, _, _, _, _, _, _,
        _, _, _, _, _, _, _
    ),

    [4] = LAYOUT( // NUMPAD
        KC_BSPC, TD4, KC_P6, KC_P7, KC_P8, KC_P9,        x, x, x, x, x, x,
        TD1, KC_P1, KC_P2, KC_P3, KC_P4, KC_P5,          x, x, x, x, x, x,
        KC_PMNS, KC_PPLS, KC_PAST, KC_PSLS, TD5, KC_EQL, x, x, x, x, x, x, x,
        KC_CIRC, KC_PERC, KC_P0,                         x, x, x, x
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    layer_state_is(0) ? (clockwise ? tap_code(KC_LEFT) : tap_code(KC_RIGHT)) :
    // layer_state_is(0) ? (clockwise ? tap_code(KC_WH_D) : tap_code(KC_WH_U)) :
    layer_state_is(1) ? (clockwise ? tap_code(KC_UP) : tap_code(KC_DOWN)) :
    NULL;

    return true;
}
