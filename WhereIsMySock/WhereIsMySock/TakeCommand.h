#pragma once
#include "Command.h"

class TakeCommand : public Command {
public:
    TakeCommand();
    bool execute(const std::vector<std::string>& args) override;
};
