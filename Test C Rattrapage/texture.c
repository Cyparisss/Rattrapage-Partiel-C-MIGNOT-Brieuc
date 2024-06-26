#include "texture.h"

SDL_Texture* loadTexture(const char* file, SDL_Renderer* renderer) {
    SDL_Surface* tempSurface = IMG_Load(file);
    if (!tempSurface) {
        SDL_Log("Unable to load image %s: %s", file, IMG_GetError());
        return NULL;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    return texture;
}
