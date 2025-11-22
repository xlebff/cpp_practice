#include <iostream>
#include <format>
#include "car.h"

using namespace std;

const char BRAND_MSG[] = "Car brand: ";
const char COLOR_MSG[] = "Car color: ";
const char BODY_TYPE_MSG[] = "Car body type: ";
const char ENGINE_CAPACITY_MSG[] = "Car engine capacity: ";
const char MILEAGE_MSG[] = "Car mileage: ";
const char AVERAGE_FUEL_CONSUMPTION_MSG[] = "Average fuel consumption per 100 km: ";
const char GET_DECREASE_MILEAGE_MSG[] = "Specify how much you want to reduce the mileage: ";

Car::Car(const char* brand,
    const char* color,
    const char* bodyType,
    float engineCapacity,
    float mileage)
    : brand(brand),
    color(color),
    bodyType(bodyType),
    engineCapacity(engineCapacity),
    mileage(mileage)
{
}

float Car::averagFuelConsumption() {
	return mileage ? (round)((engineCapacity / mileage * 100) * 1000) / 1000 : 0;
}

float Car::decreaseMileage(float decreasedKilometers) {
    if (decreasedKilometers < 0) decreasedKilometers *= -1;
    else;

    mileage -= decreasedKilometers < mileage ?
        decreasedKilometers : mileage;

    cout << format("The mileage has been decreased by {} km.\n", decreasedKilometers) <<
        format("New mileage: {}.\n", mileage);

    return mileage;
}

const void Car::printInfo() {
    cout << BRAND_MSG << brand << endl;
    cout << COLOR_MSG << color << endl;
    cout << BODY_TYPE_MSG << bodyType << endl;
    cout << ENGINE_CAPACITY_MSG << engineCapacity << endl;
    cout << MILEAGE_MSG << mileage << endl;
}

const char* Car::getBrand() { return this->brand; }

const char* Car::getColor() { return this->color; }

const char* Car::getBodyType() { return this->bodyType; }

const float Car::getEngineCapacity() { return this->engineCapacity; }