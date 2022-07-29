#pragma once
#include "cgfs/types.h"
#include "cgfs/pixel.h"
#include <cglm/cglm.h>

typedef struct Sphere_ {
  float radius;
  vec3 pos;
  RGB color;
} Sphere;

Sphere Sphere_new(float r, vec3 p, RGB c);
