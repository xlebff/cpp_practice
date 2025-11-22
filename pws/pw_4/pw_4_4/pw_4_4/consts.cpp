#include <string>
#include "consts.h"
using namespace std;

namespace PunctuationMsg {
    const char DOT = '.';
    const char COMMA = ',';
    const char COLON = ':';
}

namespace ErrorMsg {
    const char ERROR_NAN_MSG[] = "Error: Not a number.";
    const char ERROR_INCORRECT_VALUE[] = "Error: Incorrect value type.";
    const char ERROR_INCORRECT_RANGE_MSG[] = "Error: The value must be between ";
    const char ERROR_NEGOTIVE_MSG[] = "Error: The value must be greater than 0.";
    const char ERROR_NOT_FOUND_MSG[] = "Error: Not found.";
    const char ERROR_NOT_UNIQUE_MSG[] = "Error: The value is already exists.";
    const char ERROR_ZERO_DIV_EXEPTION_MSG[] = "Error: Division by 0 is not possible.";
    extern const char ERROR_TOO_BIG_MSG[] = "Error: Too large number.";
}

namespace RelatedMsg {
    const char AND[] = " and ";
    const char SPACE = ' ';
    const char SEPARATOR[] = "=========\n";
}