#pragma once
#include <string>

bool isSign(char& variable);

float add(float& a, float& b);

float sub(float& a, float& b);

float mul(float& a, float& b);

float div(float& a, float& b);

int fact(int a);

float power(float a, float b);

int bitwiseAnd(int a, int b);

int bitwiseOr(int a, int b);

int bitwiseXor(int a, int b);

int bitwiseNot(int a);

int leftShift(int a, int b);

int rightShift(int a, int b);

bool readExpression(const std::string& input, float& num1, char& sign, float& num2);

bool calculateExpression(float& num1, char& sign, float& num2, float& result);