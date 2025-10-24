enum {
    GRV_TILD,
    HOME_END,
    DEL_DELEND,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [GRV_TILD] = ACTION_TAP_DANCE_DOUBLE(KC_GRV, KC_TILD),
    [HOME_END] = ACTION_TAP_DANCE_DOUBLE(LCTL(KC_A), LCTL(KC_E)),
    [DEL_DELEND] = ACTION_TAP_DANCE_DOUBLE(KC_DELETE, LCTL(KC_K)),
};
