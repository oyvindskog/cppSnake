#include "Food.h"


Food::Food()
{
    update();
}

Food::~Food()
{
    //dtor
}

void Food::render(SDL_Renderer *renderer){
    SDL_Rect r;
    // Size of food = 10 x 10
    r.x = position.getX() * 10;
    r.y = position.getY() * 10;
    r.w = r.h = 10;
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255 );
    SDL_RenderFillRect(renderer, &r );
}

void Food::update(){
    // assuming window wdith = 800 and height 640
    // size of food = 10*10
    int x = rand() % 79;
    int y = rand() % 63;
    position.setValue(x, y);
}

const Vector2D& Food::getPos(){
    return position;
}
