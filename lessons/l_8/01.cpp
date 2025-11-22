#include <iostream>
#include "array.h"
using namespace std;

const string START_MSG = "Enter the size of the array: ";
const string FILL_MSG = "Fill the array!";
const string ARRAY_MSG = "Your array: ";
const string ELEMENT = "Element ";
const string COLON = ": ";

int main() {
    int size = getSize(START_MSG, 1, 100);
    
    int *myArray = new int[size];

    cout << endl << FILL_MSG << endl;

    fillArray(ELEMENT, COLON, myArray, size);

    cout << endl << ARRAY_MSG << endl;
    
    printArray(ELEMENT, COLON, myArray, size, true);

    delete[] myArray;
    return 0;
}