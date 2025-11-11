#include <iostream>
#include "GoCommand.h"

using namespace std;

GoCommand::GoCommand() : Command("go", "Move to another location") { }

bool GoCommand::execute(const vector<string>& args) {
    if (!validate(args)) {
        cout << "Specify the room you want to go to." << endl;
        return false;
    }
    else;

    Room* room = Room::getRoom(args[0]);
    if (!room) {
        cout << "There is no such room." << endl;
        return false;
    }
    else {
        auto it = find(Room::getAllRooms().begin(), Room::getAllRooms().end(), room);
        int index = distance(Room::getAllRooms().begin(), it);
        bool available = Room::getAvailableRooms()[index];

        if (available) {
            cout << "You`re going to the " << room->getName() << endl
                << room->getDesc() << endl;
            Player::getInstance()->setRoom(room);
        }
        else {
            cout << "You cannot enter this room from here." << endl;
            // добавить вывод комнат, доступных для перемещения
        }
    }

    return true;
}
