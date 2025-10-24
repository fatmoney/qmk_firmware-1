#pragma once

#include "config_common.h"

#define VENDOR_ID       0x8AA8
#define PRODUCT_ID      0x0002
#define DEVICE_VER      0x0001
#define MANUFACTURER    HAAH
#define PRODUCT         Second Bakery Attackl
#define DESCRIPTION     HAAH Second Bakery Attack

#define MATRIX_ROW_PINS { D0, D1, D5, C2 }
#define MATRIX_COL_PINS { D2, D3, D4, D6, B5, C4, B6, B7, C7, B3, C5, C6, B4 }

#define MATRIX_ROWS 4
#define MATRIX_COLS 13
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

#define RGB_DI_PIN B0
#define RGBLED_NUM 1
