#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>

class Vector2D
{
    public:
        Vector2D(int initX, int initY);
        Vector2D(const Vector2D &pos);
        virtual ~Vector2D();

        int getX();
        int getY();
        void operator+=(const Vector2D &v);

        friend std::ostream& operator<< (std::ostream& stream, const Vector2D& v);

    private:
        int x;
        int y;


};

#endif // VECTOR2D_H
