#include <iostream>

using namespace std;

int main()
{
    int starsAmount = 10;
    int currentItem = 0;
    cout << "While: " << endl;
    cout << "=======================================================" << endl;
    while (currentItem < starsAmount) {
        cout << "*";
        currentItem++;
    }

    cout << endl;
    cout << "Do - while: " << endl;
    cout << "=======================================================" << endl;
    currentItem = 0; // Don't forget!
    do {
        cout << "*";
        currentItem++;
    } while (currentItem < starsAmount);

    cout << endl;
    cout << "For: " << endl;
    cout << "=======================================================" << endl;
    for (int forItem=0; forItem < starsAmount; forItem++)
        cout << "*";
}
