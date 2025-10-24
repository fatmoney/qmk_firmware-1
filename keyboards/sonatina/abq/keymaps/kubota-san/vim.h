#include "config.h"
#include "print.h"
#include "keycode.h"
#include "quantum.h"
#include "quantum_keycodes.h"

#define NOR_MOD TO(NORMAL_MODE)
#define INS_MOD TO(INSERT_MODE)

#define PRESS(keycode) register_code16(keycode)
#define RELEASE(keycode) unregister_code16(keycode)

uint16_t VIM_QUEUE = KC_NO;

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  VIM_E,
  VIM_I,
  VIM_A,
  VIM_DD,
};

void VIM_END(void);
void VIM_DELETE_WHOLE_LINE(void);

void TAP(uint16_t keycode) {
    PRESS(keycode);
    RELEASE(keycode);
}

void CMD(uint16_t keycode) {
  PRESS(KC_LGUI);
    TAP(keycode);
  RELEASE(KC_LGUI);
}

void CTRL(uint16_t keycode) {
  PRESS(KC_LCTRL);
    TAP(keycode);
  RELEASE(KC_LCTRL);
}

void SHIFT(uint16_t keycode) {
  PRESS(KC_LSHIFT);
    TAP(keycode);
  RELEASE(KC_LSHIFT);
}

void ALT(uint16_t keycode) {
  PRESS(KC_LALT);
    TAP(keycode);
  RELEASE(KC_LALT);
}

/**
 * Sets the `VIM_QUEUE` variable to the incoming keycode.
 * Pass `KC_NO` to cancel the operation.
 * @param keycode
 */
void VIM_LEADER(uint16_t keycode) {
  VIM_QUEUE = keycode;
}

void VIM_DELETE_LINE_TO_END(void) {
  CTRL(KC_K);
}


void VIM_APPEND_LINE(void) {
  RELEASE(KC_LSFT);
//   VIM_LEADER(KC_NO);
  CMD(KC_RIGHT);
//   layer_on(INSERT_MODE);
}

void VIM_APPEND(void) {
  print("\e[31ma\e[0m");
  TAP(KC_RIGHT);
  layer_on(INSERT_MODE);
}

void VIM_JOIN(void) {
  CMD(KC_RIGHT);
  TAP(KC_DELETE);
  TAP(KC_DELETE);
}

void VIM_END(void) {
  ALT(KC_RIGHT);
}

void VIM_BACK(void) {
  ALT(KC_LEFT);
}

void VIM_DELETE_END(void) {
  PRESS(KC_LALT);
    SHIFT(KC_RIGHT); // select to end of this word
  RELEASE(KC_LALT);
//   CMD(KC_X);
  CMD(KC_BSPC);
}

void VIM_DELETE_INNER_WORD(void) {
  VIM_BACK();
  VIM_DELETE_END();
}

void VIM_DELETE_BACK(void) {
  PRESS(KC_LALT);
    SHIFT(KC_LEFT); // select to start of word
    SHIFT(KC_DEL); // delete selection
  RELEASE(KC_LSHIFT);
}

// void VIM_DELETE_WHOLE_LINE(void) {
//   CMD(KC_LEFT);
//   PRESS(KC_LSHIFT);
//     CMD(KC_RIGHT);
//   RELEASE(KC_LSHIFT);
//   CMD(KC_X);
// }

void VIM_DELETE_LINE(void) {
  CTRL(KC_K);
}

void VIM_DELETE_WHOLE_LINE(void) {
  CTRL(KC_A);
  CTRL(KC_K);
}

void VIM_BEG_OF_LINE(void) {
  CTRL(KC_A);
  PRESS(KC_LALT);
    TAP(KC_RIGHT);
    TAP(KC_LEFT);
  RELEASE(KC_LALT);
}

void VIM_OPEN_ABOVE(void) {
  CTRL(KC_E);
  TAP(KC_ENTER);
}

void VIM_UNDO(void) {
  CMD(KC_Z);
}
