#include <iostream>
#include "asking.h"
#include "cinHandler.h"
using namespace std;

const char CONTINUATION_CHOICE_MSG[] = "Wanna continue? (y/n): ";
const char YES = 'y';
const char NO = 'n';

bool getChoice(const char* question) {
    char choice;

    do {
        cout << question;
        if (!(cin >> choice)) {
            errorClear();
            continue;
        }
        choice = tolower(choice);
    } while (choice != YES && choice != NO);

    return choice == YES;
}