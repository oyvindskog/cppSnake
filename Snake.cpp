#include "Snake.h"

#include <memory>


Snake::Snake()
{
    //ctor
}

Snake::~Snake()
{
    //dtor
}

void Snake::render(SDL_Renderer *renderer){
    for (auto const& pos: bodyparts){
        SDL_Rect r;
        // Size of bodyparts = 10
        r.x = pos->getX() * 10;
        r.y = pos->getY() * 10;
        r.w = r.h = 10;
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255 );
        SDL_RenderFillRect(renderer, &r );
    }
}

void Snake::handleEvents(){
    const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
    if( currentKeyStates[ SDL_SCANCODE_UP ] ){
        direction = Vector2D(0, -1);
    }
    if( currentKeyStates[ SDL_SCANCODE_DOWN ] ){
        direction = Vector2D(0, 1);
    }
    if( currentKeyStates[ SDL_SCANCODE_LEFT ] ){
        direction = Vector2D(-1, 0);
    }
    if( currentKeyStates[ SDL_SCANCODE_RIGHT ] ){
        direction = Vector2D(1, 0);
    }
}

void Snake::update(){
    int length = bodyparts.size();
    for(int i=length-1; i>0; i--) {
        *bodyparts[i] = *bodyparts[i-1];
    }
    *bodyparts[0].get() += direction;


}

void Snake::addBodyPart(const Vector2D &pos){
    bodyparts.push_back(std::make_unique<Vector2D>(pos));
}



