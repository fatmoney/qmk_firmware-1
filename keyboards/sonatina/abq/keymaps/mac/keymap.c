#include QMK_KEYBOARD_H
#include "quantum_keycodes.h"
#include "action_layer.h"
#include "version.h"
#include "vim.h"
#include "print.h"

#include "tap_dance.h"

enum {
    TGL_IME = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_mac(
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINUS, \
      MT(MOD_LCTL, KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, \
      KC_LSFT, KC_Z, KC_X,  KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, MT(MOD_RSFT, KC_SLSH), \
      KC_ALGR, KC_LGUI, LT(1, KC_SPC), LT(2, KC_ENT),  TGL_IME, KC_MEDIA_FAST_FORWARD \
    ),

    [1] = LAYOUT_mac(
      TD(GRV_TILD), KC_EXLM, KC_UP, LCTL(KC_E), KC_DLR, KC_PERC, KC_CIRC, KC_LCBR, KC_RCBR, KC_AMPR, KC_HASH, KC_UNDS, \
      LCTL(KC_A), KC_LEFT, KC_DOWN, KC_DEL, KC_RIGHT, KC_SPC, KC_BSPC, KC_LPRN, KC_RPRN, KC_EQL, KC_COLN, KC_DQUO, \
      KC_PIPE, KC_BSLS, KC_AT, KC_ASTR, KC_MINUS, KC_PLUS, KC_LBRC, KC_RBRC, KC_LT, KC_GT, KC_QUES, \
      _______, _______, _______, _______, LCTL(KC_K), _______ \
    ),

    [2] = LAYOUT_mac(
      KC_0, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DOT, \
      _______, KC_LEFT, KC_DOWN, KC_DEL, KC_RIGHT, KC_SPC, KC_BSPC, KC_PLUS, KC_MINUS, KC_ASTR, KC_COLN, KC_COMM,  \
      RESET, _______, _______, _______, KC_CIRC, KC_SLSH, KC_AMPR, KC_PIPE, KC_COMM, KC_PERC, KC_EXLM,  \
      _______, _______, _______, _______, _______, _______ \
    ),

    [3] = LAYOUT_mac(
      KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, \
      KC_PSCR, KC_LANG5, KC_HOME, KC_PGUP, KC_END, KC_PGDN, _______, _______, _______, _______, _______, \
      KC_SLCK, KC_PAUS, KC_INS, _______, _______, _______, _______, _______, _______, _______, _______, _______,  \
      _______, _______, _______, _______, _______, _______ \
    ),

    [4] = LAYOUT_mac(
      KC_VOLU, KC_MNXT, KC_MPRV, KC_VOLD, KC_MPLY, KC_WBAK, _______, _______, _______, _______, _______, _______,  \
      KC_BRIU, KC_BRID, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______ \
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool SHIFTED = (keyboard_report->mods & MOD_BIT(KC_LSFT)) |
                   (keyboard_report->mods & MOD_BIT(KC_RSFT));

    uprintf("%s", SHIFTED);
    uprintf("0");
    switch (keycode) {
        case VIM_E:
            if (record->event.pressed) {
                VIM_DELETE_INNER_WORD(); break;
            }
            return false;

        // case VIM_I:
        //     if (record->event.pressed) {
        //         switch (VIM_QUEUE) {
        //             case KC_NO: layer_on(INSERT_MODE); break;
        //         }
        //     }
        //     return false;

        case VIM_A:
          if (record->event.pressed) { SHIFTED ? VIM_APPEND_LINE() : VIM_APPEND(); }
          return false;

        case VIM_DD:
          if (record->event.pressed) {
             VIM_DELETE_WHOLE_LINE();
             break;
          }
          return false;
        case TGL_IME: if (record->event.pressed) { SEND_STRING(SS_LCTL(SS_TAP(X_SPACE))); } break;

    }
    return true;
}

// LEADER_EXTERNS();

// void matrix_scan_user(void) {
//   LEADER_DICTIONARY() {
//     leading = false;
//     leader_end();

//     SEQ_ONE_KEY(KC_F) {
//       SEND_STRING(LGUI(KC_RIGHT));
//     }
//   }
// }
