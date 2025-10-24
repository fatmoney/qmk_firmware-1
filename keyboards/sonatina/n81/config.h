#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x2947
#define DEVICE_VER      0x0001
#define MANUFACTURER    haah
#define PRODUCT         n8
#define DESCRIPTION     A custom keyboard

#define MATRIX_ROWS 1
#define MATRIX_COLS 1
#define ATMEGA_COLS 0

#define MATRIX_ROW_PINS { B5 }
#define MATRIX_COL_PINS { B6 }
#define DIODE_DIRECTION COL2ROW
 
#define MOUSEKEY_ANALOG_XYVH 1
#define MOUSEKEY_MAX_SPEED 15
#define MOUSEKEY_WHEEL_MAX_SPEED 1

#define DEBOUNCING_DELAY 5

#endif
