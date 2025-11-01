#include <iostream>
#include "cinHandler.h"
#include "array.h"
#include "continuation.h"
#include "consts.h"

using namespace std;

int main() {
    const int MAX_NUMBER_OF_DAYS = 31;
    const int OCTOBER_LAST_YEAR[] = {
        12, 10, 8, 7, 9, 11, 13, 14, 12, 10,
        9, 8, 7, 6, 5, 4, 3, 2, 1, 0,
        -1, -2, 1, 3, 5, 7, 9, 11, 10, 8, 6
    };

    const char NUMBER_OF_DAYS_MSG[] = "Specify the number of analyzed days: ";
    const char TEMPERATURES_MSG[] = "Enter the temperature for each analyzed day:";
    const char DAY_PREFIX[] = "Day ";
    const char LAST_YEAR_WARMER_MSG[] = "October of last year is warmer.";
    const char THIS_YEAR_WARMER_MSG[] = "October is warmer this year.";
    const char TEMPERATURE_SAME_MSG[] = "The temperature is the same.";
    const char DIFFERENCE_MSG[] = "The difference is ";
    const char DEGREE_MSG[] = " degree.";
    const char WARNING_MSG[] = "Warning! High temperature difference.";
    const char LAST_YEAR_MAX_HIGHER_MSG[] = "The maximum temperature of last year is higher than the current one.";
    const char THIS_YEAR_MAX_HIGHER_MSG[] = "The maximum temperature of this year is higher than the last one.";
    const char MAX_TEMP_SAME_MSG[] = "The maximum temperatures are the same.";
    const char LAST_YEAR_MIN_LOWER_MSG[] = "The minimum temperature of last year is lower than the current one.";
    const char THIS_YEAR_MIN_LOWER_MSG[] = "The minimum temperature of this year is lower than the last one.";
    const char MIN_TEMP_SAME_MSG[] = "The minimum temperatures are the same.";
    const char LAST_YEAR_BELOW_0_MSG[] = "The number of days when the temperature was below 0 last October: ";
    const char THIS_YEAR_BELOW_0_MSG[] = "The number of days when the temperature was below 0 this October: ";

    do {
        cout << RelatedMsg::SEPARATOR << endl;

        int analyzingDays;
        cout << NUMBER_OF_DAYS_MSG;
        getValue<int>(analyzingDays, 1, MAX_NUMBER_OF_DAYS + 1, NUMBER_OF_DAYS_MSG, ErrorMsg::ERROR_NAN_MSG);

        int* temperatures = new int[analyzingDays];

        cout << endl << TEMPERATURES_MSG << endl;
        fillArray<int>(DAY_PREFIX, temperatures, analyzingDays, -100, 100);

        cout << endl;

        float lastYearAverage = getAverage(OCTOBER_LAST_YEAR, analyzingDays);
        float thisYearAverage = getAverage(temperatures, analyzingDays);

        float difference = fabsf(round((lastYearAverage - thisYearAverage) * 1000) / 1000);

        if (lastYearAverage > thisYearAverage)
            cout << LAST_YEAR_WARMER_MSG << endl <<
            DIFFERENCE_MSG << difference << DEGREE_MSG << endl;
        else if (thisYearAverage > lastYearAverage)
            cout << THIS_YEAR_WARMER_MSG << endl <<
            DIFFERENCE_MSG << difference << DEGREE_MSG << endl;
        else
            cout << TEMPERATURE_SAME_MSG << endl;

        if (difference >= 5) cout << WARNING_MSG << endl;
        else;

        cout << endl;

        int lastYearMax = getMaxValue(OCTOBER_LAST_YEAR, analyzingDays);
        int thisYearMax = getMaxValue(temperatures, analyzingDays);

        int lastYearMin = getMinValue(OCTOBER_LAST_YEAR, analyzingDays);
        int thisYearMin = getMinValue(temperatures, analyzingDays);

        if (lastYearMax > thisYearMax)
            cout << LAST_YEAR_MAX_HIGHER_MSG << endl;
        else if (thisYearMax > lastYearMax)
            cout << THIS_YEAR_MAX_HIGHER_MSG << endl;
        else
            cout << MAX_TEMP_SAME_MSG << endl;

        if (lastYearMin < thisYearMin)
            cout << LAST_YEAR_MIN_LOWER_MSG << endl;
        else if (thisYearMin < lastYearMin)
            cout << THIS_YEAR_MIN_LOWER_MSG << endl;
        else
            cout << MIN_TEMP_SAME_MSG << endl;

        int lastYearBelow0 = 0;
        int thisYearBelow0 = 0;
        for (int i = 0; i < analyzingDays; ++i) {
            if (OCTOBER_LAST_YEAR[i] < 0) ++lastYearBelow0;
            else;

            if (temperatures[i] < 0) ++thisYearBelow0;
            else;
        }

        cout << endl;

        cout << LAST_YEAR_BELOW_0_MSG
            << lastYearBelow0 << endl;

        cout << THIS_YEAR_BELOW_0_MSG
            << thisYearBelow0 << endl;

        cout << endl << RelatedMsg::SEPARATOR << endl;

        delete[] temperatures;

    } while (getChoice());

    return 0;
}