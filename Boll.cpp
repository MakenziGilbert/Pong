#include "Boll.h"

eDir Boll::direction;
SDL_Rect Boll::bollRect;

Boll::Boll(const char *texturesheet, int size, SDL_Point startPosition, int speed)
{
    srand(time(0));
    objTexture = TextureManager::LoadTexture(texturesheet);
    bollRect.w = bollRect.h = size;
    startPos.x = bollRect.x = startPosition.x - size / 2;
    startPos.y = bollRect.y = startPosition.y - size / 2;
    speedBoll = speed;
    sizeBoll = size;
    direction = STOP;
}

void Boll::RandomDirection()
{
    direction = (eDir)(rand()%6 + 1);
}

void Boll::Move()
{
    switch (direction)
    {
        case STOP:
            RandomDirection();
            break;
        case LEFT:
            bollRect.x -= speedBoll;
            if(bollRect.x == 0)
            {
                Game::addPoint(2);
                Reset();
            }
            break;
        case UPLEFT:
            bollRect.x -= speedBoll;
            bollRect.y -= speedBoll;
            if(bollRect.y == 0)
                Reflection(UP);
            if(bollRect.x == 0)
            {
                Game::addPoint(2);
                Reset();
            }
            break;
        case DOWNLEFT:
            bollRect.x -= speedBoll;
            bollRect.y += speedBoll;
            if(bollRect.y + sizeBoll == Game::heightWindow)
                Reflection(DOWN);
            if(bollRect.x == 0)
            {
                Game::addPoint(2);
                Reset();
            }
            break;
        case RIGHT:
            bollRect.x += speedBoll;
            if(bollRect.x + sizeBoll == Game::widthWindow)
            {
                Game::addPoint(1);
                Reset();
            }
            break;
        case UPRIGHT:
            bollRect.x += speedBoll;
            bollRect.y -= speedBoll;
            if(bollRect.y == 0)
                Reflection(UP);
            if(bollRect.x + sizeBoll == Game::widthWindow)
            {
                Game::addPoint(1);
                Reset();
            }
            break;
        case DOWNRIGHT:
            bollRect.x += speedBoll;
            bollRect.y += speedBoll;
            if(bollRect.y + sizeBoll == Game::heightWindow)
                Reflection(DOWN);
            if(bollRect.x + sizeBoll == Game::widthWindow)
            {
                Game::addPoint(1);
                Reset();
            }
            break;
    }
}

void Boll::Reset()
{
    bollRect.x = startPos.x;
    bollRect.y = startPos.y;
    RandomDirection();
}

void Boll::Reflection(typeReflection type)
{
    switch (type)
    {
        case UP:
            direction = (eDir)(int(direction) + 1);
            break;
        case DOWN:
            direction = (eDir)(int(direction) - 1);
            break;
        case PLAY1:
            if(direction == LEFT)
                direction = (eDir)(int(direction) + (3 + rand()%3));
            else
                direction = (eDir)(int(direction) + 3);
            break;
        case PLAY2:
            if(direction == RIGHT)
                direction = (eDir)(int(direction) - (1 + rand()%3));
            else
                direction = (eDir)(int(direction) - 3);
            break;
    }
}

void Boll::Render()
{
    SDL_RenderCopy(Game::renderer, objTexture, NULL, &bollRect);
}







