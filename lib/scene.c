#include "lib/scene.h"
#include "lib/pixel.h"
#include <cglm/cglm.h>
#include <string.h>

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
  Viewport = 
  Camera_new()
  return Scene_new(0, NULL); }
Scene *Scene_default(void) { return Scene_empty(); }

RGB Scene_calc_color(Scene *scene, vec3 viewport) {
  //CanvasToViewPort
  return RGB_new(0, 0, 0);
}

