/*
 * Interrupted: If the state of a dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 */

// int current_action_no_hold_delay_old(tap_dance_state_t *state) {
//     if (state->count == 1) {
//         if (state->pressed) {
//             return HOLD;
//         }  else if (state->interrupted && !state->pressed) {
//             return TAP;
//         }
//     }
//     return state->count;
// }


// int current_action_standard(tap_dance_state_t *state) {
//     if (state->count == 1) {
//         if (state->interrupted || !state->pressed) return TAP;
//         else return HOLD;
//     } else if (state->count == 2 && state->pressed) {
//         return TH;
//     }
//     return state->count;
// }

enum {
    TAP, DTAP, TTAP, HOLD, TH // Tap and Hold
};

// Keycode
typedef struct {
    int tap, dtap, ttap, hold, th;
} td_kc_t;

static int action;

static int user_action(tap_dance_state_t *state) {
    return state->pressed ?
        (state->count == 1 ? HOLD : TH) :
        state->count - 1;

    // if (state->pressed) {
    //     return state->count == 1 ? HOLD : TH;
    // } else if (state->interrupted && !state->pressed) {
    //     return TAP;
    // }
    // return state->count - 1;
}

static void reset_hold(tap_dance_state_t *state, void *user_data) {
    bool is_hold = action == HOLD || action == TH;
    if (!is_hold) return;

    layer_move(0);
    clear_mods();
}

// #define IS_KEYCODE(code) ((code) >= KC_NO && (code) <= QK_USER_31)


static void dance(tap_dance_state_t *state, void *keycodes) {
    // const td_kc_t *kc = (const td_kc_t*)user_data;
    action = user_action(state);
    int keycode = ((int*)keycodes)[action];

    keycode <= 3 ? layer_on(keycode) : // aka MO(layer)
    IS_MODIFIER_KEYCODE(keycode) ? register_code16(keycode) :
    tap_code16(keycode);
}

#define MAP_TAP_DANCE(...) { \
    .fn = { NULL, dance, reset_hold }, \
    .user_data = (void *)&((td_kc_t){ __VA_ARGS__ }) \
}

tap_dance_action_t tap_dance_actions[] = {
    [0] = MAP_TAP_DANCE(KC_SLSH, .hold=KC_QUES),
    [1] = MAP_TAP_DANCE(KC_COLN, .hold=KC_SCLN),
    [2] = MAP_TAP_DANCE(KC_GRV,  .dtap=KC_TILD, .hold=2, .ttap=KC_M, .th=KC_LSFT),
    [3] = MAP_TAP_DANCE(KC_BSLS, .hold=KC_PIPE),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    // Make HOLD input faster by shortening TAPPING_TERM
    // when only using TAP and HOLD (no DTAP or more)
    // これだと次に入力したキーにinterruptされたときにHOLDが入ってしまう
    // つまり()って早うち(TAPPING_TERM以下の時間で)を入力した場合)したときに<)になってしまう
    // 追記
    // のではない。それは正常な動作。ひとつめのキーを入力する際にしっかりはなしてTAPとして認識させないとそうなる
    // 早打ちするとひとつめのキーをHOLDしてふたつめのキーをHOLDして
    // ひとつめのキーを話して二つ目のキーを離すということを無意識にやっているからそうなる
    switch (keycode) {
        case TD(6):
            return TAPPING_TERM;
    }

    return TAPPING_TERM;
}
