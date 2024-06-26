#ifndef EVENTS_H
#define EVENTS_H

#include <SDL.h>
#include <stdbool.h>

void handleEvents(SDL_Event* event, bool* running, SDL_Rect* squareRect);

#endif
