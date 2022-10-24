#include "TextManager.h"

void TextManager::ShowText(char* text, int xPos, int yPos, int size)
{
    TTF_Init();
    SDL_Color textColor = {255, 255, 255, 255};
    TTF_Font *font = TTF_OpenFont("/home/makenzi/CLionProjects/Pong/Montserrat-Black.ttf", size);
    std::cout << SDL_GetError() << std::endl;

    SDL_Surface *textSurface = TTF_RenderText_Solid(font, text, textColor);
    SDL_Rect textPosition = {xPos - textSurface->w/2, yPos, textSurface->w, textSurface->h};
    SDL_Texture* mTexture =  SDL_CreateTextureFromSurface(Game::renderer,textSurface);
    SDL_RenderCopy(Game::renderer,mTexture,NULL,&textPosition);

    TTF_Quit();
}
