#define _COMBO_DEF(n, o, ...) X(n, o, __VA_ARGS__)
#define COMBO_DEF(o, ...) _COMBO_DEF(__LINE__, o, __VA_ARGS__)
#define COMBO_ID(n) combo_##n

#define X(n, o, ...) \
    const uint16_t PROGMEM COMBO_ID(n)[] = { __VA_ARGS__, COMBO_END };
    #include "combo_defs.h"
#undef X

#define X(n, o, ...) COMBO(COMBO_ID(n), o),
    combo_t key_combos[] = {
        #include "combo_defs.h"
    };
#undef X

#undef COMBO_ID
#undef COMBO_DEF
#undef _COMBO_DEF

uint8_t combo_ref_from_layer(uint8_t layer) {
    return 0; // YOUR BASE LAYER
}

void process_combo_event(uint16_t combo_index, bool pressed) {
    if (!pressed) return;

    combo_index == 1 && layer_state_is(0) ? tap_code16(KC_ESC) : layer_invert(2);
}
