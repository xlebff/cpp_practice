#include <iostream>
using namespace std;

int main() {
    double a, b, c;

    cout << "Input variable a: ";
    cin >> a;
    cout << "Input variable b: ";
    cin >> b;
    cout << "Input variable c: ";
    cin >> c;

    double *ptr1 = &a, *ptr2 = &b, *ptr3 = &c;

    double res = (*ptr1 + *ptr2 + *ptr3) / 3;

    cout << "Average" << res << endl;
}