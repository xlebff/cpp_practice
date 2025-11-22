#include <iostream>
#include <string>
#include "inputError.h"
using namespace std;

const int MAX_IGNORE_COUNT = 1000;
const char STOP_IGNORE_CHAR = '\n';
const string ERROR_CHAR_MSG = "Error: Not a number!";

void errorClear() {
    cin.clear();
    cin.ignore(MAX_IGNORE_COUNT, STOP_IGNORE_CHAR);
    cout << ERROR_CHAR_MSG << endl;
}