/* В диетическом плане есть список продуктов с количеством калорий в каждом. 
Нужно определить, есть ли в списке продукт с очень высоким содержанием калорий. 
Если есть – то сколько таких продуктов? Вывести количество и продукты (их индексы).
*/
#include <iostream>
#include <string>
#include "consts.h"
using namespace PunctuationMsg;
using namespace std;

const int MAX_CALORIES = 300;

const string PRODUCTS[] = { "Apple", "Banana", "Nuts", "Chocolate", "Avocado", "Cheese" };
const int CALORIES[] = { 52, 96, 607, 546, 160, 402 };
const int CAPACITY = 6;

const string PRODUCTS_MSG = "Products list: ";
const string HIGHT_CALORIE_PRODUCTS_MSG = "Count of high-calorie products: ";
const string NO_HIGHT_CALORIES_PRODUCTS_MSG = "No high-calorie products.";

int* countHighCalories(const int* array, const int size, const int max_calories, int& count) {
    for (int i = 0; i < size; ++i) count += (array[i] >= max_calories);

    int* highCalArray = new int[count];

    for (int i = 0, j = 0; i < size; ++i) {
        if (array[i] > max_calories) {
            highCalArray[j] = i;
            ++j;
        } else ;
    }

    return highCalArray;
}

int main() {
    bool first = true;
    for (int i = 0; i < CAPACITY; ++i) {
        cout << (!first ? COMMA : (PRODUCTS_MSG + '\n')) 
            << PRODUCTS[i];
        first = false;
    }
    cout << endl << endl;

    int count = 0;

    int* highCalArray = countHighCalories(CALORIES, CAPACITY, MAX_CALORIES, count);
    
    if (count == 0) {
        cout << NO_HIGHT_CALORIES_PRODUCTS_MSG << endl;
    } else {
        cout << HIGHT_CALORIE_PRODUCTS_MSG << count << endl;
        
        bool first = true;
        for (int i = 0; i < count; ++i) {
            cout << (!first ? COMMA : "") 
                 << PRODUCTS[highCalArray[i]];
            first = false;
        }
        cout << endl;
    }

    delete[] highCalArray;
    return 0;
}