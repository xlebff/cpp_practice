#include <iostream>

using namespace std;

const int TARGET_EATING_COUNT = 5;
const int LOWEST_EATING_COUNT = 3;
const int LARGEST_EATING_COUNT = 7;

const float TARGET_CALORIES_COUNT = 2000;
const int WARNING_CALORIES_COEF = 2;

const char TOO_MANY_EATING_COUNT_MSG[] = "Warning: Too many meals!Eat normally already..";
const char TOO_LITTLE_EATING_COUNT_MSG[] = "Warning: Too few meals! You'll fly away..";
const char TOO_MANY_CALORIES_MSG[] = "Warning: The amount of calories consumed exceeds the target by 2 times. Stop eating so much :(";
const char TOO_LITTLE_CALORIES_MSG[] = "Warning: The amount of calories consumed is 2 times lower than the target. You're kidding me.";
const char NORMAL_EATING_COUNT_MSG[] = "The number of meals is normal.";
const char NORMAL_CALORIES_MSG[] = "The number of calories consumed is normal.";

float getCaloriesDifference(float realCalories) {
	return fabsf(TARGET_CALORIES_COUNT - realCalories);
}

bool isEatingCountNormal(int eating_count) {
	if (eating_count > LARGEST_EATING_COUNT) cout << TOO_MANY_EATING_COUNT_MSG << endl;
	else if (eating_count < LOWEST_EATING_COUNT) cout << TOO_LITTLE_EATING_COUNT_MSG << endl;
	else {
		cout << NORMAL_EATING_COUNT_MSG << endl;
		return true;
	}

	return false;
}

bool isCaloriesNormal(float calories) {
	if (calories >= TARGET_CALORIES_COUNT * WARNING_CALORIES_COEF) cout << TOO_MANY_CALORIES_MSG << endl;
	else if (calories <= TARGET_CALORIES_COUNT / WARNING_CALORIES_COEF) cout << TOO_LITTLE_CALORIES_MSG << endl;
	else {
		cout << NORMAL_CALORIES_MSG << endl;
		return true;
	}

	return false;
}