#pragma once

#include "quantum.h"

#include <stdint.h>
#include <stdbool.h>

#if defined(__AVR__)
  #include <avr/pgmspace.h>     // PROGMEM
  #include <avr/io.h>           // PIND
#endif

#include "keycode.h"            // KC_xxx
#include "action_layer.h"       // default_layer_set
#include "analogpad.h"

#define LAYOUT( \
    K00 \
) \
{ \
    { K00 } \
}
