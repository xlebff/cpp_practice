/* При посещении сайта каждый клиент указывает свой возраст. 
Количество клиентов ежедневно разное. 
Напишите функцию для таргетированной рекламы – 
функция должна возвращать только те возраста, которые подходят под указанный диапазон. */

#include <iostream>
#include <string>
#include "inputError.h"
#include "consts.h"
using namespace ErrorMsg;
using namespace RelatedMsg;
using namespace PunctuationMsg;
using namespace std;

const string CLIENTS_COUNT_MSG = "Enter the number of clients: ";
const string AGE_INPUT_MSG = "Enter ages of clients: ";
const string AGE_RANGE_MSG = "Enter target age range (min and max): ";
const string TARGET_AGES_MSG = "Target ages: ";
const string NO_TARGET_AGES_MSG = "No clients in target age range.";
const string TOTAL_CLIENTS_MSG = "Total clients: ";
const string TARGET_COUNT_MSG = "Clients in target range: ";

const string ELEMENT = "Client ";
const string MIN = "Minimum age: ";
const string MAX = "Maximum age: ";

int getNum(const std::string start_msg, const int minValue, const int maxValue) {
    int inpNum = 0;

    while (!inpNum) {
        cout << start_msg;
        if (!(cin >> inpNum)) {
            errorClear();
        } else if ((inpNum < minValue) || (inpNum > maxValue)) {
            cout << ERROR_INCORRECT_RANGE_MSG << minValue << AND << maxValue << DOT << endl;
        } else break;

        inpNum = 0;
    }

    return inpNum;
}

void fillArray(const string element, const string colon, int *array, const int size) {
    for (int i = 0; i < size; ++i) {
        cout << element << i + 1 << colon;

        if (!(cin >> array[i])) {
            errorClear();
            --i;
        } else continue;
    }
}

int* filterAgesByRange(const int* ages, const int size, const int minAge, const int maxAge, int& resultSize) {
    resultSize = 0;
    for (int i = 0; i < size; ++i) {
        if (ages[i] >= minAge && ages[i] <= maxAge) ++resultSize;
        else continue;
    }
    
    int* targetAges = new int[resultSize];
    
    for (int i = 0, j = 0; i < size; ++i) {
        if (ages[i] >= minAge && ages[i] <= maxAge) {
            targetAges[j] = ages[i];
            ++j;
        } else continue;
    }
    
    return targetAges;
}

void printArray(const string& message, const int* array, int size) {
    cout << message;
    if (size == 0) {
        cout << NO_TARGET_AGES_MSG << endl;
        return;
    }
    
    bool first = true;
    for (int i = 0; i < size; ++i) {
        cout << (!first ? COMMA : "") << array[i];
        first = false;
    }
    cout << endl;
}

int main() {
    int clientsCount = getNum(CLIENTS_COUNT_MSG, 1, 1000);
    
    int* ages = new int[clientsCount];
    cout << AGE_INPUT_MSG << endl;
    fillArray(ELEMENT, COLON, ages, clientsCount);
    
    cout << endl;
    
    cout << AGE_RANGE_MSG << endl;
    int minAge = getNum(MIN, 0, 150);
    int maxAge = getNum(MAX, minAge, 150);

    cout << endl;
    
    int targetCount = 0;
    int* targetAges = filterAgesByRange(ages, clientsCount, minAge, maxAge, targetCount);
    
    cout << TOTAL_CLIENTS_MSG << clientsCount << endl;
    cout << TARGET_COUNT_MSG << targetCount << endl;
    printArray(TARGET_AGES_MSG, targetAges, targetCount);

    delete[] ages;
    delete[] targetAges;

    return 0;
}