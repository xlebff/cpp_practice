#include <iostream>
#include "array_input.h"
using namespace std;

const int CAPACITY = 3;
const string START_MSG_START = "Fill in the array of ";
const string START_MSG_END = " elements!";
const string RESULT_MSG = "The number of even numbers: ";

int main() {
    int myArray[CAPACITY];
    int evenCount = 0;

    cout << START_MSG_START << CAPACITY << START_MSG_END << endl << endl;
    fillArray(myArray, CAPACITY);

    for (int i = 0; i < CAPACITY; ++i) {
        evenCount += !(myArray[i] & 1);
    }

    cout << endl << RESULT_MSG << evenCount;

    return 0;
}