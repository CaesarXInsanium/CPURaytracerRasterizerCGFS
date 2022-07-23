#pragma once
#include <cglm/cglm.h>

typedef struct Coord_ {
  int x;
  int y;
} Coord;

Coord Coord_new(int x, int y);


typedef struct RGB_ {
  uint8_t r;
  uint8_t g;
  uint8_t b;
} RGB;

RGB RGB_new(uint8_t r, uint8_t g, uint8_t b);

// adds colors component wise
RGB RGB_add(RGB a, RGB b);

// x must be in range (0,1]
RGB RGB_intensity(RGB color, float x);
