#include <string>
#include "consts.h"
using namespace std;

namespace PunctuationMsg {
    const char DOT = '.';
    const char COMMA = ',';
    const char COLON = ':';
    const char SPACE = ' ';
}

namespace ErrorMsg {
    const string ERROR_NAN_MSG = "Error: Not a number.";
    const string ERROR_INCORRECT_RANGE_MSG = "Error: The value must be between ";
    const string ERROR_NEGOTIVE_MSG = "Error: The value must be greater than 0.";
    const string ERROR_NOT_FOUND_MSG = "Error: Not found.";
    const string ERROR_NOT_UNIQUE_MSG = "Error: The value is already exists.";
}

namespace RelatedMsg {
    const string AND = " and ";
    const string SEPARATOR = "====================";
}