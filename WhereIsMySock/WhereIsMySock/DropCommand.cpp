#include <iostream>
#include "DropCommand.h"

using namespace std;

DropCommand::DropCommand() : Command("drop", "Drop an item") { }

bool DropCommand::execute(const vector<string>& args) {
    Room* room = Player::getInstance()->getCurRoom();
    Inventory* inventory = Player::getInstance()->getInventory();

    if (!validate(args)) {
        cout << "Specify the item you want to drop." << endl;
        return false;
    }
    else;

    Item* item = inventory->getItem(args[0]);

    if (!item) {
        cout << "You don't have '" << args[0] << "'." << endl;
        return false;
    }
    else {
#ifdef DEBUG
        cout << "The object " << args[0] << " is specified correctly." << endl;
#endif
    }

    if (inventory->dropItem(item)) {
        room->addObj(item);
        cout << "You threw away the " << item->getName() << endl;
        return true;
    }
    else {
        cout << "Something went wrong." << endl;
        return false;
    }
}
