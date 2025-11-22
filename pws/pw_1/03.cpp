#include <iostream>
using namespace std;

int main() {
    int a, b;

    cout << "Input variable a: ";
    cin >> a;
    cout << "Input variable b: ";
    cin >> b;
    
    a = a ^ b;
    b = b ^ a;
    a = b ^ a;

    cout << "A is " << a << endl;
    cout << "B is " << b << endl;
}