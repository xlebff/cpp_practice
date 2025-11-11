#pragma once
#include "Command.h"
class HelpCommand :
    public Command
{
public:
    HelpCommand();
    bool execute(const std::vector<std::string>& args) override;
};