typedef struct {
    const char* token;
    uint16_t keycode;
} token_map_t;

const token_map_t PROGMEM token_map[] = {
    {"\n", KC_ENTER},
    {"\x1B", KC_ESCAPE},
    {"\b", KC_BACKSPACE},
    {"\t", KC_TAB},
    {" ", KC_SPACE},
    {"-", KC_MINUS},
    {"=", KC_EQUAL},
    {"[", KC_LEFT_BRACKET},
    {"]", KC_RIGHT_BRACKET},
    {"\\", KC_BACKSLASH},
    {";", KC_SEMICOLON},
    {"'", KC_QUOTE},
    {"`", KC_GRAVE},
    {",", KC_COMMA},
    {".", KC_DOT},
    {"/", KC_SLASH},
    {"~", S(KC_GRAVE)},
    {"!", S(KC_1)},
    {"@", S(KC_2)},
    {"#", S(KC_3)},
    {"$", S(KC_4)},
    {"%", S(KC_5)},
    {"^", S(KC_6)},
    {"&", S(KC_7)},
    {"*", S(KC_8)},
    {"(", S(KC_9)},
    {")", S(KC_0)},
    {"_", S(KC_MINUS)},
    {"{", S(KC_LEFT_BRACKET)},
    {"}", S(KC_RIGHT_BRACKET)},
    {"|", S(KC_BACKSLASH)},
    {":", S(KC_SEMICOLON)},
    {"\"", S(KC_QUOTE)},
    {"<", S(KC_COMMA)},
    {">", S(KC_DOT)},
    {"?", S(KC_SLASH)},
    {"a", KC_A},
    {"b", KC_B},
    {"c", KC_C},
    {"d", KC_D},
    {"e", KC_E},
    {"f", KC_F},
    {"g", KC_G},
    {"h", KC_H},
    {"i", KC_I},
    {"j", KC_J},
    {"k", KC_K},
    {"l", KC_L},
    {"m", KC_M},
    {"n", KC_N},
    {"o", KC_O},
    {"p", KC_P},
    {"q", KC_Q},
    {"r", KC_R},
    {"s", KC_S},
    {"t", KC_T},
    {"u", KC_U},
    {"v", KC_V},
    {"w", KC_W},
    {"x", KC_X},
    {"y", KC_Y},
    {"z", KC_Z},
    {"1", KC_1},
    {"2", KC_2},
    {"3", KC_3},
    {"4", KC_4},
    {"5", KC_5},
    {"6", KC_6},
    {"7", KC_7},
    {"8", KC_8},
    {"9", KC_9},
    {"0", KC_0},
    {"X", KC_NO},
    {"_", KC_TRANSPARENT},
    {"enter", KC_ENTER},
    {"ent", KC_ENTER},
    {"tab", KC_TAB},
    {"esc", KC_ESC},
    {"bspc", KC_BSPC},
    {"spc", KC_SPACE},
    {"space", KC_SPACE},
    {"ca", CTR_A},
    {"sd", SFT_DOT},
    {"sz", SFT_Z},
    {"td0", TD(0)},
    {"td1", TD(1)},
    {"td2", TD(2)},
    {"td3", TD(3)},
    {"alt", KC_LALT},
    {"ge", CMD_ENT},
    {"l1spc", L1_SPC},
    {"l2ent", L2_ENT},
    {"ss", G(S(KC_4))},
    {"mouse_u", MS_WHLU},
    {"mouse_d", MS_WHLD},
    {"left", KC_LEFT},
    {"right", KC_RIGHT},
    {"down", KC_DOWN},
    {"up", KC_UP},
    {"del", KC_DEL},
};

bool token_equals(const char* str, const char* progmem_str) {
    return strcmp_P(str, progmem_str) == 0;
}

void string_to_keycodes(const char* str, uint16_t* output) {
    char token[20];
    size_t token_idx = 0;
    size_t out_idx = 0;
    size_t i = 0;

    while (str[i] != '\0' && out_idx < 50) {
        if (str[i] == ' ') {
            if (token_idx > 0) {
                token[token_idx] = '\0';

                bool found = false;
                for (size_t j = 0; j < sizeof(token_map) / sizeof(token_map_t); j++) {
                    if (token_equals(token, (const char*)pgm_read_ptr(&token_map[j].token))) {
                        output[out_idx] = pgm_read_word(&token_map[j].keycode);  // pgm_read_word不要
                        out_idx++;
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    output[out_idx] = KC_NO;
                    out_idx++;
                }

                token_idx = 0;
            }
        } else {
            if (token_idx < sizeof(token) - 1) {
                token[token_idx++] = str[i];
            }
        }
        i++;
    }

    // 最後のトークン処理
    if (token_idx > 0) {
        token[token_idx] = '\0';
        for (size_t j = 0; j < sizeof(token_map) / sizeof(token_map_t); j++) {
            if (token_equals(token, (const char*)pgm_read_ptr(&token_map[j].token))) {
                output[out_idx] = pgm_read_word(&token_map[j].keycode);  // pgm_read_word追加
                out_idx++;  // ← これも追加
                break;
            }
        }
    }
}
