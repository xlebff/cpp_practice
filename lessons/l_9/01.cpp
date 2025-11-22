/* Напишите программу, которая с помощью функции подсчитывает количество чисел n в массиве. 
Если таковых нет – выводит «нет числа n». Размер массива известен на этапе компиляции. 
Элементы массива и число n вводятся пользователем. */

#include <iostream>
#include <string>
#include "inputError.h"
using namespace std;

const int CAPACITY = 5;

const string FILL_ARRAY_MSG = "Fill the array of ";
const string ELEMENTS = " elements";

const string TARGET_INP_MSG = "Enter the number to count: ";
const string NUMBERS = " numbers \"";
const string FOUND_MSG = "\" found.";
const string NO_TARGET_MSG = "No target number found.";

const string ELEMENT = "Element ";
const string COLON = ": ";

int findNumber(int* array, const int size, const int target) {
    int res = 0;

    for (int i = 0; i < size; ++i) {
        if (array[i] == target) ++res;
        else continue;
    }

    return res;
}

bool getNumber(int* var) {
    if (!(cin >> *var)) {
        errorClear();
        return false;
    } else return true;
}

int main() {
    int nums[CAPACITY];

    cout << FILL_ARRAY_MSG << CAPACITY << ELEMENTS << endl;

    for (int i = 0; i < CAPACITY; ++i) {
        cout << ELEMENT << i + 1 << COLON;

        if (getNumber(&nums[i])) continue;
        else --i;
    }

    cout << endl;

    int target = 0;

    do {
        cout << TARGET_INP_MSG;

        if (getNumber(&target)) break;
        else continue;

    } while (!target);

    int count = findNumber(nums, CAPACITY, target);

    if (count) cout << count << NUMBERS << target << FOUND_MSG << endl;
    else cout << NO_TARGET_MSG << endl;

    return 0;
}
