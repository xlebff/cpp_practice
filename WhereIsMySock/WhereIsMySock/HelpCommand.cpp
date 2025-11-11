#include <iostream>
#include "HelpCommand.h"

using namespace std;

HelpCommand::HelpCommand() : Command("help", "Show available commands") {}

bool HelpCommand::execute(const std::vector<std::string>& args) {
    std::cout << "Available commands:\n";
    std::cout << "look [object]  - Examine an object or location\n";
    std::cout << "use [item] [target] - Use an item on an object\n";
    std::cout << "take [item]    - Take an item\n";
    std::cout << "drop [item]    - Drop an item\n";
    std::cout << "go [location]  - Move to another room\n";
    std::cout << "inventory      - Show your inventory\n";
    std::cout << "help           - Show this help message\n";
    std::cout << "quit           - Exit the game\n";
    return true;
}
