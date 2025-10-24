#include QMK_KEYBOARD_H
#include "print.h"

#ifdef TAP_DANCE_ENABLE
    #include "tap_dance.c"
#endif

#ifdef COMBO_ENABLE
    #include "combo.c"
#endif

#ifdef LEADER_ENABLE
    #include "leader.c"
#endif

#ifdef KEY_OVERRIDE_ENABLE
    #include "key_override.c"
#endif
