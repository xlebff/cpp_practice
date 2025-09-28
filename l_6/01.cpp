#include <iostream>
using namespace std;

int main() {
    string fact = "Factorial: ";

    int n;
    cout << "Input your number: ";
    cin >> n;

    if (n < 0) {
        cout << "The number is incorrect!";
        return 1;
    }

    if (n == 1 || n == 0) {
        cout << fact << n;
        return 0;
    }

    if (n > 65) {
        cout << "Too long...";
        return 2;
    }

    unsigned long long res = 1;

    for (int i = 2, &refI = i; refI <= n; ++refI) {
        res *= refI;
    }

    cout << fact << res;
}