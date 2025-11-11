#pragma once
#include "Command.h"

class InventoryCommand :
    public Command
{
    InventoryCommand();
    bool execute(const std::vector<std::string>& args) override;
};
