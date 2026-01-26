#define COMBOS \
    CMB(KC_BSPC, KC_D, KC_F) \
    CMB(KC_NO,   KC_S, KC_D) \
    CMB(KC_HASH, KC_E, KC_F) \
    CMB(KC_MINS, KC_E, KC_W) \
    CMB(KC_PERC, KC_C, SFT_Z) \
    CMB(KC_ASTR, KC_C, KC_V) \
    CMB(KC_SLSH, KC_X, SFT_Z) \
    CMB(KC_PLUS, KC_X, KC_C) \
    CMB(KC_CIRC, KC_T, KC_Y) \
    CMB(KC_DLR,  KC_Q, KC_W) \
    CMB(KC_AT,   KC_O, KC_P) \
    CMB(KC_QUOT, KC_L, SFT_DOT) \
    CMB(KC_COMM, KC_L, KC_K) \
    CMB(KC_AMPR, KC_R, KC_W) \

#define CMB(o, i1, i2) const uint16_t PROGMEM _##o##i1[] = {i1, i2, COMBO_END};
    COMBOS
#undef CMB

#define CMB(o, i1, i2) COMBO(_##o##i1, o),
    combo_t key_combos[] = {COMBOS};
#undef CMB

void process_combo_event(uint16_t combo_index, bool pressed) {
    if (!pressed) return;

    switch (combo_index) {
        case 1:
            layer_state_is(0) ? tap_code16(KC_ESC) : layer_invert(2);
            break;
    }
}
