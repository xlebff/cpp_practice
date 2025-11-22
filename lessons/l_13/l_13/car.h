#pragma once

class Car {
public:
	Car(const char* brand,
		const char* color,
		const char* bodyType,
		const float engineCapacity,
		const float mileage);

	float averagFuelConsumption();
	float decreaseMileage(float decreasedKilometers);
	const void printInfo();

	const char* getBrand();
	const char* getColor();
	const char* getBodyType();
	const float getEngineCapacity();

private:
	const char* brand;
	const char* color;
	const char* bodyType;
	const float engineCapacity;
	float mileage;
};
