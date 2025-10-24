#include QMK_KEYBOARD_H

enum combos {
    LSCLN,
};

const uint16_t PROGMEM lscln_combo[] = {KC_L, KC_SCLN, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [LSCLN] = COMBO(lscln_combo, KC_ENT),
};

// Tap Dance declarations
enum {
    TD_ESC_CAPS,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_1),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_625(
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINUS, \
      MT(MOD_LCTL, KC_ENT), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, \
      MT(MOD_LSFT, KC_ESC), KC_Z, KC_X,  KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, \
      KC_ALGR, KC_LGUI, LT(1, KC_SPC), TG(2) \
    ),
    [1] = LAYOUT_625(
      KC_TILD, KC_EXLM, KC_UP, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_UNDS, \
      _______, KC_LEFT, KC_DOWN, KC_DEL, KC_RIGHT, KC_SPC, KC_BSPC, TD(TD_ESC_CAPS), KC_RPRN, KC_EQL, KC_COLN, KC_DQUO, \
      _______, XXXXXXX, KC_AT, KC_QUES, KC_GRV, KC_PIPE, KC_PLUS, KC_AMPR, KC_LT, KC_GT, KC_ASTR, \
      XXXXXXX, XXXXXXX, _______, KC_BSLS \
    ),
    [2] = LAYOUT_625(
      _______,  KC_5, KC_6, KC_7, KC_8, KC_9,_______, _______, _______, _______, _______, _______,  \
      _______, KC_1, KC_2, KC_3, KC_4, KC_0, _______, KC_BSPC, _______, _______, _______, _______,  \
      RESET, _______, _______, _______, _______, _______, _______, _______, KC_COMM, KC_DOT, _______, \
      _______, _______, _______, _______ \
    ),
    [3] = LAYOUT_625(
      _______, _______, _______, _______, _______, _______, _______, _______, KC_6, KC_8, _______, _______, \
      _______, _______, _______, _______, KC_0, _______, _______, KC_1, KC_2, KC_3, KC_4, KC_9, \
      _______, _______, _______, _______, _______, _______, KC_5, KC_7, _______, _______, _______, \
      _______, _______, _______, _______ \
    ),
};
