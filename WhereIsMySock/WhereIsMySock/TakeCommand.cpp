#include <iostream>
#include "TakeCommand.h"

using namespace std;

TakeCommand::TakeCommand() : Command("take", "Take an item") {}

bool TakeCommand::execute(const vector<string>& args) {
    Room* room = Player::getInstance()->getCurRoom();
    Inventory* inventory = Player::getInstance()->getInventory();

    if (!validate(args)) {
        cout << "Specify the item you want to pick up." << endl;
        return false;
    }
    else;

    Object* target = room->findObject(args[0]);
    if (!target) {
        cout << "There is no '" << args[0] << "' here." << endl;
        return false;
    } else {
#ifdef DEBUG
        cout << "The object " << args[1] << " is specified correctly." << endl;
#endif
    }

    if (inventory->takeItem((Item*)target)) {
        cout << "You`re taking the " << target << "." << endl;
        return true;
    }
    else return false;
}

