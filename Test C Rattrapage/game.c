#include "game.h"

bool initGame(Game* game, const char* title, int width, int height) {
    if (!initSDL()) {
        return false;
    }

    game->window = createWindow(title, width, height);
    if (!game->window) {
        cleanupGame(game);
        return false;
    }

    game->renderer = createRenderer(game->window);
    if (!game->renderer) {
        cleanupGame(game);
        return false;
    }

    game->image = loadTexture(game->renderer, "image.bmp");
    if (!game->image) {
        cleanupGame(game);
        return false;
    }

    game->imgRect.x = (width - game->imgRect.w) / 2;
    game->imgRect.y = (height - game->imgRect.h) / 2;

    game->windowWidth = width;
    game->windowHeight = height;
    game->isRunning = true;

    return true;
}

void processInput(Game* game) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            game->isRunning = false;
            break;
        }
    }
}

void updateGame(Game* game) {
    // Add game logic update here if needed
}

void renderGame(Game* game) {
    SDL_SetRenderDrawColor(game->renderer, 255, 255, 255, 255);
    SDL_RenderClear(game->renderer);

    SDL_RenderCopy(game->renderer, game->image, NULL, &game->imgRect);

    SDL_RenderPresent(game->renderer);
}

void cleanupGame(Game* game) {
    if (game->image) {
        SDL_DestroyTexture(game->image);
    }
    cleanupSDL(game->renderer, game->window);
}
