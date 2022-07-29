#pragma once
#include "cgfs/canvas.h"

typedef struct App_ {
  Canvas *canvas;
  Scene *scene;
} App;


App App_new(int width, int height);
int App_run(App *app);
int App_close(App *app);
