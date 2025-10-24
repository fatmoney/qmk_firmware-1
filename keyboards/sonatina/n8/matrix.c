#if defined(__AVR__)
#include <avr/io.h>
#endif
#include <stdbool.h>

#include "debug.h"
#include "n8.h"
#include "config.h"
#include "matrix.h"
#include "print.h"
#include "timer.h"
#include "util.h"
#include "wait.h"
#include "pincontrol.h"
#include "mousekey.h"
#include "outputselect.h"
#ifdef PROTOCOL_LUFA
#include "lufa.h"
#endif
#include "suspend.h"
#include <util/atomic.h>
#include <string.h>

static const uint8_t row_pins[MATRIX_ROWS] = MATRIX_ROW_PINS;
static const uint8_t col_pins[MATRIX_COLS] = MATRIX_COL_PINS;
#if DEBOUNCING_DELAY > 0
static bool debouncing;
static matrix_row_t matrix_debouncing[MATRIX_ROWS];
#endif
/* matrix state(1:on, 0:off) */
static matrix_row_t raw_matrix[MATRIX_ROWS];  // raw values
static matrix_row_t matrix[MATRIX_ROWS];

/************************************************************/

static void select_row(uint8_t row) {
    setPinOutput(row_pins[row]);
    writePinLow(row_pins[row]);
}

static void unselect_row(uint8_t row) {
    setPinInputHigh(row_pins[row]);
}

static void select_rows(void) {
    for (uint8_t x = 0; x < MATRIX_ROWS; x++) {
        select_row(x);
    }
}

static void unselect_rows(void) {
    for (uint8_t x = 0; x < MATRIX_ROWS; x++) {
        setPinInputHigh(row_pins[x]);
    }
}

static void init_pins(void) {
    unselect_rows();
    for (uint8_t x = 0; x < MATRIX_COLS; x++) {
        setPinInputHigh(col_pins[x]);
    }
}

/************************************************************/

#include "LUFA/Drivers/Peripheral/ADC.h"

void matrix_init(void) {
    // initialize key pins
    init_pins();

    // initialize matrix state: all keys off
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        raw_matrix[i] = 0;
        matrix[i]     = 0;
    }
    
    #ifdef MOUSEKEY_ENABLE
      // Turn on the ADC for reading the thumbstick
      ADC_Init(ADC_SINGLE_CONVERSION | ADC_PRESCALE_32);
      ADC_SetupChannel(0); // X
      ADC_SetupChannel(1); // Y
    #endif


    debounce_init(MATRIX_ROWS);

    matrix_init_quantum();
}

bool matrix_is_on(uint8_t row, uint8_t col) {
  return (matrix[row] & ((matrix_row_t)1 << col));
}

matrix_row_t matrix_get_row(uint8_t row) {
    return matrix[row];
}

static bool read_cols_on_row(matrix_row_t current_matrix[], uint8_t current_row) {
    // Store last value of row prior to reading
    matrix_row_t last_row_value = current_matrix[current_row];

    // Clear data in matrix row
    current_matrix[current_row] = 0;

    // Select row and wait for row selecton to stabilize
    select_row(current_row);
    wait_us(30);

    // For each col...
    for (uint8_t col_index = 0; col_index < MATRIX_COLS; col_index++) {
        // Select the col pin to read (active low)
        uint8_t pin_state = readPin(col_pins[col_index]);

        // Populate the matrix row with the state of the col pin
        current_matrix[current_row] |= pin_state ? 0 : (((matrix_row_t)1) << col_index);
    }

    // Unselect row
    unselect_row(current_row);

    return (last_row_value != current_matrix[current_row]);
}

/************************************************************/

#ifdef MOUSEKEY_ENABLE
static enum ThumbStickMode thumbstick_mode = ThumbStickMovesPointer;

enum ThumbStickMode flutterby_thumbstick_get_mode(void) {
  return thumbstick_mode;
}

void flutterby_thumbstick_set_mode(enum ThumbStickMode mode) {
  if (thumbstick_mode == mode) {
    return;
  }
  thumbstick_mode = mode;

  // Clear state to avoid getting stuck if the mode is changed
  // while the stick is not centered
  mousekey_set_xyvh(0, 0, 0, 0);
  mousekey_send();
}


#define StickMax 832
#define StickMin 160
#define StickCenter 512
#define StickSlop 64  // Dead band around the middle

// Take an input in the range 0-1024 and return a value in the
// range -127 to 127.
// [0   160    512     832    1024]
//      [-127    0     127]
static int8_t map_value(int32_t v) {
  v -= StickCenter;

  int sign = 1;
  if (v < 0) {
    sign = -1;
    v = -v;
  }

  if (v < StickSlop) {
    // It's within the dead band, so treat it as zero
    return 0;
  }


  int32_t maximum = thumbstick_mode == ThumbStickMovesPointer
                       ? mk_max_speed
                       : mk_wheel_max_speed;
  //dprintf("v=%d, max=%d product=%d\n", (int)v, (int)maximum, (int)(v * maximum));
  return (sign * maximum * v) / 320;
}

static void thumbstick_read(uint8_t chanmask, int8_t *value, int8_t *last_value,
                            bool *dirty) {
  *value = map_value(ADC_GetChannelReading(ADC_REFERENCE_AVCC | chanmask));

  if (*value != *last_value) {
    *last_value = *value;
    *dirty = true;
  }
}

void process_thumbstick(void) {
  // Cache the prior read to avoid over-reporting mouse movement
  static int8_t last_x = 0;
  static int8_t last_y = 0;
  int8_t x;
  int8_t y;

  bool dirty = false;
  thumbstick_read(ADC_CHANNEL0, &x, &last_x, &dirty);
  thumbstick_read(ADC_CHANNEL1, &y, &last_y, &dirty);

  if (dirty || x || y) {
    if (thumbstick_mode == ThumbStickMovesPointer) {
      mousekey_set_xyvh(x, -y, 0, 0);
    } else {
      mousekey_set_xyvh(0, 0, -y, x);
    }
    mousekey_send();
  }
}

#endif

/************************************************************/

uint8_t matrix_scan(void) {
    bool changed = false;

    for (uint8_t current_row = 0; current_row < MATRIX_ROWS; current_row++) {
        changed |= read_cols_on_row(raw_matrix, current_row);
    }

    debounce(raw_matrix, matrix, MATRIX_ROWS, changed);

    matrix_scan_quantum();
    return (uint8_t)changed;
}

void matrix_print(void) {
}