#pragma once
#include <string>
#include <vector>
#include "Player.h"
#include "Room.h"
#include "Object.h"

class Command {
public:
    Command(const std::string& name, const std::string& desc);
    virtual ~Command() = default;

    virtual bool execute(const std::vector<std::string>& args) = 0;
    virtual bool validate(const std::vector<std::string>& args);

    std::string getName() const;
    std::string getDescription() const;

protected:
    std::string name;
    std::string desc;
};