#include <iostream>
using namespace std;

int main() {
    int a, b;

    cout << "Input variable a: ";
    cin >> a;
    cout << "Input variable b: ";
    cin >> b;

    int *ptr_a = &a, *ptr_b = &b;

    cout << "a + b = " << (a + b) << endl;
    cout << "a - b = " << (a - b) << endl;
    cout << "a * b = " << (a * b) << endl;
    cout << "a / b = " << (a / b) << endl;
    cout << "a % b = " << (a % b) << endl;
    cout << "a and b = " << (a & b) << endl;
    cout << "a or b = " << (a | b) << endl;
    cout << "a xor b = " << (a ^ b) << endl;
    cout << "address of a is " << ptr_a << endl;
    cout << "address of b is " << ptr_b << endl;
    cout << "increment of an address of a is " << ++ptr_a << endl;
    cout << "increment of an address of b is " << ++ptr_b << endl;
    cout << "decrement of an address of a is " << --(--ptr_a) << endl;
    cout << "decrement of an address of b is " << --(--ptr_b) << endl;
}