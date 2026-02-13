#pragma once

#define I2C1_SCL_PIN B6
#define I2C1_SDA_PIN B7
#define I2C1_CLOCK_SPEED 400000 // 400kHz

// CAP1298-2-SL-TR
#define CAP1298_I2C_ADDRESS (0x28 << 1)

// どのタッチセンサをどのキーに割り当てるかの定義（例）
#define CAP_TOUCH_PIN_1 0
#define CAP_TOUCH_PIN_2 1
