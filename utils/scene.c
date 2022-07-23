#include "utils/scene.h"
#include "utils/pixel.h"
#include <cglm/cglm.h>

Scene *Scene_new(int objs, Sphere **spheres) {
  Scene *scene = (Scene *)malloc(sizeof(Scene));
  scene->object_count = objs;
  scene->spheres = spheres;
  return scene;
}
Scene *Scene_empty(void) { return Scene_new(0, NULL); }
Scene *Scene_default(void) { return Scene_empty(); }

RGB Scene_calc_color(Scene *scene, int x, int y) {
  printf("Shooting rays to (%d, %d)\n", x, y);
  printf("scene addres: %p\n", (void *)scene);
  return RGB_new(0, 0, 0);
}
