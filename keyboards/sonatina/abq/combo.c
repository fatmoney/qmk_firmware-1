#include "quantum.h"

enum combo_events {
  C_PASTE,
  C_COPY,
};

const uint16_t PROGMEM paste_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM copy_combo[] = {KC_F, KC_D, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  // [C_PASTE] = COMBO(ab_combo, KC_ESC),
  [C_PASTE] = COMBO_ACTION(paste_combo),
  [C_COPY] = COMBO_ACTION(copy_combo),
};

void process_combo_event(uint8_t combo_index, bool pressed) {
  switch(combo_index) {
    case C_PASTE:
      if (pressed) {
        // tap_code16(LGUI(KC_V));
        tap_code16(KC_0);
      }
      break;
    case C_COPY:
      if (pressed) {
        tap_code16(KC_1);
      }
      break;
  }
}
