#include <algorithm>
#include "Room.h"
#include <iostream>

using namespace std;

Room* Room::currentRoom;
vector<Room*> Room::allRooms;
vector<bool> Room::availableRooms;

Room::Room(const std::string& name,
    const std::string& desc,
    const bool available,
    const std::vector<Object*>&) :
    name(name), desc(desc), objs(objs) {
    allRooms.push_back(this);
    availableRooms.push_back(available);
}

Object* Room::findObject(const std::string& name) {
    for (Object* obj : objs) {
        if (obj->getName() == name) return obj;
        else continue;
    }

    return nullptr;
}

bool Room::addObj(Object* item) {
    if (item == nullptr) return false;
    else {
        objs.push_back(item);
        return true;
    }
}

/* bool Room::addObjs(vector<Object*>& items) {
    for (Item* item : items) objs.push_back(item);
    return true;

return true;
} */

bool Room::removeObj(Object* item) {
    if (item == nullptr) return false;
    else {
        for (vector<Object*>::iterator it = objs.begin(); it != objs.end(); ++it) {
            if (*it == item) {
                objs.erase(it);
                return true;
            }
            else continue;
        }

        return false;
    }
}

/* bool Room::removeObj(const string& name) {
    auto it = find_if(objs.begin(), objs.end(),
        [&name](Object* obj) {
            return obj->getName() == name;
        });

    if (it != objs.end()) {
        objs.erase(it);
        return true;
    }

    return false;
} */

void Room::initializeRooms() {
    allRooms = {
        new Room("bedroom",
                "Your cozy bedroom. There's a bed, a wardrobe, and a nightstand."),
        new Room("livingroom",
                "A comfortable living room with a sofa, TV, and coffee table."),
        new Room("kitchen",
                "A clean kitchen with appliances and a dining table."),
        new Room("bathroom",
                "A small bathroom with a sink, toilet, and shower."),
        new Room("balcony",
                "A balcony with a nice view of the street.")
    };

    availableRooms = { true, true, false, false, false };
    currentRoom = getRoom("bedroom");
}

Room* Room::getCurrentRoom() { return currentRoom; }

void Room::setCurrentRoom(Room* room) { currentRoom = room; }

Room* Room::getRoom(const string& name) {
    for (size_t i = 0; i < allRooms.size(); ++i) {
        if (allRooms[i]->getName() == name) return allRooms[i];
        else continue;
    }

    return nullptr;
}

bool Room::setAvailability(const string& roomName, bool available) {
    for (size_t i = 0; i < allRooms.size(); ++i) {
        if (allRooms[i]->getName() == roomName) {
            availableRooms[i] = available;
            return true;
        }
        else continue;
    }

    return false;
}

bool Room::isAvailable(const std::string& roomName) {
    for (size_t i = 0; i < allRooms.size(); ++i) {
        if (allRooms[i]->getName() == roomName) {
            return availableRooms[i];
        }
        else continue;
    }

    return false;
}

string Room::getName() const { return name; }

string Room::getDesc() const { return desc; }

vector<Object*> Room::getObjs() const { return objs; }

vector<Room*> Room::getAllRooms() { return allRooms; }

vector<bool> Room::getAvailableRooms() {
    return availableRooms;
}

vector<string> Room::getAvailableRoomsNames() {
    vector<string> names = {};

    for (size_t i = 0; i < allRooms.size(); ++i) {
        if (availableRooms[i]) {
            names.push_back(allRooms[i]->getName());
        }
        else continue;
    }

    return names;
}
