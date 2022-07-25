#pragma once
#include <cglm/cglm.h>

vec3 *trace_ray(vec3 O, vec3 V, vec3, float t);

typedef struct Coord_ {
  int x;
  int y;
} Coord;

Coord Coord_new(int x, int y);

typedef struct RGB_ {
  uint8_t r;
  uint8_t g;
  uint8_t b;
  uint8_t a;
} RGB;

RGB RGB_new(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

// adds colors component wise
RGB RGB_add(RGB a, RGB b);

// x must be in range (0,1]
RGB RGB_intensity(RGB color, float x);
