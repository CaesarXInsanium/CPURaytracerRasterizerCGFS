#include "app.h"
#include "event.h"
#include "keys.h"

App App_new(int width, int height) {
  App app;
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window *window =
      SDL_CreateWindow("SDL Raytracer", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, width, height, 0);
  if (window == NULL) {
    printf("Error: %s\n", SDL_GetError());
    printf("Failed to Create Window!!");
    exit(1);
  }
  SDL_Surface *window_surface = SDL_GetWindowSurface(window);
  unsigned int *pixels = window_surface->pixels;

  Canvas *canvas = Canvas_new(width, height, window, window_surface, pixels);
  Scene *scene = Scene_empty();
  KeyState_init();
  app.canvas = canvas;
  app.scene = scene;
  return app;
}

int App_run(App *app) {
  bool is_running = true;
  Canvas_clear(app->canvas);
  while (is_running) {
    SDL_Event event;
    bool request_draw = true;
    SDL_PollEvent(&event);
    switch (event.type) {

    case SDL_KEYDOWN:
      is_running = !handle_keydown(event);
      break;
    case SDL_KEYUP:
      handle_keyup(event);
      break;

    case SDL_QUIT:
      Canvas_destroy(app->canvas);
      break;
    default:
      // handle_event(event);
      request_draw = false;
      break;
    }

    if (request_draw) {
      Canvas_clear(app->canvas);
      //Canvas_draw(app->canvas, app->scene);
    }
  }
  return EXIT_SUCCESS;
}

int App_close(App *app) {
  Canvas_destroy(app->canvas);
  return EXIT_SUCCESS;
}
