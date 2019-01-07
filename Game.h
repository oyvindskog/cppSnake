#ifndef GAME_H
#define GAME_H

#include "Snake.h"

#include <SDL.h>


class Game
{
    public:
        Game();
        virtual ~Game();

        void init(const char* title, int x, int y, int width, int height);
        void clean();
        bool running();
        void render();
        void update();
        void handleEvents();

    private:
        bool isRunning;

        SDL_Window *window = nullptr;
        SDL_Texture* backgroundTexture = nullptr;
        SDL_Rect backSrcRect, backDestRect;
        SDL_Renderer* renderer = nullptr;
        Snake *snake = nullptr;
};

#endif // GAME_H
