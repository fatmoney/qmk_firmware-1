#include "../../../_/_.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT(
        0, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, 0,
        0, CTR_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, SFT_DOT, 0,
        0, SFT_Z, KC_X, KC_C, KC_V, KC_B, KC_B, KC_N, KC_M, TD(0), KC_TAB, 0,
        0, 0, 0, KC_LALT, CMD_ENT, L1_SPC, L2_ENT, SS, 0, 0, 0
    ),

    LAYOUT(
        0, _, KC_UP, TD(2), MS_WHLU, MS_WHLD, /**/ TD(3), KC_LCBR, KC_RCBR, KC_EQUAL, KC_EXLM, 0,
        0, KC_LEFT, KC_DOWN, KC_DEL, KC_RIGHT, KC_SPC, /**/ KC_BSPC, KC_LPRN, KC_RPRN, _, KC_DQUO, 0,
        0, KC_LALT, _, _, TD(1), _, /**/ KC_UNDS, KC_LBRC, KC_RBRC, KC_LT, KC_GT, 0,
        0, 0, 0, QK_BOOT, CMD_ENT, L1_SPC, SFT_ENT, _, 0, 0, 0
    ),

    LAYOUT(
        0, _,    KC_6, KC_7, KC_8, KC_9, /**/ _, _, _, KC_EQUAL, _, 0,
        0, KC_1, KC_2, KC_3, KC_4, KC_5, /**/ KC_6, KC_7, KC_8, KC_9, KC_0, 0,
        0, KC_0, KC_6, KC_7, KC_8, KC_9, /**/ _, _, _, _, _, 0,
        0, 0, 0, _, _, KC_DOT, _, _, 0, 0, 0
    )
};
