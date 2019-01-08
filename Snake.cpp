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

void Snake::reset(){
    bodyparts.clear();
    for (int i=0; i<10; ++i){
        const Vector2D part = Vector2D(20-i, 20);
        this->addBodyPart(part);
    }
    direction.setValue(1, 0);
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

void Snake::hasEaten(Food *food){
     auto head = *bodyparts[0].get();
     const Vector2D v(-1,-1);
     if (head == food->getPos()) {
        for (int i=0; i<5; i++){
            this->addBodyPart(v);
        }
        food->update();
     }
}

bool Snake::hasCollisions(){
    int length = bodyparts.size();
    // Collision with self
    for (int i=1; i<length; ++i){
        if (*bodyparts[0] == *bodyparts[i]) return true;
    }
    // Checking for wall collision assuming width = 800
    // and height = 640... bodypart size = 10
    auto head = *bodyparts[0].get();
    return
        head.getX() < 0 ||
        head.getY() < 0 ||
        head.getX() > 79 ||
        head.getY() > 63;
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



