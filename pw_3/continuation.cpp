#include <iostream>
#include <string>
#include "continuation.h"
#include "inputError.h"
using namespace std;

const string MSG = "Wanna continue? (y/n): ";
const char YES = 'y';
const char NO = 'n';

bool getChoice() {
    char choice;

    do {
        cout << MSG;
        if (!(cin >> choice)) {
            errorClear();
            continue;
        }
        choice = tolower(choice);
    } while (choice != YES && choice != NO);

    cout << endl;
    return choice == YES;
}