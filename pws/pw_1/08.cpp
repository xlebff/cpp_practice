#include <iostream>
using namespace std;

int main() {
    int a;

    cout << "Input variable a: ";
    cin >> a;
    
    int tmp = a - 1;

    bool res = !(tmp & a);

    cout << a << " is " << (res ? "a power of two" : "not a power of two") << endl;
}