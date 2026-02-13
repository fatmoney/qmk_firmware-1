#include QMK_KEYBOARD_H
#include "cap1298.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {{{ KC_NO }}};

// 直前のスライダー位置を記憶
static float cap_prev_position = 0.0f;

void matrix_scan_user(void) {
    // 現在のスライダー位置を取得 (0.0 〜 5.0)
    float current_pos = cap1298_get_slider_position();

    // タッチされている場合のみ処理
    if (current_pos >= 0.0f) {
        float delta = current_pos - cap_prev_position;

        // 変化量が一定以上の場合のみスクロールとみなす（閾値調整してください）
        if (delta > 0.4f) {
            // 右（増加方向）へ動いた -> 左キー
            tap_code(KC_LEFT);
            // 連続スクロールさせるため、現在値を少し追いつかせる
            cap_prev_position += 0.4f;
        }
        else if (delta < -0.4f) {
            // 左（減少方向）へ動いた -> 右キー
            tap_code(KC_RIGHT);
            cap_prev_position -= 0.4f;
        }
        else {
            // 微細な揺れや指止め時は位置を更新するだけ
            cap_prev_position = current_pos;
        }
    } else {
        // 離されたときはリセット
        cap_prev_position = 0.0f;
    }
}
