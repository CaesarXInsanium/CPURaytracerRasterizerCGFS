#include "utils/canvas.h"
#include "utils/types.h"
#include <cglm/cglm.h>
#include <utils/ppm.h>

Canvas *Canvas_new(int w, int h) {
  Canvas *canvas = (Canvas *)malloc(sizeof(Canvas));
  canvas->w = w;
  canvas->h = h;
  canvas->buffer = malloc(h * (sizeof(int) * w));
  return canvas;
}

void Canvas_destroy(Canvas *canvas) {
  free(canvas->buffer);
  free(canvas);
}

int Canvas_put_pixel(Canvas *canvas, int x, int y, RGB color) {
  printf("Placed pixel on (%d,%d)\n", x, y);
  printf("Color: [%d,%d,%d]\n", color.r, color.g, color.b);
  return canvas == NULL;
}

int Canvas_draw(Canvas *canvas, Scene *scene) {
  int x, y;

  for (x = 0; x < canvas->w; x++) {
    for (y = 0; y < canvas->h; y++) {
      Canvas_put_pixel(canvas, x, y, Scene_calc_color(scene, x, y));
    }
  }
  return 0;
}

// Print to STDOUT the PPM codes
int Canvas_print(Canvas *canvas) {
  return printf("Canvas is printing: %p\n", (void *)canvas);
}
