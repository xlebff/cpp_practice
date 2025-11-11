#define NO_COMPILE
#ifndef NO_COMPILE

#include <iostream>
#include <vector>
#include <map>
#include "Object.h"



// Main game loop
int main() {
    Object 
    CommandHandler handler;

    // Register all commands
    handler.registerCommand(std::make_unique<LookCommand>());
    handler.registerCommand(std::make_unique<UseCommand>());
    handler.registerCommand(std::make_unique<InventoryCommand>());
    handler.registerCommand(std::make_unique<TakeCommand>());
    handler.registerCommand(std::make_unique<GoCommand>());
    handler.registerCommand(std::make_unique<HelpCommand>(&handler));

    // Show welcome message
    handler.showWelcome();

    // Main game loop
    std::string input;
    bool gameRunning = true;

    while (gameRunning) {
        std::cout << "\n> ";
        std::getline(std::cin, input);

        // Convert to lowercase for case-insensitive commands
        for (char& c : input) {
            c = std::tolower(c);
        }

        if (input == "quit") {
            std::cout << "Thanks for playing The Lost Sock Adventure!\n";
            break;
        }

        bool result = handler.executeCommand(input);

        // Special handling for game completion
        if (input.find("use screwdriver clothesline") != std::string::npos) {
            std::cout << "\n*** CONGRATULATIONS! ***\n";
            std::cout << "You found your missing sock! The pair is reunited!\n";
            std::cout << "You can now leave the house properly dressed.\n";
            std::cout << "Thank you for playing!\n";
            break;
        }
    }

    return 0;
}

#endif