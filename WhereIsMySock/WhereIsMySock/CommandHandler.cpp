#include "CommandHandler.h"

using namespace std;

void CommandHandler::registerCommand(Command* cmd) {
    commands[cmd->getName()] = move(cmd);
}

bool CommandHandler::executeCommand(const string& input) {
    vector<string> tokens;
    string token;
    istringstream stream(input);

    while (stream >> token) tokens.push_back(token);

    if (tokens.empty()) {
        cout << "Please enter a command." << endl;
        return false;
    }

    string commandName = tokens[0];
    vector<string> args(tokens.begin() + 1, tokens.end());

    if (commandName == "quit") {
        cout << "Thanks for playing!" << endl;
        return true;
    }
    else;

    auto it = commands.find(commandName);
    if (it != commands.end()) {
        if (it->second->validate(args)) {
            return it->second->execute(args);
        }
        else;
    }
    else {
        cout << "Unknown command: '" << commandName << endl;
        cout << "Type 'help' to see available commands." << endl;
    }

    return false;
}

void CommandHandler::welcome() {
    cout << "=== The Lost Sock Adventure ===" << endl
        << "You wake up and realize one of your favorite socks is missing!" << endl
        << "You can't leave the house with just one sock. Find the missing pair!" << endl
        << "Type 'help' to see available commands." << endl
        << "Type 'quit' to exit the game." << endl << endl
        << "You are in your bedroom. What do you do?" << endl;
}
