#pragma once

// #define LAYOUT LAYOUT_0

// #define x KC_NO
// #define _ _______
#define CMD_ENT MT(MOD_LGUI, KC_ENT)
#define CTR_A MT(MOD_LCTL, KC_A)
#define SFT_ESC MT(MOD_LSFT, KC_ESC)
#define SFT_DOT MT(MOD_LSFT, KC_DOT)
#define SFT_Z MT(MOD_LSFT, KC_Z)
#define SFT_COMM MT(MOD_LSFT, KC_COMM)
#define SFT_SLSH MT(MOD_LSFT, KC_SLSH)
#define SFT_ENT MT(MOD_LSFT, KC_ENT)
#define SFT_A MT(MOD_LSFT, KC_A)
#define ALT_FF MT(MOD_LALT, KC_MFFD) // Fast Forward
#define L1_SPC LT(1, KC_SPC)
#define L2_ENT LT(2, KC_ENT)
#define SS G(S(KC_4)) // Screen Shot (macOS)
#define TOG_IME (C(KC_SPC)) // Toggle IME (macOS)
#define EISU KC_LANG2

#define TAPPING_TERM 175

// I'm not sure if this is working but just in case
// https://www.reddit.com/r/olkb/comments/8qppdn/qmk_issue_with_mt_when_typing_quickly/
// #undef PERMISSIVE_HOLD

// #define COMBO_ALLOW_ACTION_KEYS
// #define COMBO_MUST_HOLD_PER_COMBO
// #define COMBO_MUST_TAP_PER_COMBO
// #define AUTO_SHIFT_TIMEOUT 140

// https://docs.qmk.fm/#/feature_combo?id=layer-independent-combos
#define COMBO_ONLY_FROM_LAYER 0

// #define COMBO_PROCESS_KEY_RELEASE

// #define HOLD_ON_OTHER_KEY_PRESS

#ifdef AUTO_SHIFT_ENABLE
    #define AUTO_SHIFT_TIMEOUT 110
    #define AUTO_SHIFT_TIMEOUT_PER_KEY
    #define NO_AUTO_SHIFT_SPECIAL
    #define NO_AUTO_SHIFT_NUMERIC
#endif

#define MOUSEKEY_WHEEL_DELAY 0
#define MOUSEKEY_WHEEL_INTERVAL 25

// #define CHORDAL_HOLD

