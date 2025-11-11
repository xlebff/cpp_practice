#include <iostream>
#include "YarnItem.h"

using namespace std;

YarnItem::YarnItem()
    : Item("yarn", "A ball of colorful yarn", {}, {}, true) {
}

bool YarnItem::useOn(Object* target, Player* player, Room* room) {
    if (target->getName() == "cat") {
        cout << "The cat immediately starts playing with the yarn! "
            << "He's completely distracted." << endl;
        room->removeObj(target);
        return true;
    }
    else if (target->getName() == "sofa") {
        cout << "You find a loose thread on the sofa and tie it with the yarn." << endl;
        return true;
    }
    else {
        cout << "The yarn has no effect on the " << target->getName() << "." << endl;
        return false;
    }
}