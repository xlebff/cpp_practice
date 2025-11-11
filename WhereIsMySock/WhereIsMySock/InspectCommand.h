#pragma once
#include "Command.h"

class InspectCommand :
    public Command
{
public:
    InspectCommand();
    bool execute(const std::vector<std::string>& args) override;
};
