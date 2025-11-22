#pragma once

#include <iostream>
#include "consts.h"

extern const int MAX_IGNORE_COUNT;
extern const char STOP_IGNORE_CHAR;

void errorClear();

template<typename T>
void getValue(T& variable) {
    while (!(std::cin >> variable)) errorClear();
}

template<typename T>
void getValue(T& variable, const char* msg) {
    std::cout << msg;
    while (!(std::cin >> variable)) {
        std::cout << ErrorMsg::ERROR_INCORRECT_VALUE_MSG << std::endl;
        errorClear();
    }
}

template<typename T>
bool tryGetValue(T& variable) {
    if (std::cin >> variable) return true;
    else {
        errorClear();
        return false;
    }
}


template<typename T>
void getValue(T& variable, T minValue, T maxValue) {
    bool valid = false;

    while (!valid) {
        if (!(std::cin >> variable)) {
            errorClear();
            std::cout << ErrorMsg::ERROR_NAN_MSG << std::endl;
            continue;
        }
        else if (variable < minValue || variable >= maxValue) {
            std::cout << ErrorMsg::ERROR_INCORRECT_VALUE_MSG << minValue <<
                RelatedMsg::AND << maxValue << PunctuationMsg::DOT << std::endl;
            continue;
        }
        else valid = true;
    }
}

template<typename T>
void getValue(T& variable, T minValue, T maxValue, const char* msg) {
    std::cout << msg;
    bool valid = false;

    while (!valid) {
        if (!(std::cin >> variable)) {
            errorClear();
            std::cout << ErrorMsg::ERROR_INCORRECT_VALUE_MSG << std::endl;
            continue;
        }
        else if (variable < minValue || variable >= maxValue) {
            std::cout << ErrorMsg::ERROR_INCORRECT_RANGE_MSG << minValue <<
                RelatedMsg::AND << maxValue << PunctuationMsg::DOT << std::endl;
            continue;
        }
        else valid = true;
    }
}

template<typename T>
bool tryGetValue(T& variable, const T minValue, const T maxValue) {
    if (!(std::cin >> variable)) {
        errorClear();
        std::cout << ErrorMsg::ERROR_INCORRECT_VALUE_MSG << std::endl;
        return false;
    }
    else;

    if (variable < minValue || variable >= maxValue) {
        std::cout << ErrorMsg::ERROR_INCORRECT_RANGE_MSG << minValue <<
            RelatedMsg::AND << maxValue << PunctuationMsg::DOT << std::endl;
        return false;
    }
    else;

    return true;
}