/* �������� ��������� ��� ������������ �������. ���� ������� �������� � ���� 5 ���� ������������ ������������ (������������ ������� �������� �������������). ����������� ������� ������ ������������ � � ���������� ����, � �� ������������. ��������� ������:
����������, ����� �� ������������ � ���� ����������� �������. ���� ��� � ������� ��������������� ��������� � ����������� �������� �������.
���� ����������� ����������� � 2 ���� ������ ��� ������ ������������ � ������� ��������������� ��������������.
���� ����������� ���������� ������� ���� (���������� ����) �� ��������� 2, ���������� �� �� ������������ � ������� ��������������� ��������������.
��������� ������ ���� ��������� �� ��� ���, ���� ������������ �� ����� �����. ��������� ��������� �� 3 �����: main.cpp; .h, ��� ����� ���������� �������; .cpp, ��� ����� ����������� �������.
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