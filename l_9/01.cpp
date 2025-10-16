/* Напишите программу, которая с помощью функции подсчитывает количество чисел n в массиве. 
Если таковых нет – выводит «нет числа n». Размер массива известен на этапе компиляции. 
Элементы массива и число n вводятся пользователем. */

#include <iostream>
#include <string>
#include "inputError.h"
using namespace std;

const int CAPACITY = 5;

const string FILL_ARRAY_MSG = format("Fill the array of {} elements.");

const string ELEMENT = "Element ";
const string COLON = ": ";

void fillArray(int* array, const int size) {
    for (int i = 0; i < size; ++i) {
        cout << ELEMENT << i + 1 << COLON;

        if (!(cin >> array[i])) {
            errorClear();
            --i;
        } else continue;
    }
}

int main() {
    return 0;
}
