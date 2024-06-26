#include <stdio.h>
#include <SDL.h>
#include "game.h"

int main() {
    const char* title = "SDL Game";
    int screenWidth = 800;
    int screenHeight = 600;

    Game game;

    if (!initGame(&game, title, screenWidth, screenHeight)) {
        fprintf(stderr, "Failed to initialize the game.\n");
        return -1;
    }

    while (game.isRunning) {
        processInput(&game);
        updateGame(&game);
        renderGame(&game);
    }

    cleanupGame(&game);

    return 0;
}
