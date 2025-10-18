/* Разработать программу для анализа продаж. Считаем, что в каждом месяце 22 рабочих дня. 
Программа должна выводить аналитику продаж за текущий месяц:
Средняя сумма продаж.
Количество и номера дней с максимальными продажами (в диапазоне больше 100 000).
Количество и номера дней с минимальными продажами (в диапазоне меньше 10 000)
Количество периодов уменьшения продаж больше 3х дней подряд 
(когда продажи за каждый следующий день меньше предыдущего), вывести с количеством дней в периоде.
Программа должна составить план продаж на основе сравнения 
текущего месяца с аналогичным месяцем прошлого года («год к году») – данных о продажах 
за каждый день двух месяцев (например, март 2025 года и март 2024 года). 
Программа должна определить планируемые продажи на следующий месяц по следующему правилу:
Если продажи текущего месяца больше или равны продажам в аналогичный месяц прошлого года, 
планируемый объём увеличивается на 10% от продаж текущего месяца (округлить до целого).
Если продажи ниже, планируемый объём равен среднему арифметическому двух значений (за текущий и прошлый год), округленному до целого.
*/

#include <iostream>
#include <string>
#include "continuation.h"
#include "array.h"
#include "consts.h"
using namespace PunctuationMsg;
using namespace std;

const int DAYS = 22;
const int MAX_SALES = 100000;
const int MIN_SALES = 10000;

const string SALES_INPUT_MSG = "Enter sales per day: ";
const string AVERAGE_MSG = "Average number of sales: ";
const string MAX_SALES_DAYS_MSG = "Days with maximum sales: ";
const string NO_MAX_SALES_DAYS_MSG = "no days with maximum sales.";
const string MIN_SALES_DAYS_MSG = "Days with minimum sales: ";
const string NO_MIN_SALES_DAYS_MSG = "no days with minimum sales.";
const string DECREASING_PERIODS_MSG = "Decreasing period ";
const string DAYS_MSG = " days.";
const string NO_DECREASING_MSG = "No decreasing periods found.";
const string PREDICTION_MSG = "Planned volume by next year: ";

const string ELEMENT = "Day ";
const string TOTAL = "Total: ";

int main() {
    int prevSales[DAYS] = {
        120000, 115000, 125000, 118000, 130000,
        95000,  88000,  92000,  85000,  78000,
        72000,  68000,  75000,  82000,  95000,
        105000, 112000, 108000, 115000, 122000,
        5000,   8000
    };

    int lastSales[DAYS];
    bool first;
    int maxSalesCount = 0, minSalesCount = 0;
    int decreasingPeriods = 0, currentDays = 1;
    int prediction = 0;

    cout << SALES_INPUT_MSG << endl;
    fillArray(ELEMENT, lastSales, DAYS, 0, 2000000);

    cout << endl;

    cout << AVERAGE_MSG << getAverage(lastSales, DAYS) << endl;

    cout << endl;

    first = true;
    cout << MAX_SALES_DAYS_MSG;
    for (int i = 0; i < DAYS; ++i) {
        if (lastSales[i] >= MAX_SALES) {
            if (!first) cout << COMMA;
            else ;
            cout << i + 1;
            first = false;
            ++maxSalesCount;
        }
    }
    if (maxSalesCount) cout << DOT << endl << TOTAL << maxSalesCount << endl;
    else cout << NO_MAX_SALES_DAYS_MSG << endl;

    cout << endl;

    first = true;
    cout << MIN_SALES_DAYS_MSG;
    for (int i = 0; i < DAYS; ++i) {
        if (lastSales[i] <= MIN_SALES) {
            if (!first) cout << COMMA;
            else ;
            cout << i + 1;
            first = false;
            ++minSalesCount;
        }
    }
    if (minSalesCount) cout << DOT << endl << TOTAL << minSalesCount << endl;
    else cout << NO_MIN_SALES_DAYS_MSG << endl;

    cout << endl;

    for (int i = 0; i < DAYS - 1; ++i) {
        if (lastSales[i] > lastSales[i + 1]) {
            ++currentDays;
        } else {
            if (currentDays >= 3) {
                ++decreasingPeriods;
                cout << DECREASING_PERIODS_MSG << decreasingPeriods << COLON 
                     << currentDays << DAYS_MSG << endl;
            } else ;
            currentDays = 1;
        }
    }

    if (currentDays >= 3) {
        ++decreasingPeriods;
        cout << DECREASING_PERIODS_MSG << decreasingPeriods << COLON 
                << currentDays << DAYS_MSG << endl;
    } else ;
    
    if (decreasingPeriods == 0) {
        cout << NO_DECREASING_MSG << endl;
    } else cout << TOTAL << decreasingPeriods << endl;

    cout << endl;

    int prevSum = getSum(prevSales, DAYS);
    int lastSum = getSum(lastSales, DAYS);

    if (prevSum <= lastSum) prediction = lastSum * 1.1;
    else prediction = (lastSum + prevSum) / 2;

    cout << PREDICTION_MSG << prediction << DOT << endl;

    return 0;
}