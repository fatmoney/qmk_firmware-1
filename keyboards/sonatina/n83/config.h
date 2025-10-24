#pragma once

#include "config_common.h"

#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x2247
#define DEVICE_VER      0x0001
#define MANUFACTURER    haah
#define PRODUCT         n
#define DESCRIPTION     A custom keyboard

#define MATRIX_ROWS 1
#define MATRIX_COLS 6
#define MATRIX_ROW_PINS { D3 }
#define MATRIX_COL_PINS { B6, B2, B3, B1, F7, D7 }
#define DIODE_DIRECTION COL2ROW
#define DEBOUNCING_DELAY 5

#define ENCODERS_PAD_A { D4 }
#define ENCODERS_PAD_B { C6 }
