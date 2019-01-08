#include "Vector2D.h"

Vector2D::Vector2D(){}

Vector2D::Vector2D(int initX, int initY)
:x(initX), y(initY)
{
    //ctor
}

Vector2D::Vector2D(const Vector2D &pos)
{
    x = pos.x;
    y = pos.y;
}

Vector2D::~Vector2D()
{
    //dtor
}

int Vector2D::getX(){
    return x;
}

int Vector2D::getY(){
    return y;
}

void Vector2D::setValue(int newX, int newY) {
    x = newX;
    y = newY;
}

void Vector2D::operator+=(const Vector2D &v){
    x += v.x;
    y += v.y;
}

bool Vector2D::operator==(const Vector2D &v){
    return x == v.x && y==v.y;
}


std::ostream& operator<<(std::ostream& stream, const Vector2D& v) {

    stream << "(" << v.x << "," << v.y << ")";
    return stream;
}
