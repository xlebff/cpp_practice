#include <string>
#include <sstream>
#include <iostream>
#include <limits>
#include "consts.h"
#include "myMath.h"

bool isSign(char& variable) {
    return (variable == '+' || variable == '-'
        || variable == '*' || variable == '/'
        || variable == '^' || variable == '!'
        || variable == '&' || variable == '|'
        || variable == '~' || variable == '<' || variable == '>');
}

float add(float& a, float& b) { return a + b; }

float sub(float& a, float& b) { return a - b; }

float mul(float& a, float& b) { return a * b; }

float div(float& a, float& b) {
    if (b != 0) return a / b;
    else return 0;
}

int fact(int a) {
    if (a == 0 || a == 1) return 1;
    else return a * fact(a - 1);
}

float power(float a, float b) {
    if (b == 0) return 1;
    else return a * power(a, b - 1);
}

int bitwiseAnd(int a, int b) { return a & b; }

int bitwiseOr(int a, int b) { return a | b; }

int bitwiseXor(int a, int b) { return a ^ b; }

int bitwiseNot(int a) { return ~a; }

int leftShift(int a, int b) { return a << b; }

int rightShift(int a, int b) { return a >> b; }

bool readExpression(const std::string& input, float& num1, char& sign, float& num2) {
    std::stringstream ss(input);

    if (ss >> num1 >> sign >> num2) {
        if (isSign(sign)) return true;
    }

    ss.clear();
    ss.str(input);

    if (ss >> num1 >> sign && sign == '!') {
        num2 = 0;
        return true;
    }

    ss.clear();
    ss.str(input);

    if (ss >> sign >> num1 && (sign == '~')) {
        num2 = 0;
        return true;
    }

    return false;
}

bool calculateExpression(float& num1, char& sign, float& num2, float& result) {
    switch (sign) {
    case '+': 
        result = add(num1, num2); 
        break;
    case '-': 
        result = sub(num1, num2); 
        break;
    case '*': 
        result = mul(num1, num2); 
        break;
    case '/':
        if (num2 == 0) {
            std::cout << ErrorMsg::ERROR_ZERO_DIV_EXEPTION_MSG << std::endl;
            return false;
        }
        result = div(num1, num2);
        break;
    case '^': 
        result = power(num1, static_cast<int>(num2)); 
        break;
    case '!':
        if (num1 < 0) {
            std::cout << ErrorMsg::ERROR_NEGOTIVE_MSG << std::endl;
            return false;
        }
        if (num1 > 12) {
            std::cout << ErrorMsg::ERROR_TOO_BIG_MSG << std::endl;
            return false;
        }
        result = static_cast<float>(fact(static_cast<int>(num1)));
        break;
    case '&': 
        result = bitwiseAnd(static_cast<int>(num1), static_cast<int>(num2)); 
        break;
    case '|': 
        result = bitwiseOr(static_cast<int>(num1), static_cast<int>(num2)); 
        break;
    case '~': 
        result = bitwiseNot(static_cast<int>(num1)); 
        break;
    case '<': 
        result = leftShift(static_cast<int>(num1), static_cast<int>(num2)); 
        break;
    case '>': 
        result = rightShift(static_cast<int>(num1), static_cast<int>(num2)); 
        break;
    default:
        return false;
    }

    return true;
}