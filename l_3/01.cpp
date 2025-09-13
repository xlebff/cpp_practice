#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Input the number: ";
    cin >> n;

    int &refN = n;

    cout << "Your number is ";

    if (refN == 0) cout << "zero.";
    else if (refN > 0) {
        if (refN & 1) cout << "an odd greater then zero";
        else cout << "an even greater then zero";
    } else cout << "less then zero";
}