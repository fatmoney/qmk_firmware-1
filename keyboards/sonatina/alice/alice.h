#pragma once

#include "quantum.h"

#define _x_ KC_NO

#define LAYOUT( \
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
