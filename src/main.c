#include "lib/canvas.h"
#include "lib/scene.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 800
int handle_keydown(SDL_Event event);

int main(void) {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window *window = SDL_CreateWindow("SDL Raytracer", SDL_WINDOWPOS_CENTERED,
                                        SDL_WINDOWPOS_CENTERED, 800, 800, 0);
  if (window == NULL) {
    printf("Error: %s\n", SDL_GetError());
    printf("Failed to Create Window!!");
    exit(1);
  }
  SDL_Surface *window_surface = SDL_GetWindowSurface(window);
  unsigned int *pixels = window_surface->pixels;

  Canvas *canvas = Canvas_new(WIDTH, HEIGHT, window, window_surface, pixels);

  int is_running = 1;
  while (is_running) {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {

    case SDL_KEYDOWN:
      printf("Key press detected\n");
      handle_keydown(event);
      break;
    case SDL_KEYUP:
      printf("Key release detected\n");
      break;

    case SDL_QUIT:
      Canvas_destroy(canvas);
      is_running = 0;
      break;
    default:
      break;
    }
  }
  return EXIT_SUCCESS;
}
int handle_keydown(SDL_Event event) {
  printf("Key down: %d\n", event.key.keysym.scancode);
  return 0;
}
