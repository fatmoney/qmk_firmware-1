#pragma once

#include "quantum.h"

#define _x_ KC_NO

#ifdef USE_I2C
#include <stddef.h>
#ifdef __AVR__
  #include <avr/io.h>
  #include <avr/interrupt.h>
#endif
#endif

#define LAYOUT_iti( \
    K00, K01, K02, K03, K04, K05,      K07, K08, K09, K0A, K0B, K0C, \
    K10, K11, K12, K13, K14, K15,      K17, K18, K19, K1A, K1B, K1C, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A,      K2C, \
         K31, K32,      K34,           K37,      K39,      K3B \
) { \
  { K00, K01, K02, K03, K04, K05, _x_, K07, K08, K09, K0A, K0B, K0C }, \
  { K10, K11, K12, K13, K14, K15, _x_, K17, K18, K19, K1A, K1B, K1C }, \
  { K20, K21 ,K22, K23, K24, K25, K26, K27, K28, K29, K2A, _x_, K2C }, \
  { _x_, K31, K32, _x_, K34, _x_, _x_, K37, _x_, K39, _x_, K3B } \
}

#define LAYOUT( \
    K00, K01, K02, K03, K04, K05,      K07, K08, K09, K0A, K0B,      K0D, \
    K10, K11, K12, K13, K14, K15,      K17, K18, K19, K1A, K1B,      K1D, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A,      K2C,      \
         K31, K32,      K34,           K37,      K39, K3A                 \
) { \
  { K00, K01, K02, K03, K04, K05, _x_, K07, K08, K09, K0A, K0B, _x_, K0D }, \
  { K10, K11, K12, K13, K14, K15, _x_, K17, K18, K19, K1A, K1B, _x_, K1D }, \
  { K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, _x_, K2C, _x_ }, \
  { _x_, K31, K32, _x_, K34, _x_, _x_, K37, _x_, K39, K3A } \
}

#define LAYOUT_3( \
    K00, K01, K02, K03, K04, K05,      K07, K08, K09, K0A, K0B, K0C, \
    K10, K11, K12, K13, K14, K15,      K17, K18, K19, K1A, K1B, K1C, \
    K20, K30, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, \
         K31, K32,      K34,      K36, K37,      K39, K3A                 \
) { \
  { K00, K01, K02, K03, K04, K05, _x_, K07, K08, K09, K0A, K0B, K0C }, \
  { K10, K11, K12, K13, K14, K15, _x_, K17, K18, K19, K1A, K1B, K1C }, \
  { K20, K30, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C }, \
  { _x_, K31, K32, _x_, K34, _x_, K36, K37, _x_, K39, K3A } \
}

#define LAYOUT_SPLIT( \
    L00, L01, L02, L03, L04, L05,      R01, R02, R03, R04, R05, R06, \
    L10, L11, L12, L13, L14, L15,      R11, R12, R13, R14, R15, R16, \
    L20, L21, L22, L23, L24, L25, R20, R21, R22, R23, R24,      R26, \
         L31, L32,      L34,      R30, R31,      R33, R34            \
) { \
  { L00, L01, L02, L03, L04, L05 }, \
  { L10, L11, L12, L13, L14, L15 }, \
  { L20, L21, L22, L23, L24, L25 }, \
  { _x_, L31, L32, _x_, L34, _x_ }, \
  { _x_, R01, R02, R03, R04, R05, R06 }, \
  { _x_, R11, R12, R13, R14, R15, R16 }, \
  { R20, R21, R22, R23, R24, _x_, R26 }, \
  { R30, R31, _x_, R33, R34           }  \
}

#define LAYOUT_SPLIT_SPLIT_LSHIFT( \
    L00, L01, L02, L03, L04, L05,      R01, R02, R03, R04, R05, R06, \
    L10, L11, L12, L13, L14, L15,      R11, R12, R13, R14, R15, R16, \
    L20, L30, L21, L22, L23, L24, L25, R20, R21, R22, R23, R24,      R26, \
         L31, L32,      L34,      R30, R31,      R33, R34            \
) { \
  { L00, L01, L02, L03, L04, L05 }, \
  { L10, L11, L12, L13, L14, L15 }, \
  { L20, L21, L22, L23, L24, L25 }, \
  { L30, L31, L32, _x_, L34, _x_ }, \
  { _x_, R01, R02, R03, R04, R05, R06 }, \
  { _x_, R11, R12, R13, R14, R15, R16 }, \
  { R20, R21, R22, R23, R24, _x_, R26 }, \
  { R30, R31, _x_, R33, R34           }  \
}

#define LAYOUT_MILLMAX( \
    L00, L01, L02, L03, L04, L05,      R01, R02, R03, R04, R05, R06, \
    L10, L11, L12, L13, L14, L15,      R11, R12, R13, R14, R15, R16, \
    L20, L30, L21, L22, L23, L24, L25, R20, R21, R22, R23, R24,      R26, \
         L31, L32, L33, L34,      R30, R31,      R33, R34            \
) { \
  { L00, L01, L02, L03, L04, L05 }, \
  { L10, L11, L12, L13, L14, L15 }, \
  { L20, L21, L22, L23, L24, L25 }, \
  { L30, L31, L32, L33, L34, _x_ }, \
  { _x_, R01, R02, R03, R04, R05, R06 }, \
  { _x_, R11, R12, R13, R14, R15, R16 }, \
  { R20, R21, R22, R23, R24, _x_, R26 }, \
  { R30, R31, _x_, R33, R34           }  \
}

#define LAYOUT_4( \
    K00, K01, K02, K03, K04, K05,      K07, K08, K09, K0A, K0B, K0C, \
    K10, K11, K12, K13, K14, K15,      K17, K18, K19, K1A, K1B, K1C, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A,      K2C, \
         K31, K32,      K34,      K36, K37,      K39, K3A                 \
) { \
  { K00, K01, K02, K03, K04, K05, _x_, K07, K08, K09, K0A, K0B, K0C }, \
  { K10, K11, K12, K13, K14, K15, _x_, K17, K18, K19, K1A, K1B, K1C }, \
  { K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, _x_, K2C }, \
  { _x_, K31, K32, _x_, K34, _x_, K36, K37, _x_, K39, K3A } \
}

#define LAYOUT_5( \
    K00, K01, K02, K03, K04, K05,      K07, K08, K09, K0A, K0B, K0C, \
    K10, K11, K12, K13, K14, K15,      K17, K18, K19, K1A, K1B, K1C, \
    K20,      K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2C, \
         K31, K32,      K34,      K36,      K38, K39, K3A                 \
) { \
  { K00, K01, K02, K03, K04, K05, _x_, K07, K08, K09, K0A, K0B, K0C }, \
  { K10, K11, K12, K13, K14, K15, _x_, K17, K18, K19, K1A, K1B, K1C }, \
  { K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, _x_, K2C }, \
  { _x_, K31, K32, _x_, K34, _x_, K36, _x_, K38, K39, K3A } \
}

#define LAYOUT_6( \
    K00, K01, K02, K03, K04, K05,      K07, K08, K09, K0A, K0B, K0C, \
    K10, K11, K12, K13, K14, K15,      K17, K18, K19, K1A, K1B, K1C, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, \
         K31, K32,      K34,      K36, K37,      K39, K3A            \
) { \
  { K00, K01, K02, K03, K04, K05, _x_, K07, K08, K09, K0A, K0B, K0C }, \
  { K10, K11, K12, K13, K14, K15, _x_, K17, K18, K19, K1A, K1B, K1C }, \
  { K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C }, \
  { _x_, K31, K32, _x_, K34, _x_, K36, K37, _x_, K39, K3A } \
}
