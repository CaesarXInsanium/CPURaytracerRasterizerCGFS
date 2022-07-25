#include "lib/canvas.h"
#include "lib/pixel.h"
#include "lib/scene.h"
#include "lib/types.h"
#include <SDL2/SDL.h>
#include <cglm/cglm.h>
#include <lib/ppm.h>
#include <string.h>

Coord ScreenToCanvasSpace(Canvas *canvas, Coord self);
Coord CanvasToScreenSpace(Canvas *canvas, Coord self);
vec3 *CanvasToViewport(Canvas *canvas, Viewport *viewport, Coord cc);

Canvas *Canvas_new(int w, int h, SDL_Window *window, SDL_Surface *surface,
                   unsigned int *pixels) {
  Canvas *canvas = (Canvas *)malloc(sizeof(Canvas));
  canvas->width = w;
  canvas->height = h;
  canvas->window = window;
  canvas->surface = surface;
  canvas->pixels = pixels;
  return canvas;
}

void Canvas_destroy(Canvas *canvas) {
  SDL_DestroyWindow(canvas->window);
  free(canvas);
}

int Canvas_put_pixel(Canvas *canvas, Coord coord, RGB color) {
  int x = coord.x;
  int y = coord.y;
  Uint32 pixel =
      SDL_MapRGBA(canvas->surface->format, color.r, color.g, color.b, color.a);

  canvas->pixels[x + y * canvas->width] = pixel;
  return 0;
}
int Canvas_draw(Canvas *canvas, Scene *scene) {
  int x, y;

  for (x = 0; x < canvas->width; x++) {
    for (y = 0; y < canvas->height; y++) {
      // Places pixel unto screen coords
      Coord screen_coords = Coord_new(x, y);
      Coord canvas_coords = ScreenToCanvasSpace(canvas, screen_coords);
      vec3 *view_coords =
          CanvasToViewport(canvas, &scene->camera.view, canvas_coords);
      RGB color = Scene_calc_color(scene, *view_coords);
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
vec3 *CanvasToViewport(Canvas *canvas, Viewport *viewport, Coord cc) {
  vec3 *result = (vec3 *)malloc(sizeof(vec3));
  float vx = cc.x * (viewport->w / canvas->w);
  float vy = cc.y * (viewport->h / canvas->h);
  float vz = viewport->d;
  memcpy(result[0], (void *)&vx, sizeof(float));
  memcpy(result[1], (void *)&vy, sizeof(float));
  memcpy(result[0], (void *)&vz, sizeof(float));
  return result;
}
