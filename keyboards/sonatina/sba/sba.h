#pragma once

#include "quantum.h"

#define _x_ KC_NO

#define boring( \
  K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A,      K0C, \
  K10, K11, K12, K13, K14, K15, K16, K17, K18, K19,           K1C, \
  K20, K21, K22, K23, K24, K25, K26, K27, K28,           K2B,      \
            K32,           K35,                     K3A            \
) { \
{ K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, _x_, K0C }, \
{ K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, _x_, _x_, K1C }, \
{ K20, K21, K22, K23, K24, K25, K26, K27, K28, _x_, _x_, K2B, _x_ }, \
{ _x_, _x_, K32, _x_, _x_, K35, _x_, _x_, _x_, _x_, K3A, _x_, _x_ }  \
}

#define ni( \
  K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A,      K0C, \
  K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K2A,      \
  K20, K21, K22, K23, K24, K25, K26, K27, K28,           K2B,      \
            K32,           K35,                     K3A            \
) { \
{ K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, _x_, K0C }, \
{ K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K2A, _x_ }, \
{ K20, K21, K22, K23, K24, K25, K26, K27, K28, _x_, _x_, K2B, _x_ }, \
{ _x_, _x_, K32, _x_, _x_, K35, _x_, _x_, _x_, _x_, K3A, _x_, _x_ }  \
}
