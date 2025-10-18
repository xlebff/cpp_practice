#include <iostream>
#include <string>
#include "array.h"
#include "inputError.h"
#include "consts.h"
using namespace ErrorMsg;
using namespace RelatedMsg;
using namespace PunctuationMsg;
using namespace std;

const string ABORT = "Aborting..";
const string NO_VALUES = "No values";

int getSize(const std::string start_msg, const int minValue, const int maxValue) {
    int size = 0;

    while (!size) {
        cout << start_msg;
        if (!(cin >> size)) {
            errorClear();
        } else if ((size < minValue) || (size > maxValue)) {
            cout << ERROR_INCORRECT_RANGE_MSG << minValue << AND << maxValue << endl;
        } else break;

        size = 0;
    }

    return size;
}

void fillArray(const std::string element, int *array, const int size) {
    for (int i = 0; i < size; ++i) {
        cout << element << i + 1 << COLON;

        if (!(cin >> array[i])) {
            errorClear();
            --i;
        } else continue;
    }
}

void fillArray(const std::string element, int *array, const int size, const int minValue, const int maxValue) {
    for (int i = 0; i < size; ++i) {
        cout << element << i + 1 << COLON;

        if (!(cin >> array[i])) {
            errorClear();
        } else if (array[i] < minValue || array[i] > maxValue) {
            cout << ERROR_INCORRECT_RANGE_MSG << minValue << AND << maxValue << DOT << endl;
        } else continue;

        --i;
    }
}

void printArray(int *array, const int size, bool isReverse) {
    if (isReverse) {
        for (int i = size -1; i > 0; --i) cout << array[i] << COMMA;
        cout << array[0] << DOT << endl;
    } else {
        for (int i = 0; i < size - 1; ++i) cout << array[i] << COMMA;
        cout << array[size - 1] << DOT << endl;
    }
}

void printExceptValue(int *array, const int size, int exeptValue) {
    bool first = true;
    for (int i = 0; i < size; ++i) {
        if (array[i] != exeptValue) {
            if (!first) cout << COMMA;
            else ;
            cout << array[i];
            first = false;
        }
    }
    if (first) cout << NO_VALUES;
    else ;
}

void printArray(const std::string element, int *array, const int size, bool isReverse) {
    if (isReverse) {
        for (int i = size - 1; i >= 0; --i) cout << element << i << COLON << array[i] << endl;
    } else {
        for (int i = 0; i < size; ++i) cout << element << i << COLON << array[i] << endl;
    }
}

int getMinValue(int *array, const int size) {
    int min = *array;

    for (int i = 0; i < size; ++i) {
        min = (min < array[i] ? min : array[i]);
    }

    return min;
}

int getMaxValue(int *array, const int size) {
    int max = *array;

    for (int i = 0; i < size; ++i) {
        max = (max > array[i] ? max : array[i]);
    }

    return max;
}

int getSum(int *array, const int size) {
    int sum = 0;

    for (int i = 0; i < size; ++i) sum += array[i];
    
    return sum;
}

float getAverage(int *array, const int size) {
    return float(getSum(array, size) / size);
}

int* extend(int *array, const int size) {
    int newCapacity = size * 1.5;
    int *newArray = new int[newCapacity];

    for (int i = 0; i < size; ++i) newArray[i] = array[i];
    for (int i = size; i < newCapacity; ++i) newArray[i] = 0;

    delete[] array;
    return newArray;
}

bool contains(int *array, const int size, const int value) {
    for (int i = 0; i < size; ++i) {
        if (array[i] == value) return true;
    }
    
    return false;
}

int addValue(const string msg, int*& array, int& capacity) {
    int newValue = 0;

    while (!newValue) {
        cout << msg;
        
        if (!(cin >> newValue)) {
            errorClear();
        } else if (newValue < 0) {
            cout << ERROR_NEGOTIVE_MSG << endl;
        } else if (newValue == 0) {
            cout << ABORT << endl;
            return capacity;
        } else break;

        newValue = 0;
    }

    for (int i = 0; i < capacity; ++i) {
        if (array[i] == 0) {
            array[i] = newValue;
            return capacity;
        }
    }

    int oldCapacity = capacity;
    capacity = oldCapacity * 1.5;
    array = extend(array, oldCapacity);
    array[oldCapacity] = newValue;
    return capacity;
}

int addUniqValue(const string msg, int*& array, int& capacity) {
    int newValue = 0;

    while (!newValue) {
        cout << msg;
        
        if (!(cin >> newValue)) {
            errorClear();
        } else if (newValue == 0) {
            cout << ABORT << endl;
            return capacity;
        } else if (newValue < 0) {
            cout << ERROR_NEGOTIVE_MSG << endl;
        } else if (contains(array, capacity, newValue)) {
            cout << ERROR_NOT_UNIQUE_MSG << endl;
        } else break;

        newValue = 0;
    }

    for (int i = 0; i < capacity; ++i) {
        if (array[i] == 0) {
            array[i] = newValue;
            return capacity;
        }
    }

    int oldCapacity = capacity;
    capacity = oldCapacity * 1.5;
    array = extend(array, oldCapacity);
    array[oldCapacity] = newValue;
    return capacity;
}

void removeValue(const string msg, int *array, const int capacity) {
    int valueToRemove = 0;

    while (!valueToRemove) {
        cout << msg;
        
        if (!(cin >> valueToRemove)) {
            errorClear();
        } else if (valueToRemove == 0) {
            cout << ABORT << endl;
            return;
        } else if (valueToRemove < 0) {
            cout << ERROR_NEGOTIVE_MSG << endl;
        } else if (!contains(array, capacity, valueToRemove)) {
            cout << ERROR_NOT_FOUND_MSG << endl;
        } else break;

        valueToRemove = 0;
    }

    int index = -1;

    for (int i = 0; i < capacity; ++i) {
        if (array[i] == valueToRemove) {
            index = i;
            break;
        }
    }

    for (int i = index; i < capacity - 1; ++i) array[i] = array[i + 1];
    array[capacity - 1] = 0;
}

void clearArray(int *array, const int capacity) {
    for (int i = 0; i < capacity; ++i) array[i] = 0;
}