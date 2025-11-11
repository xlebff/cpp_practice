#include "ScrewdriverItem.h"
#include <iostream>

using namespace std;

ScrewdriverItem::ScrewdriverItem()
    : Item("screwdriver", "A sturdy screwdriver", {}, {}, true) {
}

bool ScrewdriverItem::useOn(Object* target, Player* player, Room* room) {
    if (target->getName() == "lock") {
        cout << "You've opened a jammed door." << endl;
        // добавить в доступные комнаты балкон
        return true;
    }
    cout << "You can't use the screwdriver on the " << target->getName() << "." << endl;
    return false;
}
