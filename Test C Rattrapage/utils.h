#ifndef UTILS_H
#define UTILS_H

#include <SDL.h>
#include <stdbool.h>

bool initSDL();
void cleanupSDL(SDL_Renderer* renderer, SDL_Window* window);

#endif
