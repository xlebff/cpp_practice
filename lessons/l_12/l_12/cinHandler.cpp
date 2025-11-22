#include <iostream>
#include "consts.h"

using namespace ErrorMsg;
using namespace std;

const int MAX_IGNORE_COUNT = 1000;
const char STOP_IGNORE_CHAR = '\n';

void errorClear() {
	cin.clear();
	cin.ignore(MAX_IGNORE_COUNT, STOP_IGNORE_CHAR);
	cout << ERROR_NAN_MSG << endl;
}

void getSign(char& variable) {
    bool valid = false;

    while (!valid) {
        if (!(std::cin >> variable)) {
            errorClear();
            continue;
        }
        else if (variable != '+' && variable != '-'
            && variable != '*' && variable != '/'
            && variable != '^' && variable != '!') {
            std::cout << ErrorMsg::ERROR_NOT_FOUND_MSG << endl;
            continue;
        }
        else valid = true;
    }
}