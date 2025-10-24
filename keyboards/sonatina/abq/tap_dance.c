#include "tap_dance.h"

int cur_dance (qk_tap_dance_state_t *state) {
  int current_state = 0;
  if (state->count == 1) {
      if (state->interrupted || !state->pressed) {
          current_state = SINGLE_TAP;
      } else {
          current_state = SINGLE_HOLD; //key has not been interrupted, but they key is still held. Means you want to send a 'HOLD'.
      }
  } else if (state->count == 2) {
      current_state = DOUBLE_TAP;
  }
  return current_state;
}

static tap lead_state = {
  .is_press_action = true,
  .state = 0
};

void lead_finished (qk_tap_dance_state_t *state, void *user_data) {
  lead_state.state = cur_dance(state);
  switch (lead_state.state) {
    case SINGLE_TAP: qk_leader_start(); break;
    case SINGLE_HOLD: register_code(KC_LSFT); break;
  }
}

void lead_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (lead_state.state) {
    case SINGLE_TAP: break;
    case SINGLE_HOLD: unregister_code(KC_LSFT); break;
  }
  lead_state.state = 0;
}
  
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_1] = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_EXLM),
  [TD_2] = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_AT),
  [TD_3] = ACTION_TAP_DANCE_DOUBLE(KC_3, KC_HASH),
  [TD_4] = ACTION_TAP_DANCE_DOUBLE(KC_4, KC_DLR),
  [TD_5] = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_PERC),
  [TD_6] = ACTION_TAP_DANCE_DOUBLE(KC_6, KC_CIRC),
  [TD_7] = ACTION_TAP_DANCE_DOUBLE(KC_7, KC_AMPR),
  [TD_8] = ACTION_TAP_DANCE_DOUBLE(KC_8, KC_ASTR),
  [TD_9] = ACTION_TAP_DANCE_DOUBLE(KC_9, KC_LPRN),
  [TD_0] = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_RPRN),
  [TD_MINUS] = ACTION_TAP_DANCE_DOUBLE(KC_MINUS, KC_UNDS),
  [TD_EQL] = ACTION_TAP_DANCE_DOUBLE(KC_EQL, KC_PLUS),
  [TD_PRN] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
  [TD_CBR] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
  [TD_BRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
  [TD_BSLS] = ACTION_TAP_DANCE_DOUBLE(KC_BSLS, KC_PIPE),
  [TD_TILD] = ACTION_TAP_DANCE_DOUBLE(KC_TILD, KC_GRV),
  [TD_LT] = ACTION_TAP_DANCE_DOUBLE(KC_LT, KC_GT),
  [TD_IME_JAP] = ACTION_TAP_DANCE_DOUBLE(KC_LANG2, KC_LANG1),
  [TD_SHIFT_LEAD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lead_finished, lead_reset),
  // [TD_EN_JA] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ja_finished, ja_reset)
};
