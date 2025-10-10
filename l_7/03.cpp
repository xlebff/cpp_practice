#include <iostream>
#include "array_input.h"
using namespace std;

const int CAPACITY = 5;

const string START_MSG_START = "Enter the numbers of the ";
const string START_MSG_END = " products ^^";
const string RESULT_MSG = "Result: ";

int main() {
    int myArray[CAPACITY];

    cout << START_MSG_START << CAPACITY << START_MSG_END << endl << endl;
    fillArray(myArray, CAPACITY);

    int evenIndex = 0;

    for (int i = 0; i < CAPACITY; ++i) {
        if (!(myArray[i] & 1)) {
            myArray[evenIndex] ^= myArray[i];
            myArray[i] ^= myArray[evenIndex];
            myArray[evenIndex] ^= myArray[i];
            
            ++evenIndex;
        }
    }

    cout << endl << RESULT_MSG << endl;
    printArray(myArray, CAPACITY);

    return 0;
}