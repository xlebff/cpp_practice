#include <iostream>
using namespace std;

const int CAPACITY = 100;
const int USERNAME_LENGTH = 6;
const int CASE_OFFSET = 32;
const string START_MSG = "Enter your lastname, middlename and fathername: ";

int main () {
    char str[CAPACITY];
    int currentLenght = 0;

    char username[USERNAME_LENGTH];
    int lastAdded = 1;

    cout << START_MSG;
    cin.getline(str, CAPACITY);

    for (int i = 0; i < CAPACITY; ++i) {
        if (str[i] == '\0') break;
        else ++currentLenght;
    }

    username[0] = str[0];
    username[1] = str[1];

    for (int i = 0; i < currentLenght; ++i) {
        if (str[i] != ' ') continue;
        username[++lastAdded] = ((str[i + 1] > 'Z') ? (str[i + 1]) : (str[i + 1] + CASE_OFFSET));
        username[++lastAdded] = ((str[i + 2] > 'Z') ? (str[i + 2]) : (str[i + 2] + CASE_OFFSET));
    }

    cout << "Username: ";

    for (int i = 0; i < USERNAME_LENGTH; ++i) cout << username[i];

    cout << endl;

    return 0;
}