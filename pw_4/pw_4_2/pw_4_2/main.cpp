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
		int real_eating_count;
		cout << EATING_COUNT_MSG;
		getValue(real_eating_count, 0, 50, EATING_COUNT_MSG, ErrorMsg::ERROR_NAN_MSG);

		float* calories = new float[real_eating_count];
		float total_calories = 0;

		cout << CALORIES_MSG << endl;
		for (int i = 0; i < real_eating_count; ++i) {
			string element = format("Meal {}: ", i + 1);
			cout << element;
			getValue(calories[i], 1.0f, 10000.0f, element.c_str(), ErrorMsg::ERROR_NAN_MSG);
			total_calories += calories[i];
		}

		isEatingCountNormal(real_eating_count);

		isCaloriesNormal(total_calories);

		delete[] calories;
	} while (getChoice());

	return 0;
}