#include <iostream>
using namespace std;

int main() {
    int a;

    cout << "Input variable a: ";
    cin >> a;

    bool res = a & 1;

    cout << a << " is " << (res ? "an odd" : "an even") << endl;
}