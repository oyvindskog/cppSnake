#ifndef FOOD_H
#define FOOD_H

#include "Vector2D.h"

#include <SDL.h>


class Food
{
    public:
        Food();
        virtual ~Food();

        void update();
        void render(SDL_Renderer *renderer);

        const Vector2D &getPos();

    private:
        Vector2D position;
        int size = 10;
};

#endif // FOOD_H
