#ifndef PONG_TEXTUREMANAGER_H
#define PONG_TEXTUREMANAGER_H

#include "Game.h"

class TextureManager {

public:
    static SDL_Texture* LoadTexture(const char *texture);
    static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
};

#endif //PONG_TEXTUREMANAGER_H
