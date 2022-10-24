#ifndef PONG_MAP_H
#define PONG_MAP_H

#include "Game.h"

class Map
{
public:

    Map();
    ~Map();

    void DrawMap();

private:
    SDL_Rect src, dest;
    SDL_Texture* field;
    SDL_Texture* middleLine;
};

#endif //PONG_MAP_H
