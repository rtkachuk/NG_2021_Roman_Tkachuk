#include <iostream>

using namespace std;

int main()
{
    int weight;
    cout << "Введи свой вес: ";
    cin >> weight;
    int height;
    cout << "Введи свой рост: ";
    cin >> height;

    int preferredWeight = height - 100;

    if (preferredWeight - 10 > weight)
        cout << "Вы слишком худой";
    else
        if (preferredWeight + 10 < weight)
            cout << "Вам нужно похудеть";
        else
            cout << "Вы в отличной форме!";
}
