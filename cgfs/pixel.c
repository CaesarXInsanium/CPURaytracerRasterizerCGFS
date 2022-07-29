#include "cgfs/pixel.h"
#include <limits.h>
#include <stdint.h>

uint8_t safe_add(uint8_t a, uint8_t b) {
  if (a > 0 && b > UINT8_MAX - a) {
    return UINT8_MAX;
  } else if (b < UINT8_MAX - a) {
    return 0;
  } else {
    return 0;
  }
}

uint8_t safe_mul(float a, float f) {
  float result = a * f;

  if (result > 255.0) {
    return 255.0;
  } else if (result < 0) {
    puts("Something is wrong!");
    exit(1);
  } else {
    return result;
  }
}

Coord Coord_new(int x, int y) {
  Coord n;
  n.x = x;
  n.y = y;
  return n;
}

RGB RGB_new(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
  RGB result;
  result.r = r;
  result.g = g;
  result.b = b;
  result.a = a;
  return result;
}

RGB RGB_add(RGB a, RGB b) {
  return RGB_new(safe_add(a.r, b.r), safe_add(a.g, b.g), safe_add(a.b, b.b),
                 safe_add(a.a, b.a));
}

RGB RGB_intensity(RGB color, float x) {
  float r = color.r;
  float g = color.g;
  float b = color.b;
  float a = color.a;
  return RGB_new(safe_mul(r, x), safe_mul(g, x), safe_mul(b, x),
                 safe_mul(a, x));
}
