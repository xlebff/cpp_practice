#pragma once

class Animal {
public:
	Animal(char* name,
			const char* type,
			char* color,
			int age,
			float weight);

	const float weightFeedingGain(int daysCount);
	const void printInfo();
	const char* getName();
	const char* getType();
	const char* getColor();
	const int getAge();
	const float getWeight();
	void setName(char* name);

private:
	char* name;
	const char* type;
	char* color;
	int age;
	float weight;
};