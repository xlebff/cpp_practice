#pragma once
#include "Command.h"

class GoCommand :
    public Command
{
public:
    GoCommand();
    bool execute(const std::vector<std::string>& args) override;
};
