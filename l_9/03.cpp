/* В логистике есть список маршрутов с временем их прохождения. 
Необходимо найти маршрут с минимальным временем, а также проверить, 
есть ли маршруты, которые проходят быстрее заданного времени.*/

#include <iostream>
#include <string>
#include "inputError.h"
#include "consts.h"
using namespace ErrorMsg;
using namespace RelatedMsg;
using namespace PunctuationMsg;
using namespace std;

const int ROUTES_TIME[] = { 60, 40, 45, 100 };
const int CAPACITY = 4;

const string ALL_ROUTES_MSG = "All routes: ";
const string ROUTE = "Route #";

const string FASTEST_ROUTE_MSG = "The fastest route: ";
const string FASTER_ROUTE_MSG = "Routes that faster than the set time: ";
const string NO_FASTER_ROUTE_MSG = "No route faster than the set time.";

const string SET_TIME_MSG = "Enter the target time: ";

int fastestRoute(const int* routes, const int size) {
    int minValueIndex = 0;

    for (int i = 1; i < size; ++i) minValueIndex = routes[i] < routes[minValueIndex] ? i : minValueIndex;

    return minValueIndex;
}

int getNumber(const string msg, const int minValue, const int maxValue) {
    int inpNum = 0;

    while (!inpNum) {
        cout << msg;
        if (!(cin >> inpNum)) {
            errorClear();
            inpNum = 0;
        } else if ((inpNum < minValue) || (inpNum > maxValue)) {
            cout << ERROR_INCORRECT_RANGE_MSG << minValue << AND << maxValue << DOT << endl;
            inpNum = 0;
        } else break;
    }

    return inpNum;
}

int main() {
    cout << ALL_ROUTES_MSG << endl;
    for (int i = 0; i < CAPACITY; ++i) cout << ROUTE << i + 1 << STICK << ROUTES_TIME[i] << endl;
    cout << endl;

    int fastestIndex = fastestRoute(ROUTES_TIME, CAPACITY);
    cout << FASTEST_ROUTE_MSG << ROUTE << fastestIndex + 1;

    cout << endl << endl;

    int setTime = getNumber(SET_TIME_MSG, 1, 1000);

    bool found = false, first = true;
    cout << FASTER_ROUTE_MSG;
    for (int i = 0; i < CAPACITY; ++i) {
        if (ROUTES_TIME[i] <= setTime) {
            cout << ((!first) ? COMMA : "") << i + 1;
            found = true;
            first = false;
        } else continue;
    }
    if (!found) cout << NO_FASTER_ROUTE_MSG;

    return 0;
}