/* Написать программу для отслеживания питания. План питания включает в себя 5 блюд определенной калорийности (калорийность каждого вводится пользователем). Фактическое питание вводит пользователь – и количество блюд, и их калорийность. Программа должна:
Определить, попал ли пользователь в план потребления калорий. Если нет – вывести соответствующее сообщение с необходимой разницей калорий.
Если фактическое потребление в 2 раза меньше или больше планируемого – вывести соответствующее предупреждение.
Если фактическое количество приемов пищи (количество блюд) не превышает 2, независимо от их калорийности – вывести соответствующее предупреждение.
Программа должна быть зациклена до тех пор, пока пользователь не решит выйти. Разделите программу на 3 файла: main.cpp; .h, где будут объявления функций; .cpp, где будут определения функций.
*/

#include <iostream>
#include <format>
#include <string>
#include "cinHandler.h"
#include "consts.h"
#include "caloriesControl.h"
#include "continuation.h"

using namespace std;

int main() {
	const char EATING_COUNT_MSG[] = "Enter the number of meals: ";
	const char CALORIES_MSG[] = "Specify the calorie content of each meal: ";

	do {
		int realEatingCount;
		cout << EATING_COUNT_MSG;
		getValue(realEatingCount, 0, 50, EATING_COUNT_MSG, ErrorMsg::ERROR_NAN_MSG);

		float* calories = new float[realEatingCount];
		float totalCalories = 0;

		cout << CALORIES_MSG << endl;
		for (int i = 0; i < realEatingCount; ++i) {
			string element = format("Meal {}: ", i + 1);
			cout << element;
			getValue(calories[i], 1.0f, 10000.0f, element.c_str(), ErrorMsg::ERROR_NAN_MSG);
			totalCalories += calories[i];
		}

		isEatingCountNormal(realEatingCount);

		if (!isCaloriesNormal(totalCalories)) cout << format("\nThe difference: {}.\n", getCaloriesDifference(totalCalories));

		delete[] calories;
	} while (getChoice());

	return 0;
}