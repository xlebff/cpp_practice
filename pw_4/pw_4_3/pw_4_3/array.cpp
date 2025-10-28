#include <iostream>
#include <string>
#include "array.h"
#include "cinHandler.h"
#include "consts.h"
using namespace ErrorMsg;
using namespace RelatedMsg;
using namespace PunctuationMsg;
using namespace std;

const char ABORT[] = "Aborting..";
const char NO_VALUES[] = "No values";

template<typename T>
void fillArray(const char* element, T* array, const int size) {
    for (int i = 0; i < size; ++i) {
        do cout << element << i + 1 << COLON;
        while (!tryGetValue(array[i]));
    }
}

template<typename T>
void fillArray(const char* element, T* array, const int size, const T minValue, const T maxValue) {
    for (int i = 0; i < size; ++i) {
        do cout << element << i + 1 << COLON << SPACE;
        while (!tryGetValue(array[i], minValue, maxValue));
    }
}

template<typename T>
void printArray(T* array, const int size, bool isReverse) {
    if (isReverse) {
        for (int i = size - 1; i > 0; --i) cout << array[i] << COMMA;
        cout << array[0] << DOT << endl;
    }
    else {
        for (int i = 0; i < size - 1; ++i) cout << array[i] << COMMA;
        cout << array[size - 1] << DOT << endl;
    }
}

template<typename T>
void printExceptValue(T* array, const int size, T exeptValue) {
    bool first = true;
    for (int i = 0; i < size; ++i) {
        if (array[i] != exeptValue) {
            if (!first) cout << COMMA;
            cout << array[i];
            first = false;
        }
    }
    if (first) cout << NO_VALUES;
}

template<typename T>
void printArray(const char* element, T* array, const int size, bool isReverse) {
    if (isReverse) {
        for (int i = size - 1; i >= 0; --i) cout << element << i << COLON << array[i] << endl;
    }
    else {
        for (int i = 0; i < size; ++i) cout << element << i << COLON << array[i] << endl;
    }
}

template<typename T>
T getMinValue(T* array, const int size) {
    T min = *array;

    for (int i = 0; i < size; ++i) {
        min = (min < array[i] ? min : array[i]);
    }

    return min;
}

template<typename T>
T getMaxValue(T* array, const int size) {
    T max = *array;

    for (int i = 0; i < size; ++i) {
        max = (max > array[i] ? max : array[i]);
    }

    return max;
}

template<typename T>
T getSum(T* array, const int size) {
    T sum = 0;

    for (int i = 0; i < size; ++i) sum += array[i];

    return sum;
}

template<typename T>
float getAverage(T* array, const int size) {
    return static_cast<float>(getSum(array, size)) / size;
}

template<typename T>
T* extend(T* array, const int size) {
    int newCapacity = size * 1.5;
    T* newArray = new T[newCapacity];

    for (int i = 0; i < size; ++i) newArray[i] = array[i];
    for (int i = size; i < newCapacity; ++i) newArray[i] = 0;

    delete[] array;
    return newArray;
}

template<typename T>
bool contains(T* array, const int size, const T value) {
    for (int i = 0; i < size; ++i) {
        if (array[i] == value) return true;
    }

    return false;
}

template<typename T>
int addValue(const char* msg, T*& array, int& capacity) {
    T newValue = 0;

    while (newValue == 0) {
        cout << msg;

        if (!(cin >> newValue)) {
            errorClear();
        }
        else if (newValue < 0) {
            cout << ERROR_NEGOTIVE_MSG << endl;
        }
        else if (newValue == 0) {
            cout << ABORT << endl;
            return capacity;
        }
        else break;

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

template<typename T>
int addUniqValue(const char* msg, T*& array, int& capacity) {
    T newValue = 0;

    while (newValue == 0) {
        cout << msg;

        if (!(cin >> newValue)) {
            errorClear();
        }
        else if (newValue == 0) {
            cout << ABORT << endl;
            return capacity;
        }
        else if (newValue < 0) {
            cout << ERROR_NEGOTIVE_MSG << endl;
        }
        else if (contains(array, capacity, newValue)) {
            cout << ERROR_NOT_UNIQUE_MSG << endl;
        }
        else break;

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

template<typename T>
void removeValue(const char* msg, T* array, const int capacity) {
    T valueToRemove = 0;

    while (valueToRemove == 0) {
        cout << msg;

        if (!(cin >> valueToRemove)) {
            errorClear();
        }
        else if (valueToRemove == 0) {
            cout << ABORT << endl;
            return;
        }
        else if (valueToRemove < 0) {
            cout << ERROR_NEGOTIVE_MSG << endl;
        }
        else if (!contains(array, capacity, valueToRemove)) {
            cout << ERROR_NOT_FOUND_MSG << endl;
        }
        else break;

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

template<typename T>
void clearArray(T* array, const int capacity) {
    for (int i = 0; i < capacity; ++i) array[i] = 0;
}