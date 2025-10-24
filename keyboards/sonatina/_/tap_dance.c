enum action_types {
    HOLD,
    TAP,
    DTAP,
    TTAP,
};

int action;

/*
 * Interrupted: If the state of a dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 */

int current_action_ndh(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->pressed) {
            // No-delay HOLD
            return HOLD;
        }  else if (state->interrupted && !state->pressed) {
            return TAP;
        }
    }
    return state->count;
}

int current_action(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TAP;
        else return HOLD;
    }
    return state->count;
}

void reset_shift(tap_dance_state_t *state, void *user_data) {
    if (action == HOLD) unregister_code(KC_LSFT);
}

void td1(tap_dance_state_t *state, void *user_data) {
    action = current_action_ndh(state);
    action == TAP  ? tap_code(KC_DOT) :
    action == DTAP ? tap_code(KC_COMM) :
    action == HOLD ? register_code(KC_LSFT) :
    NULL;
}

void td2(tap_dance_state_t *state, void *user_data) {
    action = current_action(state);
    action == TAP  ? tap_code(KC_SLSH) :
    action == HOLD ? tap_code16(KC_QUES) :
    NULL;
}

void td3(tap_dance_state_t *state, void *user_data) {
    action = current_action(state);
    action == TAP  ? tap_code16(KC_DQUO) :
    action == HOLD ? tap_code(KC_QUOT) :
    NULL;
}

void td4(tap_dance_state_t *state, void *user_data) {
    action = current_action(state);
    action == HOLD ? tap_code16(KC_PAST) :
    action == TAP  ? tap_code(KC_PPLS) :
    action == DTAP ? tap_code(KC_PMNS) :
    action == TTAP ? tap_code(KC_PSLS) :
    NULL;
}

void td5(tap_dance_state_t *state, void *user_data) {
    action = current_action(state);
    action == TAP  ? tap_code16(KC_LPRN) :
    action == HOLD ? tap_code16(KC_RPRN) :
    NULL;
}

void td7(tap_dance_state_t *state, void *user_data) {
    action = current_action(state);
    action == TAP  ? tap_code(KC_GRV) :
    action == HOLD ? tap_code16(KC_TILD) :
    NULL;
}

void td8(tap_dance_state_t *state, void *user_data) {
    action = current_action(state);
    action == TAP  ? tap_code16(KC_LCBR) : // {
    action == HOLD ? tap_code(KC_LBRC) : // [
    NULL;
}

void td9(tap_dance_state_t *state, void *user_data) {
    action = current_action(state);
    action == TAP  ? tap_code16(KC_RCBR) : // }
    action == HOLD ? tap_code(KC_RBRC) : // ]
    NULL;
}

void td10(tap_dance_state_t *state, void *user_data) {
    action = current_action(state);
    action == TAP  ? tap_code16(KC_UNDS) :
    action == HOLD ? register_code(KC_LSFT) :
    NULL;
}

void td11(tap_dance_state_t *state, void *user_data) {
    action = current_action(state);
    action == TAP  ? tap_code(KC_BSLS) :
    action == HOLD ? tap_code16(KC_PIPE) :
    NULL;
}

void td12(tap_dance_state_t *state, void *user_data) {
    action = current_action(state);
    action == TAP  ? tap_code(KC_A) :
    action == DTAP ? tap_code16(S(KC_A)) :
    action == HOLD ? register_code(KC_LSFT) :
    NULL;
}

void td13(tap_dance_state_t *state, void *user_data) {
    action = current_action(state);
    action == HOLD ? tap_code16(C(KC_E)) :
    action == TAP  ? tap_code(KC_RIGHT) :
    NULL;
}

// this doesnt work for some reason
void td14(tap_dance_state_t *state, void *user_data) {
    action = current_action(state);
    action == HOLD ? tap_code16(C(KC_A)) :
    action == TAP  ? tap_code(KC_LEFT) :
    NULL;
}

void td15(tap_dance_state_t *state, void *user_data) {
    action = current_action(state);
    action == TAP  ? tap_code(KC_ENT) :
    action == HOLD ? set_oneshot_mods(MOD_LSFT) :
    NULL;
}

void td16(tap_dance_state_t *state, void *user_data) {
    action = current_action_ndh(state);
    action == TAP  ? tap_code(KC_A) :
    action == HOLD ? register_code(KC_LSFT) :
    NULL;
}

void td17(tap_dance_state_t *state, void *user_data) {
    action = current_action_ndh(state);
    action == TAP  ? tap_code(KC_Z) :
    action == HOLD ? register_code(KC_LCTL) :
    NULL;
}

void td18(tap_dance_state_t *state, void *user_data) {
    action = current_action_ndh(state);
    action == TAP  ? tap_code16(G(KC_LBRC)) :
    action == HOLD ? register_code(KC_LCTL) :
    NULL;
}

void td6(tap_dance_state_t *state, void *user_data) {
    action = current_action_ndh(state);
    action == TAP  ? tap_code16(KC_COLN) :
    action == HOLD ? tap_code(KC_SCLN) :
    NULL;
}



enum {
    _TD1, _TD2, _TD3, _TD4, _TD5, _TD6, _TD7, _TD8, _TD9, _TD10,
    _TD11, _TD12, _TD13, _TD14, _TD15, _TD16, _TD17, _TD18, _TD19, _TD20,
    _TD21, _TD22, _TD23, _TD24, _TD25, _TD26, _TD27, _TD28, _TD29, _TD30,
};

tap_dance_action_t tap_dance_actions[] = {
    [_TD1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td1, reset_shift),
    [_TD2] = ACTION_TAP_DANCE_FN(td2),
    [_TD3] = ACTION_TAP_DANCE_FN(td3),
    [_TD4] = ACTION_TAP_DANCE_FN(td4),
    [_TD5] = ACTION_TAP_DANCE_FN(td5),
    [_TD6] = ACTION_TAP_DANCE_FN(td6),
    [_TD7] = ACTION_TAP_DANCE_FN(td7),
    [_TD8] = ACTION_TAP_DANCE_FN(td8),
    [_TD9] = ACTION_TAP_DANCE_FN(td9),
    [_TD10] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td10, reset_shift),
    [_TD11] = ACTION_TAP_DANCE_FN(td11),
    [_TD12] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td12, reset_shift),
    [_TD13] = ACTION_TAP_DANCE_FN(td13),
    [_TD14] = ACTION_TAP_DANCE_FN(td14),
    // [_TD15] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td15, reset_shift),
    [_TD15] = ACTION_TAP_DANCE_FN(td15),
    [_TD16] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td16, reset_shift),
    [_TD17] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td17, reset_shift),
    [_TD18] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td18, reset_shift),
};

const uint16_t TD1 = TD(_TD1);
const uint16_t TD2 = TD(_TD2);
const uint16_t TD3 = TD(_TD3);
const uint16_t TD4 = TD(_TD4);
const uint16_t TD5 = TD(_TD5);
const uint16_t TD6 = TD(_TD6);
const uint16_t TD7 = TD(_TD7);
const uint16_t TD8 = TD(_TD8);
const uint16_t TD9 = TD(_TD9);
const uint16_t TD10 = TD(_TD10);
const uint16_t TD11 = TD(_TD11);
const uint16_t TD12 = TD(_TD12);
const uint16_t TD13 = TD(_TD13);
const uint16_t TD14 = TD(_TD14);
const uint16_t TD15 = TD(_TD15);
const uint16_t TD16 = TD(_TD16);
const uint16_t TD17 = TD(_TD17);
const uint16_t TD18 = TD(_TD18);

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
        case TD1:
        case TD2:
        case TD3:
        case TD6:
        case TD7:
        case TD10:
        case TD11:
            return 120;
        case TD8:
        case TD9:
            return 90;
        case TD13:
        case TD14:
            return 90;
    }

    return TAPPING_TERM;
}
