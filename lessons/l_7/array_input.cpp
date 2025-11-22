#include "array_input.h"
#include <iostream>
#include <string>

using namespace std;

const int MAX_IGNORE_COUNT = 1000;
const char STOP_IGNORE_CHAR = '\n';

const string NUMBER_MSG = "Element ";
const string COLON = ": ";
const string ERROR_MSG = "Wrong value!";

void fillArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << NUMBER_MSG << i + 1 << COLON;

        if (!(cin >> array[i])) {
            cin.clear();
            cin.ignore(MAX_IGNORE_COUNT, STOP_IGNORE_CHAR);
            cout << ERROR_MSG << endl;
            --i;
        } else continue;
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << NUMBER_MSG << i + 1 << COLON << array[i] << endl;
    }
}