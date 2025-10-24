#include <stdint.h>
#include <stdbool.h>

#include "matrix.h"

typedef struct {
    uint16_t low_threthold;
    uint16_t high_threthold;
} ecmicro_config_t;

int      ecmicro_init(ecmicro_config_t const* const ecmicro_config);
bool     ecmicro_matrix_scan(matrix_row_t current_matrix[]);
void     ecmicro_dprint_matrix(void);
uint16_t ecmicro_readkey_raw(uint8_t row, uint8_t col);
bool     ecmicro_update_key(matrix_row_t* current_row, uint8_t col, uint16_t sw_value);
