#include "Line.h"

void Line::calculateLeght()
{
    float differenceX = end.getX() - begin.getX();
    float squareDifferenceX = pow(differenceX, 2);
    float differenceY = end.getY() - begin.getY();
    float squareDifferenceY = pow(differenceY, 2);
    length = sqrt(squareDifferenceX + squareDifferenceY);
}

void Line::configureVariables(Dot a, Dot b) {
    begin = a;
    end = b;
    calculateLeght();
}
