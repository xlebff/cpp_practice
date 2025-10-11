#include <iostream>
using namespace std;

const int CAPACITY = 100;
const string START_MSG = "Enter your string: ";

int main () {
    char str[CAPACITY];
    int currentLength = 0;

    cout << START_MSG;
    cin.getline(str, CAPACITY);

    for (int i = 0; i < CAPACITY; ++i) {
        if (str[i] == '\0') break;
        ++currentLength;
    }

    for (int i = 0; i < currentLength; ++i) {
        if (*(str + i) >= 'A' && *(str + i) <= 'Z') {
            if (str[i] == 'Z') {
                str[i] = 'A';
                continue;
            } else {
                ++str[i];
            }
        } else if (str[i] >= 'a' && str[i] <= 'z') {
            if (str[i] == 'z') {
                str[i] = 'a';
                continue;
            } else {
                ++str[i];
            }
        }
    }

    cout << "New string: ";

    for (int i = 0; i < currentLength; ++i) cout << str[i];

    cout << endl;

    return 0;
}