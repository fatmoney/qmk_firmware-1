#include "../../../_/_.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT(
        X, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, X,
        X, CTR_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, SFT_DOT, X,
        X, SFT_Z, KC_X, KC_C, KC_V, b, KC_B, KC_N, KC_M, TD(0), KC_TAB, X,
        X, X, X, LT(MOD_LALT, KC_LNG2), CMD_ENT, L1_SPC, L2_ENT, SS, X, X, X
    ),

    LAYOUT(
        X, KC_EQUAL, KC_UP, TD(2), MS_WHLU, MS_WHLD, /**/ TD(3), KC_LCBR, KC_RCBR, _, KC_EXLM, X,
        X, KC_LEFT, KC_DOWN, KC_DEL, KC_RIGHT, KC_SPC, /**/ KC_BSPC, KC_LPRN, KC_RPRN, _, KC_DQUO, X,
        X, KC_LALT, _, _, TD(1), _, /**/ KC_UNDS, KC_LBRC, KC_RBRC, KC_LT, KC_GT, X,
        X, X, X, QK_BOOT, CMD_ENT, L1_SPC, SFT_ENT, _, X, X, X
    ),

    LAYOUT(
        X, _,     KC_P6, KC_P7, KC_P8, KC_P9, /**/ _, _, _, KC_EQUAL, _, X,
        X, KC_P1, KC_P2, KC_P3, KC_P4, KC_P5, /**/ KC_P6, KC_P7, KC_P8, KC_P9, KC_P0, X,
        X, _,     KC_P6, KC_P7, KC_P8, KC_P9, /**/ _, _, _, _, _, X,
        X, X, X, _, _, KC_DOT, _, _, X, X, X
    )
};
