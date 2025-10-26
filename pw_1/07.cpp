#include <iostream>
using namespace std;

int main() {
    char a, b;

    cout << "Input variable a: ";
    cin >> a;
    cout << "Input variable b: ";
    cin >> b;
    
    char *ptr_a = &a;

    *ptr_a = b;

    cout << "A is '" << *ptr_a << "'" << endl;
}