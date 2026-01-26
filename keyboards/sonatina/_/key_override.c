#define KEY_OVERRIDES \
    KO(MOD_MASK_GUI,  KC_Q, G(KC_TAB)) \
    KO(MOD_MASK_GUI,  KC_D, G(KC_Q))   \
    KO(MOD_MASK_ALT,  KC_Q, A(KC_TAB)) \
    KO(MOD_MASK_CTRL, KC_S, C(KC_A))   \

#define KO(mod, key, o) \
    const key_override_t _##mod##key = ko_make_basic(mod, key, o);
    KEY_OVERRIDES
#undef KO

#define KO(mod, key, o) &_##mod##key,
    const key_override_t *key_overrides[] = {KEY_OVERRIDES};
#undef KO
