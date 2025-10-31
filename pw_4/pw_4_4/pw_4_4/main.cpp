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
#include "continuation.h"
#include "consts.h"

using namespace std;

const int MAX_NUMBER_OF_DAYS = 31;
const int OCTOBER_LAST_YEAR[] = {
    12, 10, 8, 7, 9, 11, 13, 14, 12, 10,
    9, 8, 7, 6, 5, 4, 3, 2, 1, 0,
    -1, -2, 1, 3, 5, 7, 9, 11, 10, 8, 6
};

const char NUMBER_OF_DAYS_MSG[] = "Specify the number of analyzed days: ";

int main() {
    do {
        cout << RelatedMsg::SEPARATOR << endl;

        int analyzingDays;
        cout << NUMBER_OF_DAYS_MSG;
        getValue<int>(analyzingDays, 1, MAX_NUMBER_OF_DAYS + 1, NUMBER_OF_DAYS_MSG, ErrorMsg::ERROR_NAN_MSG);

        int* temperatures = new int[analyzingDays];

        cout << endl << "Enter the temperature for each analyzed day:" << endl;
        fillArray<int>("Day ", temperatures, analyzingDays, -100, 100);

        cout << endl;

        float lastYearAverage = getAverage(OCTOBER_LAST_YEAR, analyzingDays);
        float thisYearAverage = getAverage(temperatures, analyzingDays);

        float difference = fabsf(round((lastYearAverage - thisYearAverage) * 1000) / 1000);

        if (lastYearAverage > thisYearAverage)
            cout << "October of last year is warmer." << endl <<
            "The difference is " << difference << " degree." << endl;
        else if (thisYearAverage > lastYearAverage)
            cout << "October is warmer this year." << endl <<
            "The difference is " << difference << " degree." << endl;
        else
            cout << "The temperature is the same." << endl;

        if (difference >= 5) cout << "Warning! High temperature difference." << endl;
        else;

        cout << endl;

        int lastYearMax = getMaxValue(OCTOBER_LAST_YEAR, analyzingDays);
        int thisYearMax = getMaxValue(temperatures, analyzingDays);

        int lastYearMin = getMinValue(OCTOBER_LAST_YEAR, analyzingDays);
        int thisYearMin = getMinValue(temperatures, analyzingDays);

        if (lastYearMax > thisYearMax)
            cout << "The maximum temperature of last year is higher than the current one." << endl;
        else if (thisYearMax > lastYearMax)
            cout << "The maximum temperature of this year is higher than the last one." << endl;
        else
            cout << "The maximum temperatures are the same." << endl;

        if (lastYearMin < thisYearMin)
            cout << "The minimum temperature of last year is lower than the current one." << endl;
        else if (thisYearMin < lastYearMin)
            cout << "The minimum temperature of this year is lower than the last one." << endl;
        else
            cout << "The minimum temperatures are the same." << endl;

        int lastYearBelow0 = 0;
        int thisYearBelow0 = 0;
        for (int i = 0; i < analyzingDays; ++i) {
            if (OCTOBER_LAST_YEAR[i] < 0) ++lastYearBelow0;
            else;

            if (temperatures[i] < 0) ++thisYearBelow0;
            else;
        }

        cout << endl;

        cout << "The number of days when the temperature was below 0 last October: "
            << lastYearBelow0 << endl;

        cout << "The number of days when the temperature was below 0 this October: "
            << thisYearBelow0 << endl;

        cout << endl << RelatedMsg::SEPARATOR << endl;

        delete[] temperatures;

    } while (getChoice());

	return 0;
}