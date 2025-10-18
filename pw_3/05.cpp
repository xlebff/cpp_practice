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
using namespace std;

const int DAYS = 22;
const int MAX_SALES = 100000;
const int MIN_SALES = 10000;
const string SALES_INPUT_MSG = "Enter salses per day: ";
const string ELEMENT = "Day ";
const string COLON = ": ";
const string AVERAGE_MSG = "Average number of sales: ";
const string MAX_SALES_DAYS_MSG = "Days with maximum sales: ";
const string MIN_SALES_DAYS_MSG = "Days with minimum sales: ";
const string TOTAL = "Total: ";
const string COMMA = ", ";

int main() {
    int sales[DAYS];
    bool first;

    cout << SALES_INPUT_MSG << endl;
    fillArray(ELEMENT, COLON, sales, DAYS, 0, 2000000);

    cout << AVERAGE_MSG << getAverage(sales, DAYS) << endl;

    first = true;
    cout << MAX_SALES_DAYS_MSG;
    for (int i = 0; i < DAYS; ++i) {
        if (sales[i] >= MAX_SALES) {
            cout << (!first ? COMMA : "") << i + 1;
            first = false;
        } else continue;
    }

    return 0;
}