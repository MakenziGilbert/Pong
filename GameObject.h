#ifndef PONG_GAMEOBJECT_H
#define PONG_GAMEOBJECT_H

#include "Game.h"
#include "Boll.h"


class GameObject
{
public:
    GameObject(const char* texturesheet, int w, int h);
    ~GameObject();

    void UpdatePlayer(int x, int y);
    void UpdateBot();
    void Render();


private:
    int xpos;
    int ypos;

    SDL_Texture *objTexture;
    SDL_Rect destRect;
};


#endif //PONG_GAMEOBJECT_H
