#include <iostream>
#include <string>
using namespace std;

int main() {
    int a, b;

    cout << "Input the variable a: ";
    cin >> a;
    cout << "Input the variable b: ";
    cin >> b;

    int *ptrA = &a, *ptrB = &b;

    cout << (*ptrA == *ptrB ? "The numbers are equal" :
        (*ptrA > *ptrB ? (to_string(*ptrA) + ", " + to_string(*ptrB)) : 
        (to_string(*ptrB) + ", " + to_string(*ptrA))));
}