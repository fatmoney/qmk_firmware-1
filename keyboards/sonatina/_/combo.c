enum {
    CMB1, CMB2, CMB3, CMB4, CMB5, CMB6, CMB7, CMB8, CMB9,
};

const uint16_t PROGMEM cmb1[] = {KC_L, MT(MOD_RSFT, KC_DOT), COMBO_END};
const uint16_t PROGMEM cmb2[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM cmb3[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM cmb4[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM cmb5[] = {MT(MOD_LCTL, KC_A), KC_S, COMBO_END};
const uint16_t PROGMEM cmb6[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM cmb7[] = {KC_W, KC_E, COMBO_END};
// const uint16_t PROGMEM cmb6[] = {KC_J, KC_K, COMBO_END};

combo_t key_combos[] = {
    [CMB1] = COMBO(cmb1, KC_COMM),
    [CMB2] = COMBO(cmb2, KC_QUOT),
    [CMB3] = COMBO(cmb3, MS_WHLD),
    [CMB4] = COMBO(cmb4, KC_ESC),
    [CMB5] = COMBO(cmb5, C(KC_A)),
    [CMB6] = COMBO(cmb6, MS_WHLU),
    [CMB7] = COMBO(cmb7, KC_MINUS),
};
