#include <iostream>
#include "AdvancedClass.h"

using namespace std;

int main()
{
    AdvancedClass calculator(0,5);
    calculator.add();
    calculator.show();
    calculator.subst();
    calculator.show();
    calculator.mul();
    calculator.show();
}
