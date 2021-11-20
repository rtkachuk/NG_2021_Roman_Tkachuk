#ifndef LINE_H
#define LINE_H

#include "Dot.h"
#include <math.h>

class Line {
public:
    Line () {
        configureVariables(Dot(0,0), Dot(0,0));
    }

    Line (Dot a, Dot b) {
        configureVariables(a,b);
    }

    Dot getBeginDot() { return begin; }
    void setBeginDot(Dot begin) { this->begin = begin; calculateLeght();}
    Dot getEndDot() { return end; }
    void setEndDot(Dot end) { this->end = end; calculateLeght();}

    float getLenght() { return length; }

private:
    void calculateLeght();
    void configureVariables(Dot a, Dot b);

    Dot begin;
    Dot end;
    float length;
};

#endif // LINE_H
