#include "GameObject.h"
#include "TextureManager.h"

#define xPosLine 64

GameObject::GameObject(const char *texturesheet, int w, int h)
{
    objTexture = TextureManager::LoadTexture(texturesheet);
    destRect.w = w;
    destRect.h = h;
    destRect.x = Game::widthWindow - xPosLine - destRect.w / 2;
    destRect.y = (Game::heightWindow - destRect.h) / 2;
}

GameObject::~GameObject() {}

void GameObject::UpdatePlayer(int x, int y)
{
    xpos = x;
    ypos = y;

    destRect.x = xpos - destRect.w / 2;
    destRect.y = ypos - destRect.h / 2;

    if(destRect.x + destRect.w == Boll::bollRect.x &&
       destRect.y < Boll::bollRect.y + Boll::bollRect.h &&
       destRect.y + destRect.h > Boll::bollRect.y)
        Boll::Reflection(PLAY1);

}

void GameObject::UpdateBot()
{
    if(destRect.y > Boll::bollRect.y + Boll::bollRect.h)
        destRect.y--;
    if(destRect.y + destRect.h < Boll::bollRect.y)
        destRect.y++;

    if(destRect.x == Boll::bollRect.x + Boll::bollRect.w &&
       destRect.y < Boll::bollRect.y + Boll::bollRect.h &&
       destRect.y  + destRect.h > Boll::bollRect.y)
        Boll::Reflection(PLAY2);


}

void GameObject::Render()
{
    SDL_RenderCopy(Game::renderer, objTexture, NULL, &destRect);
}