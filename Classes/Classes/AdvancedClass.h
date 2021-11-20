#ifndef ADVANCEDCLASS_H
#define ADVANCEDCLASS_H

#include "BasicClass.h"

class AdvancedClass : public BasicClass {
public:
    AdvancedClass (int val1, int val2);

    void mul();
    void div();
};

#endif // ADVANCEDCLASS_H
