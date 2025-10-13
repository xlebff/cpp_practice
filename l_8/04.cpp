#include <iostream>
#include "array.h"
using namespace std;

const string START_MSG = "Enter the number of students: ";
const string ELEMENT = "Student`s attendance ";
const string COLON = ": ";
const string ATTENDANCE = "Students with maximum attendance: ";
const string BELOW_ATTENDANCE = "Students with below-average attendance: ";

int main() {
    int count = 0;

    int size = getSize(START_MSG, 1, 50);

    int *attendance = new int[size];

    fillArray(ELEMENT, COLON, attendance, size);

    int max = getMaxValue(attendance, size);
    for (int i = 0; i < size; ++i) {
        if (attendance[i] == max) ++count;
    }
    cout << endl << ATTENDANCE << count;

    count = 0;

    float average = getAverage(attendance, size);
    for (int i = 0; i < size; ++i) {
        if (attendance[i] < average) ++count;
        else ;
    }
    cout << endl << BELOW_ATTENDANCE << count;

    delete[] attendance;
    return 0;
}