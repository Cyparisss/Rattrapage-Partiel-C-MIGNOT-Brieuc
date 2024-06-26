#include "events.h"

void handleEvents(SDL_Event* event, bool* running, SDL_Rect* squareRect) {
    while (SDL_PollEvent(event)) {
        if (event->type == SDL_QUIT) {
            *running = false;
        }
        else if (event->type == SDL_KEYDOWN) {
            switch (event->key.keysym.sym) {
            case SDLK_UP:
                squareRect->y -= 10;
                break;
            case SDLK_DOWN:
                squareRect->y += 10;
                break;
            case SDLK_LEFT:
                squareRect->x -= 10;
                break;
            case SDLK_RIGHT:
                squareRect->x += 10;
                break;
            }
        }
    }
}
