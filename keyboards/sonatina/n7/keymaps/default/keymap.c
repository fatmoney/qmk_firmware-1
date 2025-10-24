#include QMK_KEYBOARD_H

#include "print.h"
#include "keycode.h"
#include "quantum.h"
#include "quantum_keycodes.h"

#define PRESS(keycode) register_code16(keycode)
#define RELEASE(keycode) unregister_code16(keycode)

uint16_t VIM_QUEUE = KC_NO;

// Macro Declarations
enum custom_keycodes {
    BROWSER_BACK = SAFE_RANGE,
    TGL_IME,
    PRN,
    BRC,
    CBR,
    BOL,
    EOL,
    A_TO_1,
    S_TO_2,
    D_TO_3,
    F_TO_4,
    G_TO_5,
    H_TO_6,
    J_TO_7,
    K_TO_8,
    L_TO_9,
    P_TO_0,
    HP_TO_US,
    SQ_TO_DQ,
    SL_TO_BS,
    CM_TO_LT,
    DT_TO_GT,
    LPR_TO_LCB,
    RPR_TO_RCB,
    EQ_TO_PLS,
    EXQ_TO_QUE,
    VIM_E,
};

void TAP(uint16_t keycode) {
    PRESS(keycode);
    RELEASE(keycode);
}

void ALT(uint16_t keycode) {
    PRESS(KC_LALT);
    TAP(keycode);
    RELEASE(KC_LALT);
}

void VIM_LEADER(uint16_t keycode) {
    VIM_QUEUE = keycode;
}

void VIM_END(void) {
    register_code16(KC_LALT);
    register_code16(KC_RIGHT);
    unregister_code16(KC_RIGHT);
    unregister_code16(KC_LALT);
}

void VIM_LEFT(void) {
    VIM_LEADER(KC_NO);
    TAP(KC_LEFT);
}

// Tap Dance Declarations
enum {
    H_BARS = 0,
    CLNS,
    RVS_CLNS,
    EXQU,
    SLBS,
    QUOS,
    ONE,
};
qk_tap_dance_action_t tap_dance_actions[] = {
    [H_BARS] = ACTION_TAP_DANCE_DOUBLE(KC_MINUS, KC_UNDERSCORE),
    [CLNS] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN),
    [RVS_CLNS] = ACTION_TAP_DANCE_DOUBLE(KC_COLN, KC_SCLN),
    [EXQU] = ACTION_TAP_DANCE_DOUBLE(KC_EXLM, KC_QUES),
    [SLBS] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_BSLS),
    [QUOS] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DQUO),
    [ONE] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_1),
};

void remap_key_on_hold(keyrecord_t *record, uint16_t from, uint16_t to) {
    static uint16_t my_hash_timer;
    
    // implement this later
    // https://github.com/qmk/qmk_firmware/issues/303#issuecomment-217328415
    
    if (record->event.pressed) {
        my_hash_timer = timer_read();
    } else {
        if (timer_elapsed(my_hash_timer) > 200) {
            tap_code16(to);
        } else {
            tap_code16(from);
        }
    }
};

// custom macro definitions
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      case BROWSER_BACK: if (record->event.pressed) { SEND_STRING(SS_LGUI("[")); } break;
      case TGL_IME: if (record->event.pressed) { SEND_STRING(SS_LGUI(SS_TAP(X_SPACE))); } break;
      case PRN: if (record->event.pressed) { SEND_STRING("()"); } break;
      case BRC: if (record->event.pressed) { SEND_STRING("[]"); } break;
      case CBR: if (record->event.pressed) { SEND_STRING("{}"); } break;
      case BOL: if (record->event.pressed) { SEND_STRING(SS_LCTRL("a")); } break;
      case EOL: if (record->event.pressed) { SEND_STRING(SS_LCTRL("e")); } break;
      case A_TO_1: remap_key_on_hold(record, KC_A, KC_1); break;
      case S_TO_2: remap_key_on_hold(record, KC_S, KC_2); break;
      case D_TO_3: remap_key_on_hold(record, KC_D, KC_3); break;
      case F_TO_4: remap_key_on_hold(record, KC_F, KC_4); break;
      case G_TO_5: remap_key_on_hold(record, KC_G, KC_5); break;
      case H_TO_6: remap_key_on_hold(record, KC_H, KC_6); break;
      case J_TO_7: remap_key_on_hold(record, KC_J, KC_7); break;
      case K_TO_8: remap_key_on_hold(record, KC_K, KC_8); break;
      case L_TO_9: remap_key_on_hold(record, KC_L, KC_9); break;
      case P_TO_0: remap_key_on_hold(record, KC_P, KC_0); break;
      case HP_TO_US: remap_key_on_hold(record, KC_MINUS, KC_UNDERSCORE); break;
      case SQ_TO_DQ: remap_key_on_hold(record, KC_QUOT, KC_DQUO); break;
      case SL_TO_BS: remap_key_on_hold(record, KC_SLSH, KC_BSLS); break;
      case CM_TO_LT: remap_key_on_hold(record, KC_COMM, KC_LT); break;
      case DT_TO_GT: remap_key_on_hold(record, KC_DOT, KC_GT); break;
      case LPR_TO_LCB: remap_key_on_hold(record, KC_LPRN, KC_LCBR); break;
      case RPR_TO_RCB: remap_key_on_hold(record, KC_RPRN, KC_RCBR); break;
      case EQ_TO_PLS: remap_key_on_hold(record, KC_EQL, KC_PLUS); break;
      case EXQ_TO_QUE: remap_key_on_hold(record, KC_EXCLAIM, KC_QUESTION); break;
      
      case VIM_E:
          if (record->event.pressed) {
              switch (VIM_QUEUE) {
                  case KC_NO: VIM_END(); break;
              }
          }
          return false;
    }
  
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT(
        KC_TAB,  KC_Q,    KC_W,    KC_E, KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_MINUS, \
        LT(2, KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, \
        KC_BSLS, KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,  \
        KC_LALT, KC_LGUI, LT(1, KC_SPC), MT(MOD_LSFT, KC_ENT), KC_RALT, TGL_IME \
    ),
    LAYOUT(
        _______, KC_1,   KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,  KC_0, KC_UNDERSCORE, \
        _______, KC_LEFT, KC_UP, KC_DEL,  KC_RIGHT, KC_SPC, KC_BSPC, KC_LPRN, KC_RPRN, KC_EQL,  KC_COLN, KC_DQUO, \
        _______, _______, XXXXXXX, KC_DOWN, KC_GRV, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, _______, _______, KC_BSLS, \
        RESET, _______, _______, _______, _______, _______ \
    ),
    LAYOUT(
      _______, _______, _______, _______, _______, _______, _______, KC_1, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______ \
    )
};