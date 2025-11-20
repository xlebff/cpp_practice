#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "Player.h"
#include "Room.h"
#include "Inventory.h"
#include "Item.h"
#include "Object.h"
#include "UsageManager.h"

class Facade {
public:
    static Facade* getInstance();

    bool processInput(std::string& input);
    void showWelcome();
    void showHelp();

    bool moveTo(const std::string& roomName);
    bool takeItem(const std::string& itemName);
    bool dropItem(const std::string& itemName);
    bool useItem(std::vector<std::string> args);
    bool inspect(const std::string& objectName);
    void showInventory();
    void lookAround();

private:
    static Facade* instance;
    Facade();

    bool parseInput(std::string& input, 
        std::string& action, 
        std::vector<std::string>& args);

    std::string combineArgs(const std::vector<std::string>& args);

    bool isCommand(std::string& curCmd);
};