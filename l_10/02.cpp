/* Напишите рекурсивную функцию для вывода всех элементов массива. */
#include <iostream>
using namespace std;

const int CAPACITY = 5;
const int ARRAY[CAPACITY] = { 1, 2, 3, 4, 5 };

void printArray(const int* array, const int size, int i = 0) {
    if (i >= size) return;
    cout << array[i] << endl;
    printArray(array, size, i + 1);
}

int main() {
    printArray(ARRAY, CAPACITY);
    return 0;
}