#include "Game.h"

#define widthLine 16
#define heightLine 64
#define sizeBoll 20
#define xPosLine 64

Map *map;
GameObject *playerLine;
GameObject *botLine;
Boll *boll;

Game* Game::game_ = nullptr;
SDL_Renderer* Game::renderer = nullptr;
int Game::widthWindow, Game::heightWindow;
int Game::score[2]{0, 0};

Game *Game::GetInstance()
{
    if(game_==nullptr){
        game_ = new Game();
    }
    return game_;
}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flag = 0;
    if(fullscreen)
    {
        flag = SDL_WINDOW_FULLSCREEN;
    }


    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "Subsystems Initialised!..." << std::endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flag);
        if(window)
        {
            std::cout << "Window create!" << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer created!" << std::endl;
        }

        isRunning = true;
    } else {
        isRunning = false;
    }

    SDL_GetWindowSize(window, &widthWindow, &heightWindow);
    map = new Map();

    playerLine = new GameObject("/home/makenzi/CLionProjects/Pong/Textures/line1.png", widthLine, heightLine);
    botLine = new GameObject("/home/makenzi/CLionProjects/Pong/Textures/line2.png", widthLine, heightLine);
    boll = new Boll("/home/makenzi/CLionProjects/Pong/Textures/sphere.png", sizeBoll, SDL_Point{widthWindow/2, heightWindow/2}, 1);
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_MOUSEMOTION:
            SDL_GetMouseState(&mousPos.x, &mousPos.y);
            break;
        case SDL_MOUSEBUTTONUP:
            pause = !pause;
            break;
        default:
            break;
    }
}

void Game::update() const
{
    if(!pause)
    {
        boll->Move();
        playerLine->UpdatePlayer(xPosLine, mousPos.y);
        botLine->UpdateBot();
    }
}

void Game::addPoint(int player)
{
    score[player-1]++;
    if(score[player-1] == 10)
    {
        if(player == 1)
        {
            char text[10] = "You wine!";
            TextManager::ShowText(text, widthWindow / 2, 50, 32);
            SDL_RenderPresent(renderer);
            SDL_Delay(1000);
        } else {
            char text[10] = "You lose!";
            TextManager::ShowText(text, widthWindow / 2, 50, 32);
            SDL_RenderPresent(renderer);
            SDL_Delay(1000);
        }

        score[0] = score[1] = 0;
    }
}

void Game::render() const
{
    SDL_RenderClear(renderer);

    map->DrawMap();
    playerLine->Render();
    botLine->Render();
    boll->Render();

    char textScore1 = char(48 + score[0]);
    TextManager::ShowText(&textScore1, widthWindow / 2 - 100, 50, 52);
    char textScore2 = char(48 + score[1]);
    TextManager::ShowText(&textScore2, widthWindow / 2 + 100, 50, 52);

    if(pause)
    {
        char text[6] = "Pause";
        TextManager::ShowText(text, widthWindow / 2, 50, 32);
    }

    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Cleaned" << std::endl;
}