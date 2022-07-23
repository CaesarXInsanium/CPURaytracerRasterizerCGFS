#pragma once
#include <cglm/cglm.h>

typedef struct RGB_ {
  short r;
  short g;
  short b;
} RGB;

RGB RGB_new(short r, short g, short b);
