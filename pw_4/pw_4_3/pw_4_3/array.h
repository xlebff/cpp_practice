#pragma once
#include <string>

extern const char ABORT[];
extern const char NO_VALUES[];

template<typename T>
void fillArray(const char* element, T* array, const int size);

template<typename T>
void fillArray(const char* element, T* array, const int size, const T minValue, const T maxValue);

template<typename T>
void printArray(T* array, const int size, bool isReverse);

template<typename T>
void printExceptValue(T* array, const int size, const T exeptValue);

template<typename T>
void printArray(const char* element, T* array, const int size, bool isReverse);

template<typename T>
T getMinValue(T* array, const int size);

template<typename T>
T getMaxValue(T* array, const int size);

template<typename T>
T getSum(T* array, const int size);

template<typename T>
float getAverage(T* array, const int size);

template<typename T>
T* extend(T* array, const int size);

template<typename T>
bool contains(T* array, const int size, const T value);

template<typename T>
int addValue(const char* msg, T*& array, int& capacity);

template<typename T>
int addUniqValue(const char* msg, T*& array, int& capacity);

template<typename T>
void removeValue(const char* msg, T* array, const int capacity);

template<typename T>
void clearArray(T* array, const int capacity);

template void fillArray<int>(const char*, int*, const int);
template void fillArray<float>(const char*, float*, const int);

template void fillArray<int>(const char*, int*, const int, const int, const int);
template void fillArray<float>(const char*, float*, const int, const float, const float);

template void printArray<int>(int*, const int, bool);
template void printArray<float>(float*, const int, bool);

template void printExceptValue<int>(int*, const int, int);
template void printExceptValue<float>(float*, const int, float);

template void printArray<int>(const char*, int*, const int, bool);
template void printArray<float>(const char*, float*, const int, bool);

template int getMinValue<int>(int*, const int);
template float getMinValue<float>(float*, const int);

template int getMaxValue<int>(int*, const int);
template float getMaxValue<float>(float*, const int);

template int getSum<int>(int*, const int);
template float getSum<float>(float*, const int);

template float getAverage<int>(int*, const int);
template float getAverage<float>(float*, const int);

template int* extend<int>(int*, const int);
template float* extend<float>(float*, const int);

template bool contains<int>(int*, const int, const int);
template bool contains<float>(float*, const int, const float);

template int addValue<int>(const char*, int*&, int&);
template int addValue<float>(const char*, float*&, int&);

template int addUniqValue<int>(const char*, int*&, int&);
template int addUniqValue<float>(const char*, float*&, int&);

template void removeValue<int>(const char*, int*, const int);
template void removeValue<float>(const char*, float*, const int);

template void clearArray<int>(int*, const int);
template void clearArray<float>(float*, const int);