#include <string>
#include "consts.h"

namespace PunctuationMsg {
    extern const std::string DOT = ".";
    extern const std::string COMMA = ", ";
    extern const std::string COLON = ": ";
    const std::string SPACE = " ";
    const std::string STICK = " - ";
}

namespace ErrorMsg {
    extern const std::string ERROR_NAN_MSG = "Error: Not a number.";
    extern const std::string ERROR_INCORRECT_RANGE_MSG = "Error: The value must be between ";
    extern const std::string ERROR_NEGOTIVE_MSG = "Error: The value must be greater than 0.";
    extern const std::string ERROR_NOT_FOUND_MSG = "Error: Not found.";
    extern const std::string ERROR_NOT_UNIQUE_MSG = "Error: The value is already exists.";
}

namespace RelatedMsg {
    extern const std::string AND = " and ";
}