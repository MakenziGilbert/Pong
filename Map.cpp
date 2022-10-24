#include "Map.h"
#include "TextureManager.h"

Map::Map()
{
    field = TextureManager::LoadTexture("/home/makenzi/CLionProjects/Pong/Textures/field.png");
    middleLine = TextureManager::LoadTexture("/home/makenzi/CLionProjects/Pong/Textures/middleLine.png");

    dest.w = 16;
    dest.h = Game::heightWindow;
    dest.x = (Game::widthWindow - dest.w) / 2;
    dest.y = 0;


}

Map::~Map() {}

void Map::DrawMap()
{
    SDL_RenderCopy( Game::renderer, field, NULL, NULL);
    SDL_RenderCopy(Game::renderer, middleLine, NULL, &dest);
}