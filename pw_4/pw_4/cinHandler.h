#pragma once

#include <iostream>
#include "consts.h"

extern const int MAX_IGNORE_COUNT;
extern const char STOP_IGNORE_CHAR;

void errorClear();

void getValue(auto& variable) {
    while (!(std::cin >> variable)) errorClear();
}

void getValue(auto& variable, auto minValue, auto maxValue) {
    bool valid = false;

    while (!valid) {
        if (!(std::cin >> variable)) {
            errorClear();
            continue;
        }
        else if (variable < minValue || variable >= maxValue) {
            std::cout << ErrorMsg::ERROR_INCORRECT_RANGE_MSG << minValue << RelatedMsg << maxValue << PunctuationMsg::DOT << endl;
            continue;
        }
        else valid = true;
    }
}

void getSign(char& variable);