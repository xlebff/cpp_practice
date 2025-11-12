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

class Facade {
public:
    static Facade* getInstance();

    bool processInput(const std::string& input);
    void showWelcome();
    void showHelp();

    bool moveTo(const std::string& roomName);
    bool takeItem(const std::string& itemName);
    /*bool dropItem(const std::string& itemName);
    bool useItem(const std::string& itemName, const std::string& targetName = "");
    bool inspect(const std::string& objectName);
    void showInventory();*/
    void lookAround();

private:
    static Facade* instance;
    Facade();

    void parseInput(const std::string& input, 
        std::string& action, 
        std::vector<std::string>& args);
};