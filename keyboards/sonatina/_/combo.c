#define COMBOS \
    X(KC_BSPC, KC_D, KC_F) \
    X(0,       KC_S, KC_D) \
    X(KC_HASH, KC_E, KC_F) \
    X(KC_MINS, KC_E, KC_W) \
    X(KC_PERC, KC_C, SFT_Z) \
    X(KC_ASTR, KC_C, KC_V) \
    X(KC_SLSH, KC_X, SFT_Z) \
    X(KC_PLUS, KC_X, KC_C) \
    X(KC_CIRC, KC_T, KC_Y) \
    X(KC_DLR,  KC_Q, KC_W) \
    X(KC_AT,   KC_O, KC_P) \
    X(KC_QUOT, KC_L, SFT_DOT) \
    X(KC_COMM, KC_L, KC_K) \
    X(KC_AMPR, KC_R, KC_W) \

#define X(o, i1, i2) \
    const uint16_t PROGMEM _##o##i1##i2[] = { i1, i2, 0 };
    COMBOS
#undef X

#define X(o, i1, i2) \
    COMBO(_##o##i1##i2, o),
    combo_t key_combos[] = { COMBOS };
#undef X

uint8_t combo_ref_from_layer(uint8_t layer) { return 0; }

void process_combo_event(uint16_t combo_index, bool pressed) {
    if (!pressed) return;

    combo_index == 1 && layer_state_is(0) ? tap_code16(KC_ESC) : layer_invert(2);
}
