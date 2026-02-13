#pragma once

#include <stdint.h>

// CAP1298 レジスタ定義
#define REG_MAIN_CONTROL   0x00
#define REG_INPUT_STATUS   0x03  // CS1-CS4はここから始まる
#define REG_SENSITIVITY    0x1F

// I2Cアドレス
#define CAP1298_I2C_ADDRESS (0x28 << 1)

// CAP1298 の初期化（Standby解除など）
void cap1298_init(void);

// スライダーの位置を計算して返す関数
// 戻り値: 0.0〜5.0（タッチ位置）、-1.0（タッチなし or エラー）
float cap1298_get_slider_position(void);
