#include "utils/canvas.h"
#include "utils/scene.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  Canvas *canvas = Canvas_new(400, 400);
  Scene *scene = Scene_default();
  int draw_success = Canvas_draw(canvas, scene);
  int success = Canvas_print(canvas);
  return success + draw_success;
}
