#pragma once
#include <stdbool.h>
#include <SDL.h>

typedef struct KeyState_ {
  bool forward;
  bool backward;
  bool left;
  bool right;
} MovementKeyState;

void KeyState_init(void);
bool handle_keydown(SDL_Event event);
int handle_keyup(SDL_Event event);
