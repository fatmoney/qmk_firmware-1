#include "n8.h"
#include "action_layer.h"
#include "pincontrol.h"
#include <print.h>

#ifdef MOUSEKEY_ENABLE
#include "mousekey.h"
#endif

// Function ids for use with F(n)
enum function_id {
  FNTHUMBSTICKMODE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT(
        F(FNTHUMBSTICKMODE) \
    )
};

// Using F(n) causes the firmware to lookup what to do from this table
const uint16_t PROGMEM fn_actions[] = {
  [FNTHUMBSTICKMODE] = ACTION_FUNCTION(FNTHUMBSTICKMODE),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch (id) {
    case FNTHUMBSTICKMODE:
      if (IS_RELEASED(record->event)) {
        switch (flutterby_thumbstick_get_mode()){
          case ThumbStickMovesPointer:
            uprintf("ok");
            flutterby_thumbstick_set_mode(ThumbStickPanning);
            break;
          case ThumbStickPanning:
            flutterby_thumbstick_set_mode(ThumbStickMovesPointer);
            break;
          default:
            break;
        }
      }
      return;
  }
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}
