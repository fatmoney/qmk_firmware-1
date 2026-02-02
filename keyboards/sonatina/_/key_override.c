#define KEY_OVERRIDES \
    X(MOD_MASK_GUI,  KC_Q, G(KC_TAB)) \
    X(MOD_MASK_GUI,  KC_D, G(KC_Q))   \
    X(MOD_MASK_ALT,  KC_Q, A(KC_TAB)) \
    X(MOD_MASK_CTRL, KC_S, C(KC_A))   \

#define X(mod, key, o) \
    const key_override_t _##mod##key = ko_make_basic(mod, key, o);
    KEY_OVERRIDES
#undef X

#define X(mod, key, o) &_##mod##key,
    const key_override_t *key_overrides[] = {KEY_OVERRIDES};
#undef X
