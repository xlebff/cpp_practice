/* Разработать программу для анализа статистики посещения сайта.
Временной период (количество дней) определяется пользователем. 
Количество посетителей за каждый день определяется пользователем. 

Программа должна подсчитать и вывести:
Общее количество посещений за весь период.
Среднее количество посещений в день.
Максимальное и минимальное число посещений за весь период (с указанием дня).
Общий % низкой посещаемости сайта (низкая – посещаемость ниже среднего).
*/

#include <iostream>
#include <string>
#include "array.h"
#include "continuation.h"
#include "consts.h"
using namespace PunctuationMsg;
using namespace std;

const string START_MSG = "Specify the time period (number of days): ";
const string FILL_MSG = "Enter the number of visits: ";
const string NO_DAYS_MSG = "The number of visits is the same.";
const string SUM_MSG = "Total number of visits: ";
const string MAX_MSG = "Maximum number of visits: ";
const string MIN_MSG = "Minimum number of visits: ";
const string AVERAGE_MSG = "Average number of visits: ";
const string IN_DAY_MSG = "In days: ";
const string BELOW_AVERAGE_MSG = "Number of days with below-average attendance: ";

const string ELEMENT = "Day ";

int main() {
    do {
        int size = getSize(START_MSG, 1, 100);
        int *visitors = new int[size];
        cout << FILL_MSG << endl;
        fillArray(ELEMENT, visitors, size, 0, 1000);

        cout << endl;

        int allVisits = getSum(visitors, size);
        cout << SUM_MSG << allVisits << endl;

        float averageVisits = getAverage(visitors, size);
        cout << AVERAGE_MSG << averageVisits << endl;

        int maxVisits = getMaxValue(visitors, size);
        int minVisits = getMinValue(visitors, size);

        if (maxVisits != minVisits) {
            cout << endl << MAX_MSG << maxVisits << endl;
            cout << IN_DAY_MSG;
            bool first = true;
            for (int i = 0; i < size; ++i) {
                if (visitors[i] == maxVisits) {
                    if (!first) cout << DOT;
                    else ;
                    cout << i + 1;
                    first = false;
                } else continue;
            }

            cout << endl << endl << MIN_MSG << minVisits << endl << IN_DAY_MSG;
            first = true;
            for (int i = 0; i < size; ++i) {
                if (visitors[i] == minVisits) {
                    if (!first) cout << DOT;
                    else ;
                    cout << i + 1;
                    first = false;
                } else continue;
            }

            int belowAverage = 0;
            for (int i = 0; i < size; ++i) {
                if (visitors[i] < averageVisits) ++belowAverage;
                else continue;
            }
            cout << endl << endl << BELOW_AVERAGE_MSG << belowAverage << endl << endl;
        } else cout << NO_DAYS_MSG << endl;

        delete[] visitors;
    } while (getChoice());

    return 0;
}