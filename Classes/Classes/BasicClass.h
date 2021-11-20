#ifndef BASICCLASS_H
#define BASICCLASS_H

#include <iostream>

using namespace std;

class BasicClass {
public:
    void add();
    void subst();
    void show ();

    int getFirstValue() { return a; }
    void setFirstValue(int val1);

    int getSecondValue() { return b; }
    void setSecondValue(int val2);

private:
    int a;
    int b;

protected:
    int result;
};

#endif // BASICCLASS_H
