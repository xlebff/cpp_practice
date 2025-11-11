#include "FlashlightItem.h"
#include <iostream>

using namespace std;

FlashlightItem::FlashlightItem()
    : Item("flashlight", 
        "A small but powerful flashlight", 
        {}, {}, true), isOn(false) { }

bool FlashlightItem::useOn(Object* target, Player* player, Room* room) {
    if (target->getName() == "dark_corner" || target->getName() == "under_bed") {
        if (!isOn) {
            cout << "You need to turn on the flashlight first!" << endl;
            return false;
        }
        else {
            cout << "You shine the flashlight and discover something hidden!" << endl;
            return true;
        }
    }
    else if (target->getName() == "flashlight" || target->getName() == "self") {
        toggle();
        return true;
    }
    else {
        cout << "You can't use the flashlight on the " << target->getName() << "." << endl;
        return false;
    }
}

void FlashlightItem::toggle() {
    isOn = !isOn;
    cout << "You turn the flashlight " << (isOn ? "on" : "off") << "." << endl;
}
