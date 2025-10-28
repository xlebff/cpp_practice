#pragma once

extern const int TARGET_EATING_COUNT;
extern const int LOWEST_EATING_COUNT;
extern const int LARGEST_EATING_COUNT;

extern const float TARGET_CALORIES_COUNT;
extern const int WARNING_CALORIES_COEF;

extern const char TOO_MANY_EATING_COUNT_MSG[];
extern const char TOO_LITTLE_EATING_COUNT_MSG[];
extern const char TOO_MANY_CALORIES_MSG[];
extern const char TOO_LITTLE_CALORIES_MSG[];
extern const char NORMAL_EATING_COUNT_MSG[];
extern const char NORMAL_CALORIES_MSG[];

bool isEatingCountNormal(int eating_count);

bool isCaloriesNormal(float calories);