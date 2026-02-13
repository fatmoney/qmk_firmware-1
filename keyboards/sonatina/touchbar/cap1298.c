#include "cap1298.h"
#include "i2c_master.h"

void cap1298_init(void) {
    uint8_t data[] = {0x00}; // Standby解除
    i2c_write_register(CAP1298_I2C_ADDRESS, REG_MAIN_CONTROL, data, 1, 0);

    // （任意）感度調整
    // デフォルトだと非常に敏感なので、少し下げることも検討してください
    // uint8_t sens = 0x2F; // デフォルト
    // i2c_write_register(CAP1298_I2C_ADDRESS, REG_SENSITIVITY, &sens, 1, 0);
}

// スライダーの位置を計算して返す関数 (0.0 〜 5.0)
float cap1298_get_slider_position(void) {
    uint8_t status[2] = {0};

    // 0x03番地から2バイト読み込む (CS1-CS8)
    // status[0]のbit0-3がCS1-4, status[1]のbit0-3がCS5-8
    if (i2c_read_register(CAP1298_I2C_ADDRESS, REG_INPUT_STATUS, status, 2, 0)) {
        return -1.0f; // 読み取りエラー
    }

    // CS1〜CS6のビットを抽出してマスクを作る
    // CS1(0x03のbit0) 〜 CS6(0x04のbit1)
    uint8_t cs1 = status[0] & 0x01;
    uint8_t cs2 = status[0] & 0x02;
    uint8_t cs3 = status[0] & 0x04;
    uint8_t cs4 = status[0] & 0x08;
    uint8_t cs5 = status[1] & 0x01;
    uint8_t cs6 = status[1] & 0x02;

    // タッチされているセンサーのインデックス(0〜5)と、その数をカウント
    float sum_index = 0;
    int count = 0;

    if (cs1) { sum_index += 0; count++; }
    if (cs2) { sum_index += 1; count++; }
    if (cs3) { sum_index += 2; count++; }
    if (cs4) { sum_index += 3; count++; }
    if (cs5) { sum_index += 4; count++; }
    if (cs6) { sum_index += 5; count++; }

    if (count == 0) {
        return -1.0f; // 何もタッチされていない
    }

    // 平均値を算出（ここが補間の処理です）
    // 例: CS1(0)とCS2(1)がタッチされていれば (0+1)/2 = 0.5 が返る
    return sum_index / count;
}
