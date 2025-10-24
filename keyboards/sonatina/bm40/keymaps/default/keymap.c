#include "../../../_/_.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        x, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, x,
        x, MT(MOD_LCTL, KC_A), KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, MT(MOD_RSFT, KC_DOT), x,
        x, MT(MOD_LSFT, KC_Z), KC_X, KC_C, KC_V, KC_B, KC_B, KC_N, KC_M, TD2, KC_TAB, x,
        x, x, x, KC_LALT, CMD_ENT, L1_SPC, L2_ENT, SS, x, x, x
    ),

    [1] = LAYOUT(
        x, TD11, KC_UP, KC_DQUO, KC_QUOT, _, /**/ _, KC_LCBR, KC_RCBR, KC_MINUS, KC_AMPR, x,
        x, KC_LEFT, KC_DOWN, KC_DEL, KC_RIGHT, KC_SPC,   /**/ KC_BSPC, KC_LPRN, KC_RPRN, KC_EQUAL, KC_DQUO, x,
        x, KC_PPLS, _,  KC_ASTR, TD7, TD6,                     /**/ KC_UNDS, KC_LBRC, KC_RBRC, KC_LT, KC_GT, x,
        x, x, x, _, CMD_ENT, L1_SPC, SFT_ENT, _, x, x, x
    ),

    [2] = LAYOUT(
        x, _, _, _, KC_LT, KC_GT, /**/ _, KC_EQUAL, KC_ASTR, KC_MINS, KC_PPLS, x,
        x, KC_P1, KC_P2, KC_P3, KC_P4, KC_P5, /**/ KC_P6, KC_P7, KC_P8, KC_P9, KC_P0, x,
        x, KC_DLR, KC_PERC, KC_CIRC, KC_HASH, KC_EXLM, /**/ _, _, _, _, KC_AMPR, KC_AT,
        x, x, x, KC_CAPS, _, KC_DOT, _, QK_BOOT, x, x, x
    )
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
        'L', 'L', 'L', 'L', 'L', 'L',  'L', 'L', 'L', 'L', 'L', 'L',
        'L', 'L', 'L', 'L', 'L', 'L',  'L', 'L', 'L', 'L', 'L', 'L',
        'L', 'L', 'L', 'L', 'L', 'L',  'L', 'L', 'L', 'L', 'L', 'L',
        'L', 'L', 'L', 'L', 'L',     'L',  'L', 'L', 'L', 'L', 'L'
    );
