#include "app.h"
#include "cgfs/canvas.h"
#include "cgfs/scene.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 800

int main(void) {
  App app = App_new(800, 600);
  App_run(&app);
  int status  = App_close(&app);
  return status;
}
