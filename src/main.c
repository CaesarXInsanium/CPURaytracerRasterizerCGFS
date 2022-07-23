#include "lib/canvas.h"
#include "lib/scene.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  Canvas *canvas = Canvas_new(800, 600);
  Scene *scene = Scene_default();
  int draw_success = Canvas_draw(canvas, scene);
  int success = Canvas_print(canvas);
  return success + draw_success;
}
