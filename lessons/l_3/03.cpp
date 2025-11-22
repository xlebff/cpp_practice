#include <iostream>
using namespace std;

int main() {
    int a, b;

    cout << "Input the variable a: ";
    cin >> a;
    cout << "Input the variable b: ";
    cin >> b;

    int *ptrA = &a, *ptrB = &b;

    if ((a & 1) == (b & 1)) {
        if ((a & 1) == 0) {
            *ptrA *= 2;
            *ptrB *= 2;            
        } else {
            *ptrA /= 2;
            *ptrB /= 2;
        }
    } else {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }

    cout << "The new value a is " << *ptrA << endl;
    cout << "The new value b is " << *ptrB << endl;
}