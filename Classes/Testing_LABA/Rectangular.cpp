#include "Rectangular.h"

float Rectangular::getPerimeter()
{
    Line side(one, two);
    Line top(two,three);

    return side.getLenght() * 2 + top.getLenght() * 2;
}

float Rectangular::getArea()
{
    Line side(one, two);
    Line top(two,three);

    return side.getLenght() * top.getLenght();
}

void Rectangular::checkRectangle()
{
    if (one.getX() == two.getX() &&
            two.getY() == three.getY() &&
            three.getX() == four.getX() &&
            one.getY() == four.getY()) {
        isRectangle = true;
        return;
    }
    if (one.getY() == two.getY() &&
            two.getX() == three.getX() &&
            three.getY() == four.getY() &&
            one.getX() == four.getX()) {
        isRectangle = true;
        return;
    }
    isRectangle = false;
}
