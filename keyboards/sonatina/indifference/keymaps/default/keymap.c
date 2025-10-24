#include QMK_KEYBOARD_H
#include "quantum_keycodes.h"
#include "action_layer.h"
#include "version.h"
#include "print.h"

enum {
    GRV_TILD,
    TGL_IME,
    NUMPAD
};

enum {
    SINGLE_TAP,
    SINGLE_HOLD,
};

typedef struct {
    int action;
    int prev_layer;
} tap;

static tap tap_state = {
    .action = SINGLE_TAP,
    .prev_layer = 0
};

int cur_dance(qk_tap_dance_state_t *state) {
    int current_state = SINGLE_HOLD;

    if (state->count == 1) {
        if (state->interrupted || !state->pressed) {
            current_state = SINGLE_TAP;
        } else {
            current_state = SINGLE_HOLD;
        }
    }

    return current_state;
}

void numpad_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.action = cur_dance(state);
    tap_state.prev_layer = biton32(layer_state);

    if (state->interrupted) {
        register_code(KC_LSHIFT);
        return;
    }

    switch(tap_state.action) {
        case SINGLE_TAP:
            layer_on(3);
            break;

        case SINGLE_HOLD:
            register_code(KC_LSHIFT);
            break;
    }
}

void numpad_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->interrupted) {
        unregister_code(KC_LSHIFT);
        return;
    }

    switch (tap_state.action) {
        case SINGLE_TAP:
            if (tap_state.prev_layer == 3) {
                layer_off(3);
            }
            break;

        case SINGLE_HOLD:
            unregister_code(KC_LSHIFT);
            break;
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [GRV_TILD] = ACTION_TAP_DANCE_DOUBLE(KC_GRV, KC_TILD),
    [NUMPAD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, numpad_finished, numpad_reset)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINUS, \
        MT(MOD_LCTL, KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, \
        KC_LSFT, KC_Z, KC_X,  KC_C, KC_V, KC_B, KC_B, KC_N, KC_M, KC_COMM, KC_SLSH, MT(MOD_RSFT, KC_DOT), \
        KC_LALT, KC_LGUI, LT(1, KC_SPC), LT(2, KC_ENT), TGL_IME, KC_0 \
    ),

    [1] = LAYOUT(
        TD(GRV_TILD), KC_EXLM, KC_UP, LCTL(KC_E), KC_DLR, KC_PERC, KC_CIRC, KC_LCBR, KC_RCBR, KC_AMPR, KC_HASH, KC_UNDS, \
        LCTL(KC_A), KC_LEFT, KC_DOWN, KC_DEL, KC_RIGHT, KC_SPC, KC_BSPC, KC_LPRN, KC_RPRN, KC_EQL, KC_COLN, KC_DQUO, \
        KC_PIPE, KC_BSLS, KC_AT, KC_ASTR, KC_MINUS, KC_PLUS, KC_PLUS, KC_LBRC, KC_RBRC, KC_LT, KC_GT, KC_QUES, \
        _______, _______, _______, _______, _______, RESET \
    ),

    [2] = LAYOUT(
        KC_0, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DOT, \
        _______, KC_LEFT, KC_DOWN, KC_DEL, KC_RIGHT, KC_SPC, KC_BSPC, KC_PLUS, KC_MINUS, KC_ASTR, KC_COLN, KC_COMM,  \
        _______, _______, _______, _______, KC_CIRC, KC_SLSH, KC_AMPR, KC_PIPE, KC_COMM, KC_PERC, KC_EXLM, _______, \
        _______, _______, _______, _______, _______, _______ \
    ),

    [3] = LAYOUT(
        KC_BSPC, KC_5, KC_6, KC_7, KC_8, KC_9, _______, _______, _______, _______, _______, _______, \
        _______, KC_0, KC_1, KC_2, KC_3, KC_4, _______, _______, _______, _______, _______, _______, \
        _______, KC_MINUS, KC_DEL, KC_ENT, KC_LEFT, KC_RIGHT, KC_COMM, KC_PLUS, KC_ASTR, KC_SLSH, _______, _______, \
        _______, _______, KC_DOT, _______, _______, _______ \
    ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch (biton32(layer_state)) {
            case 1:
                if (clockwise) {
                    tap_code(KC_UP);
                } else {
                    tap_code(KC_DOWN);
                }
                break;

            // case 3:
            default:
                if (clockwise) {
                    tap_code(KC_MS_WH_DOWN);
                } else {
                    tap_code(KC_MS_WH_UP);
                }
                break;

        //     default:
        //         if (clockwise) {
        //             tap_code(KC_LEFT);
        //         } else {
        //             tap_code(KC_RIGHT);
        //         }
        //         break;
        }
    }

    return true;
}

// layer_state_t layer_state_set_user(layer_state_t state) {
//   return update_tri_layer_state(state, 1, 2, 3);
// }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    print("here");
    if (biton32(layer_state) == 3 && get_mods() && record->event.pressed) {
        if (get_mods() & MOD_BIT(KC_LGUI)) {
            uint16_t row = record->event.key.row;
            uint16_t col = record->event.key.col;
            layer_on(0);
            tap_code(pgm_read_word(&keymaps[0][row][col]));
            layer_off(0);
            return false;
        }
    }

    switch (keycode) {
        case TGL_IME:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL(SS_TAP(X_SPACE)));
            }
            return false;
            break;
    }

    return true;
};
