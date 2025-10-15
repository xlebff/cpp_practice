/* Программа фиксирует скорость водителя каждый час в течении суток. 
Порог разрешенной скорости зависит от местонахождения водителя (вводится пользователем). 
Необходимо написать программу, выводящую:
Среднюю скорость водителя за сутки.
Максимальный непрерывный интервал (в часах), когда скорость не превышала введенный порог.
Максимальный непрерывный интервал превышения порога.
Общее количество часов движения автомобиля.
*/

#include <iostream>
#include <string>
#include "array.h"
#include "continuation.h"
using namespace std;

const int HOURS = 24;
const string REGION_MSG = "Enter the region: ";
const string FILL_MSG = "Enter the speed: ";
const string ELEMENT = "Hour ";
const string COLON = ": ";
const string AVERAGE_MSG = "Average value: ";
const string REGIONS = "Regions: ";
const string DOT = ". ";
const string ERROR_MSG = "Error: Wrong region.";
const string MAX_LEGAL_MSG = "Max continuous legal speed interval: ";
const string MAX_OVERSPEED_MSG = "Max continuous overspeed interval: ";
const string TOTAL_HOURS_MSG = "Total driving hours: ";

const int REGIONS_SPEEDS[] = {100, 60, 200};
const int REGIONS_COUNT = 3;
const string REGION_NAMES[] = {
        "Cool Region",
        "Strange Region", 
        "Fast Region"
    };
/* enum REGION { COOL_REGION_ID = 1, STRANGE_REGION_ID = 2, FAST_REGION_ID = 3 }; */

int main() {
    do {
        int maxSpeed = 0;
        int speed[HOURS];

        cout << REGIONS << endl;
        for (int i = 1; i <= REGIONS_COUNT; ++i) {
            cout << i << DOT << REGION_NAMES[i - 1] << endl;
        }

        int inp;
        do {
            cout << REGION_MSG;
            cin >> inp;
            
            if (inp >= 1 && inp <= REGIONS_COUNT) {
                maxSpeed = REGIONS_SPEEDS[inp - 1];
            } else {
                errorClear();
                cout << ERROR_MSG << endl;
                inp = 0;
            }
        } while (!inp);

        cout << FILL_MSG << endl;
        fillArray(ELEMENT, COLON, speed, HOURS, 0, 240);

        cout << endl;

        cout << AVERAGE_MSG << getAverage(speed, HOURS) << endl;

        int maxInterval = 0, currentInterval = 0;
        for (int i = 0; i < HOURS; ++i) {
            if (speed[i] && speed[i] <= maxSpeed) {
                ++currentInterval;
                maxInterval = currentInterval > maxInterval ? currentInterval : maxInterval;
            } else currentInterval = 0;
        }
        cout << MAX_LEGAL_MSG << maxInterval << endl;

        maxInterval = 0, currentInterval = 0;
        for (int i = 0; i < HOURS; ++i) {
            if (speed[i] && speed[i] > maxSpeed) {
                ++currentInterval;
                maxInterval = currentInterval > maxInterval ? currentInterval : maxInterval;
            } else currentInterval = 0;
        }
        cout << MAX_OVERSPEED_MSG << maxInterval << endl;

        int driveHours = 0;
        for (int i = 0; i < HOURS; ++i) driveHours += speed[i] != 0 ? 1 : 0;
        cout << TOTAL_HOURS_MSG << driveHours << endl;
    } while (getChoice());
    return 0;
}