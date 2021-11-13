#include <iostream>

using namespace std;

struct crate {
    int sz = -1;
    char sym = '%';
};

void drawLineOfSymbols(crate data) {
    for (int i=0; i<data.sz; i++) {
        cout << data.sym;
    }
}

int main()
{
    crate posilka;
    cout << "Enter size: ";
    cin >> posilka.sz;
    posilka.sym = '*';

    drawLineOfSymbols(posilka);
    return 0;
}
