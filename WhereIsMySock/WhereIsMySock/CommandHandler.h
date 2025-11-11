#pragma once
#include <iostream>
#include <map>
#include <sstream>
#include "Command.h"

class CommandHandler {
public:
    static CommandHandler* getInstance();
    void registerCommand(Command* cmd);
    bool executeCommand(const std::string& input);
    void welcome();

private:
    static CommandHandler* instance;
    std::map<std::string, Command*> commands;
};
