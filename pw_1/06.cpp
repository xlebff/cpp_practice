#include <iostream>
using namespace std;

int main() {
    char a, b;

    cout << "Input variable a: ";
    cin >> a;
    cout << "Input variable b: ";
    cin >> b;
    
    char &ref_a = a;

    ref_a = b;

    cout << "A is '" << ref_a << "'" << endl;
}