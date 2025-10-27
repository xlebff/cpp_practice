/* �������� ��������� ��� �������� ���������� �� ����������.
��������� ������ ��������� ������� 5 �����: �����, ����, ��� ������, ����� ���������, ������.
�������� ������� 3 ������: ������� �������� ������� ������� �� 100 ��
(����� ���������/���������� ���������� * 100), ���������� �������, ����� ������ ��������� � �������.
�������� 1 ����������� � 1 ������������ ������ ���������, ������������������ ����.
�������� ������ ��� ������� ���������� ���������.
*/

#include <iostream>
#include <string>
#include <format>
#include <cmath>
#include "cinHandler.h"
#include "consts.h"

using namespace std;

const string BRAND_MSG = "Car brand: ";
const string COLOR_MSG = "Car color: ";
const string BODY_TYPE_MSG = "Car body type: ";
const string ENGINE_CAPACITY_MSG = "Car engine capacity: ";
const string MILEAGE_MSG = "Car mileage: ";
const string AVERAGE_FUEL_CONSUMPTION_MSG = "Average fuel consumption per 100 km: ";
const string GET_DECREASE_MILEAGE_MSG = "Specify how much you want to reduce the mileage: ";

struct Car {
	const char* brand;
	const char* color;
	const char* bodyType;
	const float engineCapacity;
	float mileage;

	float averagFuelConsumption() {
		return mileage ? (round)((engineCapacity / mileage * 100) * 1000) / 1000 : 0;
	}

	float decreaseMileage(float decreasedKilometers) {
		if (decreasedKilometers < 0) decreasedKilometers *= -1;
		else;

		mileage -= decreasedKilometers < mileage ?
			decreasedKilometers : mileage;

		cout << format("The mileage has been decreased by {} km.\n", decreasedKilometers) <<
			format("New mileage: {}.\n", mileage);

		return mileage;
	}

	void printInfo() {
		cout << BRAND_MSG << brand << endl;
		cout << COLOR_MSG << color << endl;
		cout << BODY_TYPE_MSG << bodyType << endl;
		cout << ENGINE_CAPACITY_MSG << engineCapacity << endl;
		cout << MILEAGE_MSG << mileage << endl;
	}
};

int main() {
	cout << RelatedMsg::SEPARATOR << endl << endl;

	Car* dynamicCar = new Car{ "Toyota", "Red", "Sedan", 2.0, 15000 };

	dynamicCar->printInfo();

	float decreasedKilometers;
	cout << endl << GET_DECREASE_MILEAGE_MSG;
	getValue(decreasedKilometers);
	dynamicCar->decreaseMileage(decreasedKilometers);
	cout << endl;

	cout << AVERAGE_FUEL_CONSUMPTION_MSG << dynamicCar->averagFuelConsumption();

	delete dynamicCar;

	cout << endl << endl << RelatedMsg::SEPARATOR << endl << endl;

	Car staticCar{ "BMV", "Black", "Off-road vehicle", 3.0, 25000 };

	staticCar.printInfo();

	cout << endl << GET_DECREASE_MILEAGE_MSG;
	getValue(decreasedKilometers);
	staticCar.decreaseMileage(decreasedKilometers);
	cout << endl;

	cout << AVERAGE_FUEL_CONSUMPTION_MSG << staticCar.averagFuelConsumption();

	cout << endl << endl << RelatedMsg::SEPARATOR;
	return 0;
}