#pragma once
#include <iostream>
#include <string>

extern const int MAX_IGNORE_COUNT;
extern const char STOP_IGNORE_CHAR;

extern const std::string ERROR_CHAR_MSG;
extern const std::string ERROR_NUM_MSG;
extern const std::string AND;

int getSize(const std::string start_msg, const int minValue, const int maxValue);
void fillArray(const std::string element, const std::string colon, int *array, const int size);
void fillArray(const std::string element, const std::string colon, int *array, const int size, const int minValue, const int maxValue);
void printArray(const std::string element, const std::string colon, int *array, const int size, bool isReverse = false);
int getMaxValue(int *array, int size);
float getAverage(int *array, int size);
int getSum(int *array, int size);