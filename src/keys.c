#include "keys.h"
#include "SDL_scancode.h"
#include <SDL.h>

static MovementKeyState state;

void KeyState_init(void) {
  state.forward = false;
  state.backward = false;
  state.right = false;
  state.right = false;
}

bool handle_keydown(SDL_Event event) {
  bool quit = false;
  switch (event.key.keysym.scancode) {
  case SDL_SCANCODE_W:
    if (!state.forward)
      puts("Goin forward");
    state.forward = true;
    break;
  case SDL_SCANCODE_S:
    if (!state.backward)
      puts("Goin backward");
    state.backward = true;
    break;
  case SDL_SCANCODE_D:
    if (!state.right)
      puts("Goin right");
    state.right = true;
    break;
  case SDL_SCANCODE_A:
    if (!state.left)
      puts("Goin left");
    state.left = true;
    break;
  case SDL_SCANCODE_ESCAPE:
    quit = true;
    break;
  default:
    printf("Key down: %d\n", event.key.keysym.scancode);
    break;
  }

  return quit;
}
int handle_keyup(SDL_Event event) {

  switch (event.key.keysym.scancode) {
  case SDL_SCANCODE_W:
    if (state.forward)
      puts("not Goin forward");
    state.forward = false;
    break;
  case SDL_SCANCODE_S:
    if (state.backward)
      puts("not Goin backward");
    state.backward = false;
    break;
  case SDL_SCANCODE_D:
    if (state.right)
      puts("not Goin right");
    state.right = false;
    break;
  case SDL_SCANCODE_A:
    if (state.left)
      puts("not Goin left");
    state.left = false;
    break;
  default:
    printf("Key down: %d\n", event.key.keysym.scancode);
    break;
  }
  return 0;
}
