#include <iostream>
#include <format>
#include "animal.h"

using namespace std;

const char* NAME_MSG = "Animal`s name: ";
const char* TYPE_MSG = "Animal`s type: ";
const char* COLOR_MSG = "Animal`s color: ";
const char* AGE_MSG = "Animal`s age: ";
const char* WEIGHT_MSG = "Animal`s weight: ";

const float FEEDING_GAIN = 0.01;

Animal::Animal(char* name,
	const char* type,
	char* color,
	int age,
	float weight) {
	this->name = name;
	this->type = type;
	this->color = color;
	this->age = age;
	this->weight = weight;
}

const float Animal::weightFeedingGain(int daysCount) {
	float weightIncrease = FEEDING_GAIN * daysCount;
	cout << format("The weight increased by {} kg.", weightIncrease)
		<< endl << WEIGHT_MSG << (weight += weightIncrease);
	return weight;
}

const void Animal::printInfo() {
	cout << NAME_MSG << name << endl;
	cout << TYPE_MSG << type << endl;
	cout << COLOR_MSG << color << endl;
	cout << AGE_MSG << age << endl;
	cout << WEIGHT_MSG << weight << endl;
}

const char* Animal::getName() { return this->name; }

const char* Animal::getType() { return this->type; }

const char* Animal::getColor() { return this->color; }

const int Animal::getAge() { return this->age; }

const float Animal::getWeight() { return this->weight; }

void Animal::setName(char* name) { this->name = name; }