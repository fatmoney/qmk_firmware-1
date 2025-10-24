const key_override_t ko1 = ko_make_basic(
    MOD_MASK_GUI, KC_Q, G(KC_TAB)
);

const key_override_t ko2 = ko_make_basic(
    MOD_MASK_GUI, KC_D, G(KC_Q)
);

const key_override_t ko3 = ko_make_basic(
    MOD_MASK_ALT, KC_Q, A(KC_TAB)
);

const key_override_t *key_overrides[] = {
	&ko1,
	&ko2,
	&ko3,
};
