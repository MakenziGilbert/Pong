#ifndef PONG_BOLL_H
#define PONG_BOLL_H

#include <time.h>
#include "Game.h"
#include "TextureManager.h"

enum eDir { STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6};
enum typeReflection { UP = 0, DOWN = 1, PLAY1 = 2, PLAY2 = 3};

class Boll
{
public:
    Boll(const char* texturesheet, int size, SDL_Point startPos, int speed);

    void Move();
    void Render();
    static void Reflection(typeReflection type);
    void Reset();
    void RandomDirection();

    static SDL_Rect bollRect;
    static eDir direction;
private:
    SDL_Point startPos;
    SDL_Texture *objTexture;
    int speedBoll;
    int sizeBoll;
};


#endif //PONG_BOLL_H
