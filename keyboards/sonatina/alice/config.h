#pragma once

#include "config_common.h"

#define VENDOR_ID       0x8AA8
#define PRODUCT_ID      0x0002
#define DEVICE_VER      0x0001
#define MANUFACTURER    Sonatina
#define PRODUCT         alice
#define DESCRIPTION     Sonatina alice beta

#define MATRIX_COL_PINS { B4, B0, D6, D5, D4, D3, D0, C2, C4, C5, B2, B6, B7 }
#define MATRIX_ROW_PINS { C7, B5, B1, B3 }
#define MATRIX_COLS 13
#define MATRIX_ROWS 4
#define ENCODERS_PAD_A { D1 }
#define ENCODERS_PAD_B { D2 }
#define DIODE_DIRECTION COL2ROW
