#include <iostream>
#include "Rectangular.h"

using namespace std;

int main()
{
    Dot first = Dot();
    Dot second = Dot(0,2);
    Dot third = Dot(6,2);
    Dot fourth = Dot(6,0);
    Rectangular target(first, second, third, fourth);
    cout << "Perimeter: " << target.getPerimeter() << endl;
    cout << "Area: " << target.getArea() << endl;
}
