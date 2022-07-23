#include "lib/canvas.h"
#include "lib/pixel.h"
#include "lib/scene.h"
#include "lib/types.h"
#include <cglm/cglm.h>
#include <lib/ppm.h>

Coord ScreenToCanvasSpace(Canvas *canvas, Coord self);
Coord CanvasToScreenSpace(Canvas *canvas, Coord self);
vec3 CanvasToViewPort(Canvas *canvas, Coord cc);

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

int Canvas_draw(Canvas *canvas, Scene *scene) {
  int x, y;

  for (x = 0; x < canvas->w; x++) {
    for (y = 0; y < canvas->h; y++) {
      // Places pixel unto screen coords
      Coord screen_coords = Coord_new(x, y);
      Coord canvas_coords = ScreenToCanvasSpace(canvas, screen_coords);
      RGB color = Scene_calc_color(scene, canvas_coords);
      Canvas_put_pixel(canvas, screen_coords, color);
    }
  }
  return 0;
}

// Print to STDOUT the PPM codes
int Canvas_print(Canvas *canvas) {
  return printf("Canvas is printing: %p\n", (void *)canvas);
}

Coord ScreenToCanvasSpace(Canvas *canvas, Coord s) {
  int cx = s.x - (canvas->w / 2);
  int cy = s.x + (canvas->w / 2);
  return Coord_new(cx, cy);
}
Coord CanvasToScreenSpace(Canvas *canvas, Coord c) {
  int sx = (canvas->w / 2) + c.x;
  int sy = (canvas->h / 2) - c.y;
  return Coord_new(sx, sy);
}
vec3 CanvasToViewPort(Canvas *canvas, Coord cc) { float vx = cc.x * }
