#include <iostream>
#include <string>
#include "array.h"
#include "inputError.h"
using namespace std;

const string ERROR_NUM_MSG = "Error: The value must be between ";
const string AND = " and ";
const string ERROR_VAL_MSG = "Error: The value must be greater than 0.";
const string ERROR_NOT_UNIQ_MSG = "Error: The value is already exist.";
const string ERROR_NOT_FOUND_MSG = "Error: The value is not found.";
const string ABORT = "Aborting..";
const string TERMINATOR = ", ";

int getSize(const std::string start_msg, const int minValue, const int maxValue) {
    int size = 0;

    while (!size) {
        cout << start_msg;
        if (!(cin >> size)) {
            errorClear();
        } else if ((size < minValue) || (size > maxValue)) {
            cout << ERROR_NUM_MSG << minValue << AND << maxValue << endl;
        } else break;

        size = 0;
    }

    return size;
}

void fillArray(const std::string element, const std::string colon, int *array, const int size) {
    for (int i = 0; i < size; ++i) {
        cout << element << i + 1 << colon;

        if (!(cin >> array[i])) {
            errorClear();
            --i;
        } else continue;
    }
}

void fillArray(const std::string element, const std::string colon, int *array, const int size, const int minValue, const int maxValue) {
    for (int i = 0; i < size; ++i) {
        cout << element << i + 1 << colon;

        if (!(cin >> array[i])) {
            errorClear();
        } else if (array[i] < minValue || array[i] > maxValue) {
            cout << ERROR_NUM_MSG << minValue << AND << maxValue << endl;
        } else continue;

        --i;
    }
}

void printArray(int *array, const int size, bool isReverse) {
    if (isReverse) {
        for (int i = size -1; i > 0; --i) cout << array[i] << TERMINATOR;
        cout << array[0] << endl;
    } else {
        for (int i = 0; i < size - 1; ++i) cout << array[i] << TERMINATOR;
        cout << array[size - 1] << endl;
    }
}

void printExeptValue(int *array, const int size, int exeptValue) {
    bool first = true;
    for (int i = 0; i < size; ++i) {
        if (array[i] != exeptValue) {
            if (!first) {
                cout << TERMINATOR;
            }
            cout << array[i];
            first = false;
        }
    }
    if (first) {
        cout << "No tasks";
    }
}

void printArray(const std::string element, const std::string colon, int *array, const int size, bool isReverse) {
    if (isReverse) {
        for (int i = size - 1; i >= 0; --i) cout << element << i << colon << array[i] << endl;
    } else {
        for (int i = 0; i < size; ++i) cout << element << i << colon << array[i] << endl;
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
            cout << ERROR_VAL_MSG << endl;
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
            cout << ERROR_VAL_MSG << endl;
        } else if (contains(array, capacity, newValue)) {
            cout << ERROR_NOT_UNIQ_MSG << endl;
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
            cout << ERROR_VAL_MSG << endl;
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