#include <iostream>
#include "array_input.h"
using namespace std;

const int CAPACITY = 3;

const string START_MSG_START = "Fill in the array of ";
const string START_MSG_END = " elements!";
const string RESULT_MSG = "The difference between maximum and minimum values of the array is ";
const string DOT = ".";
const string EQUAL_MSG = "The maximum and minimum values of the array are the same!";

int main() {
    int myArray[CAPACITY];

    cout << START_MSG_START << CAPACITY << START_MSG_END << endl << endl;
    fillArray(myArray, CAPACITY);
    
    int maxNumber = *myArray, minNumber = *myArray, difference = 0;

    for (int i = 0; i < CAPACITY; ++i) {
        maxNumber = maxNumber > *(myArray + i) ? maxNumber : *(myArray + i);
        minNumber = minNumber < *(myArray + i) ? minNumber : *(myArray + i);
    }

    if (maxNumber != minNumber) {
        difference = maxNumber - minNumber;
        cout << endl << RESULT_MSG << difference << DOT << endl;
    } else {
        cout << endl << EQUAL_MSG << endl;
    }

    return 0;
}