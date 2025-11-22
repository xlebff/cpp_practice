#include "array.h"
#include <iostream>
#include <string>

using namespace std;

const int MAX_IGNORE_COUNT = 1000;
const char STOP_IGNORE_CHAR = '\n';

const string ERROR_CHAR_MSG = "Error: Not a number!";
const string ERROR_NUM_MSG = "Error: The value must be between ";
const string AND = " and ";

int getSize(const string start_msg, const int minValue, const int maxValue) {
    int size = 0;

    while (!size) {
        cout << start_msg;
        if (!(cin >> size)) {
            cin.clear();
            cin.ignore(MAX_IGNORE_COUNT, STOP_IGNORE_CHAR);
            cout << ERROR_CHAR_MSG << endl;
        } else if ((size < minValue) || (size > maxValue)) {
            cout << ERROR_NUM_MSG << minValue << AND << maxValue << endl;
        } else break;

        size = 0;
    }

    return size;
}

void fillArray(const string element, const string colon, int *array, const int size) {
    for (int i = 0; i < size; ++i) {
        cout << element << i + 1 << colon;

        if (!(cin >> array[i])) {
            cin.clear();
            cin.ignore(MAX_IGNORE_COUNT, STOP_IGNORE_CHAR);
            cout << ERROR_CHAR_MSG << endl;
            --i;
        } else continue;
    }
}

void fillArray(const string element, const string colon, int *array, const int size, const int minValue, const int maxValue) {
    for (int i = 0; i < size; ++i) {
        cout << element << i + 1 << colon;

        if (!(cin >> array[i])) {
            cin.clear();
            cin.ignore(MAX_IGNORE_COUNT, STOP_IGNORE_CHAR);
            cout << ERROR_CHAR_MSG << endl;
        } else if (array[i] < minValue || array[i] > maxValue) {
            cout << ERROR_NUM_MSG << minValue << AND << maxValue << endl;
        } else continue;

        --i;
    }
}

void printArray(const string element, const string colon, int *array, const int size, bool isReverse) {
    if (isReverse) {
        for (int i = size - 1; i >= 0; --i) cout << element << i << colon << array[i] << endl;
    } else {
        for (int i = 0; i < size; ++i) cout << element << i << colon << array[i] << endl;
    }
}

int getMaxValue(int *array, int size) {
    int max = 0;

    for (int i = 0; i < size; ++i) {
        max = (max > array[i] ? max : array[i]);
    }

    return max;
}

float getAverage(int *array, int size) {
    return float(getSum(array, size) / size);
}

int getSum(int *array, int size) {
    int sum = 0;

    for (int i = 0; i < size; ++i) sum += array[i];
    
    return sum;
}