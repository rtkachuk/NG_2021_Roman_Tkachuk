#include "AdvancedClass.h"

AdvancedClass::AdvancedClass(int val1, int val2) {
    setFirstValue(val1);
    setSecondValue(val2);
}

void AdvancedClass::mul() {
    result = getFirstValue() * getSecondValue();
}

void AdvancedClass::div() {
    result = getFirstValue() / getSecondValue();
}
