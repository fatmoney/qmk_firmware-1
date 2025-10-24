/* CUSTOM TAP DANCE
https://beta.docs.qmk.fm/using-qmk/software-features/feature_tap_dance
*/

// https://www.reddit.com/r/olkb/comments/b29a99/kc_lead_on_tap_and_layer_on_on_hold_in_a_tap_dance/
// ~/keyboard/qmk_firmware/keyboards/ergodox_ez/keymaps/hacker_dvorak/tap_dance

typedef struct {
    bool is_press_action;
    int state;
} tap;

enum tap_dances {
  TD_1,
  TD_2,
  TD_3,
  TD_4,
  TD_5,
  TD_6,
  TD_7,
  TD_8,
  TD_9,
  TD_0,
  TD_RIGHT,
  TD_LEFT,
  TD_MINUS,
  TD_PRN,
  TD_CBR,
  TD_BRC,
  TD_BSLS,
  TD_EQL,
  TD_TILD,
  TD_LT,
  TD_BSPC,
  TD_IME_JAP,
  SFT_IME_JA,
  TD_SHIFT_LEAD,
  TD_EN_JA,
};

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3
};

int cur_dance (qk_tap_dance_state_t *state);
void lead_finished (qk_tap_dance_state_t *state, void *user_data);
void lead_reset (qk_tap_dance_state_t *state, void *user_data);
// void ja_finished (qk_tap_dance_state_t *state, void *user_data);
// void ja_reset (qk_tap_dance_state_t *state, void *user_data);
