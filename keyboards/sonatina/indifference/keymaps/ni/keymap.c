#include QMK_KEYBOARD_H
#include "quantum_keycodes.h"
#include "action_layer.h"
#include "version.h"
#include "print.h"

enum {
    GRV_TILD,
    TGL_IME,
    P1,
    P2,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [GRV_TILD] = ACTION_TAP_DANCE_DOUBLE(KC_GRV, KC_TILD),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINUS, \
        MT(MOD_LCTL, KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, \
        MT(MOD_LSFT, KC_ENT), KC_Z, KC_X,  KC_C, KC_V, KC_B, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, MT(MOD_RSFT, KC_SLSH), \
        KC_LALT, KC_LGUI, LT(1, KC_SPC), LT(2, KC_ENT), KC_MEDIA_NEXT_TRACK, KC_QUOT \
    ),

    [1] = LAYOUT(
        TD(GRV_TILD), KC_EXLM, KC_UP, LCTL(KC_E), KC_DLR, KC_PERC, KC_CIRC, KC_LCBR, KC_RCBR, KC_AMPR, KC_HASH, KC_UNDS, \
        KC_BSPC, KC_LEFT, KC_DOWN, KC_DEL, KC_RIGHT, KC_SPC, KC_BSPC, KC_LPRN, KC_RPRN, KC_EQL, KC_COLN, KC_DQUO, \
        KC_PIPE, KC_BSLS, KC_AT, KC_ASTR, KC_MINUS, KC_PLUS, KC_PLUS, KC_LBRC, KC_RBRC, KC_LT, KC_GT, KC_QUES, \
        _______, _______, _______, _______, P1, RESET \
    ),

    [2] = LAYOUT(
        KC_PLUS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINUS, \
        KC_ENT, KC_LEFT, KC_DOWN, KC_DEL, KC_RIGHT, KC_SPC, KC_BSPC, KC_ASTR, _______, _______, _______, KC_ASTR,  \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, KC_DOT, _______, _______, _______ \
    ),

    [3] = LAYOUT(
        KC_BSPC, KC_5, KC_6, KC_7, KC_8, KC_9, _______, _______, _______, _______, _______, _______, \
        _______, KC_0, KC_1, KC_2, KC_3, KC_4, _______, _______, _______, _______, _______, _______, \
        _______, KC_MINUS, KC_DEL, KC_ENT, KC_LEFT, KC_RIGHT, KC_COMM, KC_PLUS, KC_ASTR, KC_SLSH, _______, _______, \
        _______, _______, KC_DOT, _______, _______, _______ \
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TGL_IME:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL(SS_TAP(X_SPACE)));
            }
            return false;

        case P1:
            if (record->event.pressed) {
                SEND_STRING("qwerty12");
            }
            return false;
    }

    return true;
};
