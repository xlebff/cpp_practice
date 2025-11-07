/* В офисном здании собирают температуру по разным датчикам. За прошлый день собрано 8 значений
(18.3, 18, 17.9, 18.5, 18.8, 19, 19.5, 19.8, 20). За текущий день данные собираются в режиме реального
времени. Для анализа данных нужно найти разницу минимальных, максимальных и средних значений
за день. Составьте функции для поиска этих значений. */

#include <iostream>
#include "array.h"

using namespace std;

float getDifference(float value0, float value1) {
	return fabsf(value0 - value1);
}

int main() {
	const float LAST_DAY[] = { 18.3f, 18.0f, 17.9f, 18.5f, 18.8f, 19.0f, 19.5f, 19.8f, 20.0f };
	const int SIZE = 9;

	const char LAST_DAY_MSG[] = "Temperatures of last day:";
	const char THIS_DAY_DATA_MSG[] = "Enter the current day's temperature:";
	const char MEASUREMENT[] = "Measurement ";
	const char MAX_DIFFERENCE_MSG[] = "Maximum temperatures difference is ";
	const char MAX_SAME_MSG[] = "Maximum temperatures are the same.";
	const char MIN_DIFFERENCE_MSG[] = "Minimum temperatures difference is ";
	const char MIN_SAME_MSG[] = "Minimum temperatures are the same.";
	const char AVERAGE_DIFFERENCE_MSG[] = "Average temperatures difference is ";
	const char AVERAGE_SAME_MSG[] = "Average temperatures are the same.";

	cout << LAST_DAY_MSG << endl;
	printArray(MEASUREMENT, LAST_DAY, SIZE);

	cout << endl;

	float thisDay[SIZE];
	cout << THIS_DAY_DATA_MSG << endl;
	fillArray(MEASUREMENT, thisDay, SIZE, (float)-20, (float)40);

	cout << endl;

	float maxDifference = getDifference(getMaxValue(LAST_DAY, SIZE), getMaxValue(thisDay, SIZE));
	float minDifference = getDifference(getMinValue(LAST_DAY, SIZE), getMinValue(thisDay, SIZE));
	float averageDifference = getDifference(getAverage(LAST_DAY, SIZE), getAverage(thisDay, SIZE));

	cout << (maxDifference ? MAX_DIFFERENCE_MSG + to_string(maxDifference) : MAX_SAME_MSG) << endl;
	cout << (minDifference ? MIN_DIFFERENCE_MSG + to_string(minDifference) : MIN_SAME_MSG) << endl;
	cout << (averageDifference ? AVERAGE_DIFFERENCE_MSG + to_string(averageDifference) : AVERAGE_SAME_MSG) << endl;

	return 0;
}