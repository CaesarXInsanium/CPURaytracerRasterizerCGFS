#include "lib/scene.h"
#include "lib/pixel.h"
#include <cglm/cglm.h>
#include <string.h>

Viewport Viewport_new(float w, float h, float d) {
  Viewport view;
  view.w = w;
  view.h = h;
  view.d = d;
  return view;
}
Camera Camera_new(vec3 pos, vec3 dir, Viewport viewport) {
  Camera cam;
  memcpy(cam.pos, pos, sizeof(vec3));
  memcpy(cam.dir, dir, sizeof(vec3));
  cam.view = viewport;
  return cam;
}

Scene *Scene_new(Camera cam, Sphere **spheres) {
  Scene *scene = (Scene *)malloc(sizeof(Scene));
  scene->spheres = spheres;
  scene->camera = cam;
  return scene;
}
Scene *Scene_empty(void) {
  Viewport view = Viewport_new(10, 10, 10);
  vec3 cpos = {0, 0, 0};
  vec3 cdir = {0, 0, 1};
  Camera cam = Camera_new(cpos, cdir, view);

  return Scene_new(cam, NULL);
}
Scene *Scene_default(void) { return Scene_empty(); }

RGB Scene_calc_color(Scene *scene, vec3 view_coords) {
  
  return RGB_new(0, 0, 0);
}
