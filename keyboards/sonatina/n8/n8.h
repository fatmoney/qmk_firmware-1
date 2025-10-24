#ifndef N8_H
#define N8_H

#include "quantum.h"

#define LAYOUT( \
    K00 \
) \
{ \
    { K00 } \
}

enum ThumbStickMode {
  ThumbStickMovesPointer,
  ThumbStickPanning,
};
void flutterby_thumbstick_set_mode(enum ThumbStickMode mode);
enum ThumbStickMode flutterby_thumbstick_get_mode(void);

#endif