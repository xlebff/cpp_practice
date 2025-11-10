#include <iostream>
#include "car.h"
#include "animal.h"
#include "cinHandler.h"
#include "consts.h"

using namespace std;

int main() {
	const char BRAND_MSG[] = "Car brand: ";
	const char COLOR_MSG[] = "Car color: ";
	const char BODY_TYPE_MSG[] = "Car body type: ";
	const char ENGINE_CAPACITY_MSG[] = "Car engine capacity: ";
	const char MILEAGE_MSG[] = "Car mileage: ";
	const char AVERAGE_FUEL_CONSUMPTION_MSG[] = "Average fuel consumption per 100 km: ";
	const char GET_DECREASE_MILEAGE_MSG[] = "Specify how much you want to reduce the mileage: ";
	const char GET_DAYS_COUNT_MSG[] = "Enter the number of feeding days: ";

	float decreasedKilometers;

	cout << RelatedMsg::SEPARATOR << endl << endl;

	Car* dynamicCar = new Car( "Toyota", "Red", "Sedan", 2.0, 15000 );

	dynamicCar->printInfo();

	cout << endl << GET_DECREASE_MILEAGE_MSG;
	getValue(decreasedKilometers);
	dynamicCar->decreaseMileage(decreasedKilometers);
	cout << endl;

	cout << AVERAGE_FUEL_CONSUMPTION_MSG << dynamicCar->averagFuelConsumption();

	delete dynamicCar;

	cout << endl << endl << RelatedMsg::SEPARATOR << endl << endl;

	Car staticCar("Toyota", "Red", "Sedan", 2.0, 15000);

	staticCar.printInfo();

	cout << endl << GET_DECREASE_MILEAGE_MSG;
	getValue(decreasedKilometers);
	staticCar.decreaseMileage(decreasedKilometers);
	cout << endl;

	cout << AVERAGE_FUEL_CONSUMPTION_MSG << staticCar.averagFuelConsumption();

	cout << endl << endl << RelatedMsg::SEPARATOR << endl << endl;

	Animal* dynamicAnimal = new Animal( (char*)"Max", "Dog", (char*)"Brown", 5, 12.7f );

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