#include "BasicClass.h"

void BasicClass::add() {
    result = a + b;
}

void BasicClass::subst() {
    result = a - b;
}

void BasicClass::show() {
    cout << "Result: " << result << endl;
}

void BasicClass::setFirstValue(int val1) {
    if (val1 > 0)
        a = val1;
    else {
        cout << "[DEBUG]: WRONG VALUE PASSED! DEFAULTS TO 1" << endl;
        a = 1;
    }
}

void BasicClass::setSecondValue(int val2) {
    if (val2 > 0)
        b = val2;
    else {
        cout << "[DEBUG]: WRONG VALUE PASSED! DEFAULTS TO 1" << endl;
        b = 1;
    }
}
