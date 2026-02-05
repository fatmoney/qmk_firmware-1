enum {
    TAP, DTAP, TTAP, HOLD, TH // Tap & Hold
};

typedef struct {
    int tap, dtap, ttap, hold, th;
} td_kc_def_t;

static int action;

static int user_action(tap_dance_state_t *state) {
    return state->pressed ? (state->count == 1 ? HOLD : TH) : state->count - 1;
};

static void reset_hold(tap_dance_state_t *state, void *user_data) {
    if (action != HOLD && action != TH) return;

    // layer_move(0);
    layer_clear();
    clear_mods();
}

static void map(tap_dance_state_t *state, void *keycodes) {
    action = user_action(state);
    int keycode = ((int*)keycodes)[action];

    keycode <= 3 ? layer_on(keycode) : // aka MO(layer)
    IS_MODIFIER_KEYCODE(keycode) ? register_code16(keycode) :
    tap_code16(keycode);
}

#define DANCE(...) { \
    .fn = { NULL, map, reset_hold }, \
    .user_data = (void *)&((td_kc_def_t){ __VA_ARGS__ }) \
}

tap_dance_action_t tap_dance_actions[] = {
    DANCE(KC_SLSH, .hold=KC_QUES),
    DANCE(KC_COLN, .hold=KC_SCLN),
    DANCE(KC_GRV,  .hold=KC_TILD, .th=2),
    DANCE(KC_BSLS, .hold=KC_PIPE),
    // DANCE(KC_X, .hold=G(KC_LBRC)),
};

#undef DANCE

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    return IS_QK_TAP_DANCE(keycode) ? 100 : TAPPING_TERM;
}
