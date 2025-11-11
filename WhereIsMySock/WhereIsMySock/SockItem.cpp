#include "SockItem.h"
#include <iostream>

using namespace std;

SockItem::SockItem(bool isMissing)
    : Item(isMissing ? "lonely_sock" : "sock",
        isMissing ? "Your favorite sock, waiting for its pair" : "A warm, comfortable sock",
        {}, {}, true) {
}

bool SockItem::useOn(Object* target, Player* player, Room* room) {
    if (target->getName() == "lonely_sock") {
        cout << "You reunite the pair of socks! Victory is yours!" << endl;
        player->completeGame();
        return true;
    }
    /* else if (target->getName() == "foot") {
        cout << "You put the sock on your foot. Much warmer!" << endl;
        return true;
    } */
    else {
        cout << "You can't use the sock on the " << target->getName() << "." << endl;
        return false;
    }
}