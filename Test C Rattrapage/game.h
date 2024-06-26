#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <stdbool.h>
#include "window.h"
#include "renderer.h"
#include "texture.h"
#include "utils.h"

typedef struct {
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* image;
    SDL_Rect imgRect;
    int windowWidth;
    int windowHeight;
    bool isRunning;
} Game;

bool initGame(Game* game, const char* title, int width, int height);
void processInput(Game* game);
void updateGame(Game* game);
void renderGame(Game* game);
void cleanupGame(Game* game);

#endif
