#pragma once
#include "lib/pixel.h"
#include "lib/sphere.h"
#include "lib/types.h"
#include <cglm/cglm.h>

typedef struct Viewport_ {
  float w;
  float h;
  float distance;
} Viewport;

typedef struct Camera_ {
  vec3 pos;
  vec3 dir;
  Viewport view;
} Camera;

Camera Camera_new(vec3 pos, vec3 dir);

typedef struct Scene_ {
  Camera camera;
  Sphere **spheres;
} Scene;

Scene *Scene_new(Camera cam, Sphere **spheres);
Scene *Scene_empty(void);

// Returns empty scene to be rendered
Scene *Scene_default(void);

// Must receive coordinates in canvas space, not screen space
RGB Scene_calc_color(Scene *scene, Coord canvas_coord);
