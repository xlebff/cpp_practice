#include "cinHandler.h"
#include "consts.h"

using namespace ErrorMsg;
using namespace std;

const int MAX_IGNORE_COUNT = 1000;
const char STOP_IGNORE_CHAR = '\n';

void errorClear() {
    cin.clear();
    cin.ignore(MAX_IGNORE_COUNT, STOP_IGNORE_CHAR);
}

template<typename T>
void getValue(T& variable) {
    while (!(cin >> variable)) errorClear();
}

template<typename T>
void getValue(T& variable, const char* msg, const char* errorMsg) {
    while (!(cin >> variable)) {
        cout << errorMsg << endl << msg;
        errorClear();
    }
}

template<typename T>
bool tryGetValue(T& variable) {
    if (cin >> variable) {
        return true;
    }
    errorClear();
    return false;
}

template<typename T>
void getValue(T& variable, T minValue, T maxValue) {
    bool valid = false;

    while (!valid) {
        if (!(cin >> variable)) {
            errorClear();
            cout << ErrorMsg::ERROR_NAN_MSG << endl;
            continue;
        }
        else if (variable < minValue || variable >= maxValue) {
            cout << ERROR_INCORRECT_RANGE_MSG << minValue << RelatedMsg::AND << maxValue << PunctuationMsg::DOT << endl;
            continue;
        }
        else valid = true;
    }
}

template<typename T>
void getValue(T& variable, T minValue, T maxValue, const char* msg, const char* errorMsg) {
    bool valid = false;

    while (!valid) {
        if (!(cin >> variable)) {
            errorClear();
            cout << "errorMsg" << endl << msg;
            continue;
        }
        else if (variable < minValue || variable >= maxValue) {
            cout << ERROR_INCORRECT_RANGE_MSG << minValue << RelatedMsg::AND << maxValue << PunctuationMsg::DOT << endl;
            cout << msg;
            continue;
        }
        else valid = true;
    }
}

template<typename T>
bool tryGetValue(T& variable, T minValue, T maxValue) {
    if (!(cin >> variable)) {
        errorClear();
        return false;
    }

    if (variable < minValue || variable >= maxValue) {
        cout << ERROR_INCORRECT_RANGE_MSG << minValue << RelatedMsg::AND << maxValue << PunctuationMsg::DOT << std::endl;
        return false;
    }

    return true;
}

template<typename T>
bool tryGetValue(T& variable, T minValue, T maxValue, const char* errorMsg) {
    if (!(cin >> variable)) {
        errorClear();
        cout << errorMsg << endl;
        return false;
    }

    if (variable < minValue || variable >= maxValue) {
        cout << ERROR_INCORRECT_RANGE_MSG << minValue << RelatedMsg::AND << maxValue << PunctuationMsg::DOT << endl;
        return false;
    }

    return true;
}

template void getValue<int>(int&);
template void getValue<float>(float&);

template bool tryGetValue<int>(int&);
template bool tryGetValue<float>(float&);

template void getValue<int>(int&, int, int);
template void getValue<float>(float&, float, float);

template bool tryGetValue<int>(int&, int, int);
template bool tryGetValue<float>(float&, float, float);
template bool tryGetValue<double>(double&, double, double);

template void getValue<int>(int&, const char*, const char*);
template void getValue<float>(float&, const char*, const char*);

template void getValue<int>(int&, int, int, const char*, const char*);
template void getValue<float>(float&, float, float, const char*, const char*);

template bool tryGetValue<int>(int&, int, int, const char*);
template bool tryGetValue<float>(float&, float, float, const char*); 
template bool tryGetValue<double>(double&, double, double, const char*);