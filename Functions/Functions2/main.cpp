#include <iostream>

using namespace std;

void drawLineOfSymbols(int sz, char symbol) {
    if (sz > 0) {
        cout << symbol;
        drawLineOfSymbols(sz - 1, symbol);
    }
}

void drawStars(int sz) {
    drawLineOfSymbols(sz, '*');
}

void drawSpaces(int sz) {
    drawLineOfSymbols(sz, ' ');
}

void drawTreeTop(int sz) {
    for (int row = 0; row <= sz; row++) {
        drawSpaces(sz - row);
        drawStars(row*2-1);
        cout << endl;
    }
}

void drawStump(int sz) {
    drawSpaces(sz-1);
    cout << "*";
}

void drawChristmasTree(int sz) {
    drawTreeTop(sz);
    drawStump(sz);
}

int getUserInput() {
    int size = 0;
    cout << "Enter size of christmas tree: ";
    cin >> size;

    return size;
}

int main()
{
    drawChristmasTree(getUserInput());
}
