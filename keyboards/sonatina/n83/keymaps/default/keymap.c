#include QMK_KEYBOARD_H

#include "print.h"
#include "pointing_device.h"
#include "analog.c"
#include "pincontrol.h"
#include "report.h"
#include "timer.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT(
        KC_UP, KC_RIGHT, KC_DOWN, KC_LEFT, KC_A, LT(1, KC_A) \
    ),
    LAYOUT(
        KC_MS_WH_UP, KC_MS_WH_RIGHT, KC_MS_WH_DOWN, KC_MS_WH_LEFT, _______, _______ \
    )
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_LEFT);
    } else {
        tap_code(KC_RIGHT);
    }
}

void matrix_scan_user(void) {
  	report_mouse_t currentReport = pointing_device_get_report();
    pointing_device_set_report(currentReport);
    pointing_device_send();
}
