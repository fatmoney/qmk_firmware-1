#define DEF_COMBO(o, ...) X(__LINE__, o, __VA_ARGS__)
#define COMBO_ID(n) combo_##n

#define X(n, o, ...) \
    const uint16_t PROGMEM COMBO_ID(n)[] = { __VA_ARGS__, COMBO_END };
    #include "combo_defs"
#undef X

#define X(n, o, ...) COMBO(COMBO_ID(n), o),
    combo_t key_combos[] = {
        #include "combo_defs"
    };
#undef X

#undef COMBO_ID
#undef DEF_COMBO

uint8_t combo_ref_from_layer(uint8_t layer) {
    return 0; // Base Layer Index
}

void process_combo_event(uint16_t combo_index, bool pressed) {
    if (!pressed) return;

    combo_index == 1 && layer_state_is(0) ? tap_code16(KC_ESC) : layer_invert(2);

    // if (!layer_state_is(3)) return;

    // if (combo_index == 14) { tap_code16(KANA); tap_code16(KC_A); tap_code16(EISU); }
}
