#include <iostream>
#include "InspectCommand.h"

using namespace std;

InspectCommand::InspectCommand() : Command("inspect", "Inspect at an object or location") {}

bool InspectCommand::execute(const vector<string>& args) {
    Room* room = Player::getInstance()->getCurRoom();

    if (!validate(args)) {
        cout << "To use the inspect command, specify the name of the object." << endl;
        return false;
    }
    else;

    Object* target = room->findObject(args[0]);

    if (!target) {
        cout << "The inspecting object is not in this room." << endl;
        return false;
    }
    else;

    cout << "You examine the " << target->getName() << "." << endl
        << target->getDesc() << endl;

    return true;
}
