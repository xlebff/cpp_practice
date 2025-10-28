#include <iostream>
#include "consts.h"

using namespace ErrorMsg;
using namespace std;

const int MAX_IGNORE_COUNT = 1000;
const char STOP_IGNORE_CHAR = '\n';

void errorClear() {
	cin.clear();
	cin.ignore(MAX_IGNORE_COUNT, STOP_IGNORE_CHAR);
}