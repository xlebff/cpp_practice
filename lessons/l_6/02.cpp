#include <iostream>
using namespace std;

int main() {
    string msgStart = "2 to the ", msgEnd = " degree is ";

    int ceil = 63;
    unsigned long long res = 1;

    cout << msgStart << 0 << msgEnd << 1 << endl;

    for (int i = 1, &refI = i; refI <= ceil; ++refI) {
        res *= 2;
        cout << msgStart << i << msgEnd << res << endl;
    }
}