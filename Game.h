#ifndef PONG_GAME_H
#define PONG_GAME_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "GameObject.h"
#include "Map.h"
#include "TextManager.h"
#include "Boll.h"

class Game {

public:
    Game(Game &other) = delete;
    void operator=(const Game &) = delete;
    static Game* GetInstance();

    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

    void handleEvents();
    void update() const;
    void render() const;
    void clean();
    bool running() { return isRunning; };

    static void addPoint(int player);
    static SDL_Renderer *renderer;
    static int widthWindow, heightWindow;
    static int score[2];

    static Game* game_;

private:
    Game() {}
    bool isRunning;
    SDL_Window *window;
    SDL_Point mousPos;

    bool pause = true;
};


#endif //PONG_GAME_H
