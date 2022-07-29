#pragma once
#include "cgfs/pixel.h"
#include "cgfs/scene.h"
#include "cgfs/types.h"
#include <SDL2/SDL.h>
#include <cglm/cglm.h>

typedef struct Canvas_ {
  int width;
  int height;
  SDL_Window *window;
  SDL_Surface *surface;
  unsigned int *pixels;
} Canvas;

// Returns pointer to new canvas with proper settings
Canvas *Canvas_new(int w, int h, SDL_Window *window, SDL_Surface *surface,
                   unsigned int *pixels);

void Canvas_destroy(Canvas *canvas);

int Canvas_put_pixel(Canvas *canvas, Coord coord, RGB color);

int Canvas_clear(Canvas *canvas);
// Writes to buffer the objects described in the scene
int Canvas_draw(Canvas *canvas, Scene *scene);

// Print to STDOUT the PPM codes
int Canvas_print(Canvas *canvas);
