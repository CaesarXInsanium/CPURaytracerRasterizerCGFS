#include "lib/canvas.h"
#include "lib/scene.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 800

int main(void) {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window *window =
      SDL_CreateWindow("SDL Raytracer", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, 800, 800, ~SDL_WINDOW_RESIZABLE);
  SDL_Surface *window_surface = SDL_GetWindowSurface(window);
  unsigned int *pixels = window_surface->pixels;
  Canvas *canvas = Canvas_new(WIDTH, HEIGHT, window, window_surface, pixels);

  while (1) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        exit(EXIT_SUCCESS);
      }

      //
      // Display the pixel buffer here.
      //
    }
  }
  return EXIT_SUCCESS;
}
