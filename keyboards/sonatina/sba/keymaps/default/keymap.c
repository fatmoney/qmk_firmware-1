#include QMK_KEYBOARD_H
#include "quantum_keycodes.h"
#include "action_layer.h"
#include "version.h"
#include "print.h"

enum {
    GRV_TILD,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [GRV_TILD] = ACTION_TAP_DANCE_DOUBLE(KC_GRV, KC_TILD),
};

/*
[0] = boring(
  KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINUS, \
  MT(MOD_LCTL, KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_ENTER, \
  KC_LSFT, KC_Z, KC_X,  KC_C, KC_V, KC_B, KC_B, KC_N, KC_M, MT(MOD_RSFT, KC_SLSH), \
  KC_LGUI, KC_SPC, RESET \
)
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = ni(
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINUS, \
      MT(MOD_LCTL, KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, \
      KC_LSFT, KC_Z, KC_X,  KC_C, KC_V, KC_B, KC_B, KC_N, KC_M, MT(MOD_RSFT, KC_SLSH), \
      RGB_TOG, KC_SPC, RESET \
    )
};
