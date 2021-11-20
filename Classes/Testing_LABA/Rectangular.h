#ifndef RECTANGULAR_H
#define RECTANGULAR_H

#include "Line.h"

class Rectangular {
public:
    Rectangular(Dot f, Dot s, Dot t, Dot l) {
        one = f;
        two = s;
        three = t;
        four = l;
        checkRectangle();
    }

    float getPerimeter();
    float getArea();

private:
    void checkRectangle();

    Dot one;
    Dot two;
    Dot three;
    Dot four;

    bool isRectangle = false;
};

#endif // RECTANGULAR_H
