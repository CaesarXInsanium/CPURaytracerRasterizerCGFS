#include "event.h"
#include <stdio.h>

int handle_event(SDL_Event event){
  printf("Handling event:\t%p\n", (void *)&event);
  return EXIT_SUCCESS;
}
