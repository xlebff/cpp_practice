#pragma once

#include <iostream>
#include <sstream>
#include "consts.h"

extern const int MAX_IGNORE_COUNT;
extern const char STOP_IGNORE_CHAR;

void errorClear();

template<typename T>
bool getValue(T& variable) {
    if (!(std::cin >> variable)) {
        errorClear();
        return false;
    }

    return true;
}

template<typename T>
void getValue(T& variable, T minValue, T maxValue) {
    bool valid = false;

    while (!valid) {
        if (!(std::cin >> variable)) {
            errorClear();
            continue;
        }
        else if (variable < minValue || variable >= maxValue) {
            std::cout << ErrorMsg::ERROR_INCORRECT_RANGE_MSG << minValue << RelatedMsg::AND << maxValue << PunctuationMsg::DOT << std::endl;
            continue;
        }
        else valid = true;
    }
}