#include <iostream>
using namespace std;

int main() {
    int volume;
    cout << "Enter the volume level: ";
    cin >> volume;

    while ((volume > 10) || (volume < 0)) {
        cout << "Incorrect volume level. ";
        cin >> volume;
    }

    if (volume < 3) cout << "quietly";
    else if (volume < 6) cout << "medium";
    else cout << "loudly";
}