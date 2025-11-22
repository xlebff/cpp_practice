#include <iostream>
using namespace std;

int main() {
    bool a = false, b = false, c = true;
    cout << ((a && !b && c) || (!a && b && !c)) << endl;
}