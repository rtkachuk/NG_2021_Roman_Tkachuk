#include <iostream>

using namespace std;

void drawLine(int sz) {
    if (sz > 0) {
        cout << "*";
        drawLine(sz-1);
    } else {
        cout << endl;
    }
}

void pyromidWorker(int curr, int sz) {
    if (curr <= sz) {
        drawLine(curr);
        pyromidWorker(curr+1, sz);
        drawLine(curr);
    }
}

void drawPyromid(int sz) {
    pyromidWorker(0, sz);
}

int main()
{
    drawPyromid(7);
    return 0;
}
