
#pragma once
#include "utils/sphere.h"
#include "utils/types.h"
#include <cglm/cglm.h>

typedef struct Scene_ {
  int object_count;
  vec3 dims;
  Sphere **spheres;
} Scene;

Scene *Scene_new(int objs, Sphere **spheres);
Scene *Scene_empty(void);

// Returns empty scene to be rendered
Scene *Scene_default(void);

RGB Scene_calc_color(Scene *scene, int x, int y);
