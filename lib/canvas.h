#pragma once
#include "lib/pixel.h"
#include "lib/types.h"
#include "lib/scene.h"
#include <cglm/cglm.h>

typedef struct Canvas_ {
  int w;
  int h;
  int **buffer;
} Canvas;

// Returns pointer to new canvas with proper settings
Canvas *Canvas_new(int w, int h);

void Canvas_destroy(Canvas *canvas);

int Canvas_put_pixel(Canvas *canvas,Coord coord, RGB color);

// Writes to buffer the objects described in the scene
int Canvas_draw(Canvas *canvas, Scene *scene);

// Print to STDOUT the PPM codes
int Canvas_print(Canvas *canvas);
