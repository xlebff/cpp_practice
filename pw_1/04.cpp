#include <iostream>
using namespace std;

int main() {
    int a, n;

    cout << "Input variable a: ";
    cin >> a;
    cout << "Input variable n: ";
    cin >> n;
    
    a <<= n;

    cout << "A * 2^" << n << " is " << a << endl;
}