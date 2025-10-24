#pragma once

#include "config_common.h"

#define VENDOR_ID       0x8AA8
#define PRODUCT_ID      0x0001
#define DEVICE_VER      0x0001
#define MANUFACTURER    HAAH
#define PRODUCT         ABQ
#define DESCRIPTION     HAAH ABQ

// atmega32u4
// #define MATRIX_ROW_PINS { C6, B6, B5, B4 }
// #define MATRIX_COL_PINS { F7, C7, F6, F5, F4, F1, F0, E6, B0, B1, B2, B3 }

// ?
// #define MATRIX_ROW_PINS { B1, B0, B5, D2 }
// #define MATRIX_COL_PINS { D6, D5, D4, D3, B3, B4, C4, B6, C5, C6, B7, C7 }

#define MATRIX_ROWS 4
#define MATRIX_COLS 12
#define UNUSED_PINS
#define DIODE_DIRECTION COL2ROW
// #define DIODE_DIRECTION ROW2COL

#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

// LTとかのレイヤー切り替え時の閾値
// レイヤー切り替えのタイミングを調整したい場合変更する
// Tap Danceもこれ使う
#define TAPPING_TERM 175

// #define BOOTMAGIC_KEY_SALT KC_TAB
// #define COMBO_COUNT 2
// #define COMBO_TERM 100

#define LEADER_TIMEOUT 300
