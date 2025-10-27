/* �������� ��������� ��� �������� ���������� � ��������. 
��������� ������ ��������� ������� 5 �����: ���, ���, �����, �������, ���.
�������� ������� 3 ������: ���������� ���� �� 0,01 �� ������ ���� �������� 
(���*0,01*���-�� ���� ��������), ����� �����, ����� ������ ��������� � �������.
�������� 1 ����������� � 1 ������������ ������ ���������, ������������������ ����. 
�������� ������ ��� ������� ���������� ���������.
*/

#include <iostream>
#include <string>
#include <format>
#include "cinHandler.h"
#include "consts.h"

using namespace std;

const float FEEDING_GAIN = 0.01;

const string NAME_MSG = "Animal`s name: ";
const string TYPE_MSG = "Animal`s type: ";
const string COLOR_MSG = "Animal`s color: ";
const string AGE_MSG = "Animal`s age: ";
const string WEIGHT_MSG = "Animal`s weight: ";

const string GET_DAYS_COUNT_MSG = "Enter the number of feeding days: ";

struct Animal {
	char* name;
	const char* type;
	char* color;
	int age;
	float weight;

	float weightFeedingGain(int daysCount) {
		float weightIncrease = FEEDING_GAIN * daysCount;
		cout << format("The weight increased by {} kg.", weightIncrease)
			<< endl << WEIGHT_MSG << (weight += weightIncrease);
		return weight;
	}

	char* setName(char* newName) { return name = newName; }

	void printInfo() {
		cout << NAME_MSG << name << endl;
		cout << TYPE_MSG << type << endl;
		cout << COLOR_MSG << color << endl;
		cout << AGE_MSG << age << endl;
		cout << WEIGHT_MSG << weight << endl;
	}
};

int main() {
	cout << RelatedMsg::SEPARATOR << endl << endl;

	Animal* dynamicAnimal = new Animal{ (char*)"Max", "Dog", (char*)"Brown", 5, 12.7f };

	dynamicAnimal->printInfo();
	cout << endl;

	int daysCount;
	cout << GET_DAYS_COUNT_MSG;
	getValue(daysCount);
	dynamicAnimal->weightFeedingGain(daysCount);

	delete dynamicAnimal;

	cout << endl << endl << RelatedMsg::SEPARATOR << endl << endl;

	Animal staticAnimal{ (char*)"Whiskers", "Cat", (char*)"White", 3, 4.2f };

	staticAnimal.printInfo();
	cout << endl;

	daysCount;
	cout << GET_DAYS_COUNT_MSG;
	getValue(daysCount);
	staticAnimal.weightFeedingGain(daysCount);

	cout << endl << endl << RelatedMsg::SEPARATOR;
	return 0;
}