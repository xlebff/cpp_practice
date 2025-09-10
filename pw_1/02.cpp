#include <iostream>
using namespace std;

int main() {
    double a, b;

    cout << "Input variable a: ";
    cin >> a;
    cout << "Input variable b: ";
    cin >> b;

    double *ptr1 = &a, &ref2 = b;

    *ptr1 *= 1.3;
    ref2 -= a;

    cout << "A is " << a << endl;
    cout << "B is " << b << endl;
}