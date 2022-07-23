#include "utils/sphere.h"
#include <string.h>

Sphere Sphere_new(float r, vec3 p, RGB c) {
  Sphere sphere;
  sphere.radius = r;
  memcpy( sphere.pos,(void *)p, sizeof(vec3));
  sphere.color = c;
  return sphere;
}
