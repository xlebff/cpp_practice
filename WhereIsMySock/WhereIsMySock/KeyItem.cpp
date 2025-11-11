/* #include <iostream>
#include "KeyItem.h"

using namespace std;

KeyItem::KeyItem()
    : Item("key", "A rusty old key", {}, {}, true) { }

bool KeyItem::useOn(Object* target, Player* player, Room* room) {
    if (target->getName() == "door") {
        cout << "The key fits perfectly! The door unlocks with a satisfying click." << endl;
         room->unlockDoor();
        return true;
    }
    cout << "The key doesn't fit the " << target->getName() << "." << endl;
    return false;
}
*/