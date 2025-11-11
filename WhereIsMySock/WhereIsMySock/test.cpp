#define NO_COMPILE
#ifndef NO_COMPILE

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <map>
#include <sstream>

// Concrete commands




class InventoryCommand : public Command {
private:
    std::vector<std::string> inventory = { "lonely sock", "coin", "key" };

public:
    InventoryCommand() : Command("inventory", "Show your inventory") {}

    bool validate(const std::vector<std::string>& args) const override {
        return true; // This command doesn't require arguments
    }

    bool execute(const std::vector<std::string>& args) override {
        std::cout << "Your inventory:\n";
        if (inventory.empty()) {
            std::cout << "Empty\n";
        }
        else {
            for (size_t i = 0; i < inventory.size(); ++i) {
                std::cout << i + 1 << ". " << inventory[i] << "\n";
            }
        }
        return true;
    }
};

class TakeCommand : public Command {
public:
    TakeCommand() : Command("take", "Take an item") {}

    bool execute(const std::vector<std::string>& args) override {
        if (args.empty()) {
            std::cout << "Take what? Please specify an item.\n";
            return false;
        }

        std::string item = args[0];
        std::cout << "You take the " << item << ".\n";

        if (item == "screwdriver") {
            std::cout << "The screwdriver might be useful for mechanical tasks.\n";
        }
        else if (item == "clothespin") {
            std::cout << "A simple wooden clothespin. It looks fragile.\n";
        }
        else {
            std::cout << "You add the " << item << " to your inventory.\n";
        }

        return true;
    }
};

class GoCommand : public Command {
public:
    GoCommand() : Command("go", "Move to another location") {}

    bool execute(const std::vector<std::string>& args) override {
        if (args.empty()) {
            std::cout << "Go where? Please specify a location.\n";
            return false;
        }

        std::string location = args[0];
        std::cout << "You go to the " << location << ".\n";

        if (location == "bedroom") {
            std::cout << "You are in your bedroom. The morning sun shines through the window.\n";
        }
        else if (location == "balcony") {
            std::cout << "You try to go to the balcony, but the door is blocked by a flowerpot outside.\n";
        }
        else if (location == "livingroom") {
            std::cout << "You enter the living room. There's a sofa, TV, and a laundry basket turned upside down.\n";
        }
        else if (location == "kitchen") {
            std::cout << "You're in the kitchen. It smells like coffee and yesterday's pizza.\n";
        }
        else {
            std::cout << "You can't go to the " << location << " from here.\n";
        }

        return true;
    }
};

class CommandHandler {
private:
    std::map<std::string, std::unique_ptr<Command>> commands;

public:
    void registerCommand(std::unique_ptr<Command> cmd) {
        commands[cmd->getName()] = std::move(cmd);
    }

    bool executeCommand(const std::string& input) {
        // Parse user input
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream stream(input);

        while (stream >> token) {
            tokens.push_back(token);
        }

        if (tokens.empty()) {
            std::cout << "Please enter a command.\n";
            return false;
        }

        std::string commandName = tokens[0];
        std::vector<std::string> args(tokens.begin() + 1, tokens.end());

        // Handle quit command separately
        if (commandName == "quit") {
            std::cout << "Thanks for playing!\n";
            return true; // Special return for quit
        }

        // Find and execute command
        auto it = commands.find(commandName);
        if (it != commands.end()) {
            if (it->second->validate(args)) {
                return it->second->execute(args);
            }
        }
        else {
            std::cout << "Unknown command: '" << commandName << "'\n";
            std::cout << "Type 'help' to see available commands.\n";
        }

        return false;
    }

    void showWelcome() {
        std::cout << "=== The Lost Sock Adventure ===\n";
        std::cout << "You wake up and realize one of your favorite socks is missing!\n";
        std::cout << "You can't leave the house with just one sock. Find the missing pair!\n";
        std::cout << "Type 'help' to see available commands.\n";
        std::cout << "Type 'quit' to exit the game.\n\n";
        std::cout << "You are in your bedroom. What do you do?\n";
    }
};

class HelpCommand : public Command {
private:
    CommandHandler* handler;

public:
    HelpCommand(CommandHandler* h) : Command("help", "Show available commands"), handler(h) {}

    bool validate(const std::vector<std::string>& args) const override {
        return true;
    }

    bool execute(const std::vector<std::string>& args) override {
        std::cout << "Available commands:\n";
        // Note: In full implementation, handler would provide command list
        std::cout << "look [object]  - Examine an object or location\n";
        std::cout << "use [item] [target] - Use an item on an object\n";
        std::cout << "take [item]    - Take an item\n";
        std::cout << "go [location]  - Move to another room\n";
        std::cout << "inventory      - Show your inventory\n";
        std::cout << "help           - Show this help message\n";
        std::cout << "quit           - Exit the game\n";
        return true;
    }
};

// Main game loop
int main() {
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