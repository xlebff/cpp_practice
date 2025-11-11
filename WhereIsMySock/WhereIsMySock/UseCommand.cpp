#include <iostream>
#include "UseCommand.h"

using namespace std;

UseCommand::UseCommand() : Command("use", "Use an item on an object") { }

bool UseCommand::execute(const std::vector<std::string>& args) {
    Player* player = Player::getInstance();
    Room* room = player->getCurRoom();
    Inventory* inventory = player->getInventory();
    
    if (!validate(args)) {
        cout << "Specify which object you want to use and on what." << endl;
#ifdef DEBUG
        cout << "Number of arguments: " << args.size() << endl;
#endif
        return false;
    }
    else;

    Item* item = inventory->getItem(args[0]);
    Object* target = room->findObject(args[1]);

    if (!item) {
        cout << "You don't have '" << args[0] << "'." << endl;
        return false;
    }
    else {
#ifdef DEBUG
        cout << "The item " << args[0] << " is specified correctly." << endl;
#endif
    }

    if (!target) {
        cout << "There is no '" << args[1] << "' here." << endl;
        return false;
    }
    else {
#ifdef DEBUG
        cout << "The object " << args[1] << " is specified correctly." << endl;
#endif
    }

    cout << "You`re using the " << item->getName() 
        << " on the " << target->getName() << endl;

    item->useOn(target, player, room);

    return true;
}

bool UseCommand::validate(const vector<string>& args) {
    return args.size() >= 2;
}
