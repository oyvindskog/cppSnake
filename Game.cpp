#include "Game.h"

#include <iostream>

Game::Game()
{
    snake = new Snake();
    snake->reset();
    food = new Food();
    std::cout << "adding food at " << food->getPos() << std::endl;
}

Game::~Game()
{

    std::cout << "destroying snake" << std::endl;
    delete snake;
    std::cout << "destroying food" << std::endl;
    delete food;
}


void Game::init(const char* title, int x, int y, int width, int height){
    int flags = 0;

    if(SDL_Init(SDL_INIT_EVERYTHING)==0){

        std::cout << "Subsystem initialized" << std::endl;
        window = SDL_CreateWindow("title", x, y, width, height, flags);
        if (window){
            std::cout << "Window created" << std::endl;
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer ){
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
            std::cout << "Renderer created" << std::endl;
        }

        backDestRect.x = 0;
        backDestRect.y = 0;
        backDestRect.w =width ;
        backDestRect.h = height ;

        isRunning = true;

    }else{
        isRunning=false;
    }
}

void Game::handleEvents(){
    SDL_Event event;
    SDL_PollEvent(&event);

    switch(event.type){
        case SDL_QUIT:
            isRunning=false;
            break;
        default:
            break;
    }

    snake->handleEvents();
    if (snake->hasCollisions()) snake->reset();
    snake->hasEaten(food);
}

void Game::render(){
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255 );
    SDL_RenderFillRect(renderer, &backDestRect );

    snake->render(renderer);
    food->render(renderer);
    SDL_RenderPresent(renderer);
}

void Game::update(){
    snake->update();
}

void Game::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "game cleaned" << std::endl;
}


bool Game::running(){
    return isRunning;
}




