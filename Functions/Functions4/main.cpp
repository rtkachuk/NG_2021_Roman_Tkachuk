#include <iostream>

using namespace std;

int sum(int a, int b, int c) {
    return a + b + c;
}

int sum(int a, int b) {
    return sum(a, b, 0);
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << a << "+" <<
            b << "=" <<
            sum(a,b) << endl;
    cout << a << "+" <<
            b << "+" <<
            c << "=" <<
            sum(a,b,c) << endl;
    return 0;
}
