void leader_start_user(void) {
    if (leader_sequence_one_key(KC_A)) {
        tap_code16(KC_ESC);
    } else if (leader_sequence_two_keys(KC_K, KC_L)) {
        // Leader, a, s => GUI+S
        // tap_code16(LGUI(KC_S));
        tap_code16(KC_COMM);
    }
}
