/* Написать программу для анализа температуры в городе за октябрь. 
В программе используются данные за 2 месяца – октябрь прошлого года (данные известны) и 
октябрь текущего года (данные и количество анализируемых дней вводятся пользователем, 
но не должны превышать количество дней месяца). Программа должна:
Определить, какой из месяцев был теплее по средней температуре, и вывести соответствующее сообщение.
Проверить, есть ли разница в средних температурах более 5°C. Если есть – вывести предупреждение о высоком перепаде температур.
Сравнить максимальную и минимальную температуры за разные года и вывести соответствующее сообщение.
Подсчитать и вывести количество дней, когда температура была ниже 0, для каждого месяца.
Программа должна быть зациклена до тех пор, пока пользователь не решит выйти. 
Разделите программу на 3 файла: main.cpp; .h, где будут объявления функций; .cpp, где будут определения функций. */

#include <iostream>
#include "cinHandler.h"
#include "array.h"
#include "consts.h"

using namespace std;

const int MAX_NUMBER_OF_DAYS = 31;
const float OCTOBER_LAST_YEAR[] = {
    12, 10, 8, 7, 9, 11, 13, 14, 12, 10,
    9, 8, 7, 6, 5, 4, 3, 2, 1, 0,
    -1, -2, 1, 3, 5, 7, 9, 11, 10, 8, 6
};

const char NUMBER_OF_DAYS_MSG[] = "Specify the number of analyzed days: ";

int main() {
    int analyzingDays;
    cout << NUMBER_OF_DAYS_MSG;
    getValue(analyzingDays, 1, MAX_NUMBER_OF_DAYS + 1, NUMBER_OF_DAYS_MSG, ErrorMsg::ERROR_NAN_MSG);

    int* temperatures = new int[analyzingDays];

    cout << endl << "Enter the temperature for each analyzed day:" << endl;
    fillArray("Day ", temperatures, analyzingDays, -100, 100);

    float lastYearAverage = getAverage(OCTOBER_LAST_YEAR, analyzingDays);
    float thisYearAverage = getAverage(temperatures, analyzingDays);

    if (lastYearAverage > thisYearAverage) {
        cout << "October of last year is warmer." << endl <<
            "The difference is " << (lastYearAverage - thisYearAverage) << "⁰C." << endl;
    }
    else if (thisYearAverage > lastYearAverage) {
        cout << "October is warmer this year." << endl <<
            "The difference is " << (thisYearAverage - lastYearAverage) << "⁰C." << endl;
    }
    else cout << "The temperature is the same." << endl;



    delete[] temperatures;
	return 0;
}