#include <iostream>
#include "array.h"
using namespace std;

const string START_MSG = "Enter the size of the array: ";
const string FILL_MSG = "Fill the array!";
const string SUM_MSG = "Sum of elements of your array: ";
const string ELEMENT = "Element ";
const string COLON = ": ";

int main() {
    int size = 0;
    int res = 0;

    size = getSize(START_MSG, 1, 100);
    
    int *myArray = new int[size];

    cout << endl << FILL_MSG << endl;

    fillArray(ELEMENT, COLON, myArray, size);

    res = getSum(myArray, size);
    
    cout << endl << SUM_MSG << res << endl;

    delete[] myArray;
    return 0;
}