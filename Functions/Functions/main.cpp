#include <iostream>

using namespace std;

void drawLineOfSymbols(int sz, char symbol) {
    for (int i=0; i<sz; i++)
        cout << symbol;
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
