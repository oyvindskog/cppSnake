#ifndef SNAKE_H
#define SNAKE_H

#include "Vector2D.h"

#include <SDL.h>

#include <vector>
#include <memory>

class Snake
{
    public:
        Snake();
        virtual ~Snake();

        void addBodyPart(const Vector2D &position);
        void render(SDL_Renderer *renderer);
        void update();
        void handleEvents();



    private:
        std::vector<std::unique_ptr<Vector2D> > bodyparts;
        Vector2D direction = Vector2D(1,0);
};

#endif // SNAKE_H
