#pragma once

#include <iostream>

extern const int MAX_IGNORE_COUNT;
extern const char STOP_IGNORE_CHAR;

void errorClear();

template<typename T>
void getValue(T& variable);

template<typename T>
void getValue(T& variable, const char* msg, const char* errorMsg);

template<typename T>
bool tryGetValue(T& variable);

template<typename T>
void getValue(T& variable, T minValue, T maxValue);

template<typename T>
void getValue(T& variable, T minValue, T maxValue, const char* msg, const char* errorMsg);

template<typename T>
bool tryGetValue(T& variable, T minValue, T maxValue);

template<typename T>
bool tryGetValue(T& variable, T minValue, T maxValue, const char* errorMsg);