#pragma once
#include "Command.h"

class UseCommand :
    public Command
{
public:
    UseCommand();
    bool execute(const std::vector<std::string>& args) override;
    bool validate(const std::vector<std::string>& args) override;
};
