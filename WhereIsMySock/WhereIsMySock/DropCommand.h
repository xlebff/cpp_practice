#pragma once
#include "Command.h"

class DropCommand :
    public Command
{
public:
    DropCommand();
    bool execute(const std::vector<std::string>& args) override;
};

