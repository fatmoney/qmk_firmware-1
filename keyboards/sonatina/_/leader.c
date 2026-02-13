void leader_end_user(void) {
    if (leader_sequence_one_key(KC_A)) {
        tap_code16(KC_ESC);
    } else if (leader_sequence_two_keys(KC_K, KC_L)) {
        tap_code16(KC_Q);
    }
}
