#include "Room.h"
#include <algorithm>

using namespace std;

// Инициализация статических переменных
vector<Room*> Room::allRooms;
vector<bool> Room::availableRooms;

Room::Room(const std::string& name, const std::string& desc,
    const bool available, const std::vector<Object*>& objs) :
    name(name), desc(desc), objs(objs) {
    allRooms.push_back(this);
    availableRooms.push_back(available);
}

Object* Room::findObject(const std::string& name) {
    for (Object* obj : objs) {
        if (obj->getName() == name) return obj;
    }
    return nullptr;
}

bool Room::addObj(Object* item) {
    if (item == nullptr) return false;

    objs.push_back(item);
    return true;
}

bool Room::addObjs(vector<Object*>& items) {
    /*for (Item* item : items) objs.push_back(item);
    return true;*/

    return true;
}

bool Room::removeObj(Object* item) {
    if (item == nullptr) return false;

    for (vector<Object*>::iterator it = objs.begin(); it != objs.end(); ++it) {
        if (*it == item) {
            objs.erase(it);
            return true;
        }
    }

    return false;
}

bool Room::removeObj(const string& name) {
    auto it = find_if(objs.begin(), objs.end(),
        [&name](Object* obj) {
            return obj->getName() == name;
        });

    if (it != objs.end()) {
        objs.erase(it);
        return true;
    }

    return false;
}

Room* Room::getRoom(const std::string& name) {
    for (Room* room : allRooms) {
        if (room->getName() == name) return room;
    }
    return nullptr;
}

string Room::getName() const { return name; }

string Room::getDesc() const { return desc; }

vector<Object*> Room::getObjs() const { return objs; }

vector<Room*> Room::getAllRooms() { return allRooms; }

// Добавленные методы:

vector<bool> Room::getAvailableRooms() {
    return availableRooms;
}

// Дополнительные полезные методы:

bool Room::setAvailability(const std::string& roomName, bool available) {
    for (size_t i = 0; i < allRooms.size(); ++i) {
        if (allRooms[i]->getName() == roomName) {
            availableRooms[i] = available;
            return true;
        }
    }
    return false;
}

bool Room::isAvailable(const std::string& roomName) {
    for (size_t i = 0; i < allRooms.size(); ++i) {
        if (allRooms[i]->getName() == roomName) {
            return availableRooms[i];
        }
    }
    return false;
}

// Очистка статических данных (опционально, для предотвращения утечек памяти)
void Room::cleanup() {
    allRooms.clear();
    availableRooms.clear();
}