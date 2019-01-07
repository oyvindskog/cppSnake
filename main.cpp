#include "Game.h"
#include "Vector2D.h"
#include "Snake.h"

#include <iostream>

Game *game=nullptr;

int main(int argc, char** argv)
{


    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    int frameTime;


    int windowWidth = 800;
    int windowHeight = 640;
    std::cout << "lets go" << std::endl;
    std::cout << "game_init()" << std::endl;


    game = new Game();
    game->init("My Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight);
    while(game->running()){
        frameStart = SDL_GetTicks();
        game->update();
        game->handleEvents();
        game->render();
        frameTime = SDL_GetTicks() - frameStart; // how long did it all take
        if (frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime); //Delay as much as needed;
        }
    }

    game->clean();
    delete game;
    return 0;
}
