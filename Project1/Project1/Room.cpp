#include <algorithm>
#include "Room.h"
#include "Item.h"

using namespace std;

Room* Room::currentRoom;
vector<Room*> Room::allRooms;
vector<bool> Room::availableRooms;

enum roomIndexes { BEDROOM, LIVINGROOM, KITCHEN, BATHROOM, BALCONY };
const int roomsCount = 5;

const vector<vector<bool>> availableForEachRoom = {
    { false, true, false, false, true },
    { true, false, true, true, false },
    { false, true, false, true, false },
    { false, true, true, false, false },
    { true, false, false, false, false }
};

Room::Room(const string& name,
    const string& desc,
    const vector<Object*> objs,
    const bool available) :
    name(name), desc(desc), objs(objs) {
    allRooms.push_back(this);
    availableRooms.push_back(available);
    index = allRooms.size() - 1;
}

Room::~Room() {
    for (Object* obj : objs)
        delete obj;
    objs.clear();
}

Object* Room::findObject(const string& objName) {
    for (Object* obj : objs) {
        if (*obj == objName) return obj;
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

void Room::initializeRooms() {
    allRooms = {
        new Room("Bedroom", 
            "Your cozy bedroom. There's a bed, a wardrobe, and a nightstand.", 
            {
                new Object("Cat", "A fluffy ginger cat named Vasya is lazily stretching on the floor."),
                new Object("Bed", "A neatly made single bed with a blue comforter. It looks comfortable and inviting."),
                new Object("Nightstand", "A small wooden nightstand with a drawer. There's a lamp and an alarm clock on top."),
                new Item("Pencil", "A standard yellow pencil with a sharp tip."),
                new Item("Lamp", "A new, unpacked light bulb."),
                new Item("Phone", "Your smartphone. The battery is at 25%."),
                new Object("Wardrobe", "A tall wooden wardrobe with two doors. It seems to contain your clothes and other personal items.")
            },
            true),

        new Room("Livingroom", 
            "A comfortable living room with a sofa, TV, and coffee table.", 
            {
                new Object("Sofa", "A comfortable-looking sofa with soft cushions. Perfect for relaxing after a long day."),
                new Item("Note",
                    "You unfold the note and read: \"Dear roommate, I borrowed your sock for a art project. Check the balcony! - Cat Vasya\""),
                new Item("Coin", "A shiny gold coin. It looks quite ordinary."),
                new Item("Sports sock", "A clean white sports sock with blue stripes at the top.")
            }, 
            true),

        new Room("Kitchen", 
            "A clean kitchen with appliances and a dining table.", 
            {
                new Object("Kitchen table", "A simple wooden kitchen table with a clean surface. A fruit bowl sits in the center."),
                new Object("Sink", "A stainless steel kitchen sink. It's clean and dry, with a faucet that looks relatively new."),
                new Item("Glass of water", "A full glass of clear, fresh water."),
                new Object("Flower", "A disgruntled flower... The soil is completely dry!")
            }),

        new Room("Bathroom", "A dark bathroom. The light bulb burned out yesterday, so you can't see anything."),

        new Room("Balcony", 
            "A balcony with a nice view of the street.", 
            {
                new Object("Clothesline", 
                    "A drying clothesline stretched across the balcony. A single striped sock hangs from it, swaying gently in the breeze."),
                new Object("Trash bin", "A plastic trash bin in the corner. It's mostly empty with just some crumpled papers inside."),
            }, 
            false)
    };

    setCurrentRoom(getRoom("Bedroom"));
}

void Room::cleanup() {
    for (Room* room : allRooms)
        delete room;

    allRooms.clear();
    availableRooms.clear();
    currentRoom = nullptr;
}

Room* Room::getCurrentRoom() { return currentRoom; }

void Room::setCurrentRoom(Room* room) { 
    currentRoom = room;
    availableRooms = availableForEachRoom[room->getIndex()];
}

Room* Room::getRoom(const string& name) {
    for (size_t i = 0; i < allRooms.size(); ++i) {
        if (*allRooms[i] == name) return allRooms[i];
        else continue;
    }

    return nullptr;
}

bool Room::setAvailability(const string& roomName, bool available) {
    for (size_t i = 0; i < allRooms.size(); ++i) {
        if (*allRooms[i] == roomName) {
            availableRooms[i] = available;
            return true;
        }
        else continue;
    }

    return false;
}

bool Room::isAvailable(const std::string& roomName) {
    for (size_t i = 0; i < allRooms.size(); ++i) {
        if (*allRooms[i] == roomName) return availableRooms[i];
        else continue;
    }

    return false;
}

int Room::getIndex() const { return index; }

string Room::getName() const { return name; }

string Room::getDesc() const { return desc; }

void Room::setDesc(string newDesc) { desc = newDesc; }
void Room::setDesc(const char* newDesc) { desc = newDesc; }

vector<Object*> Room::getObjs() const { return objs; }

vector<Room*> Room::getAllRooms() { return allRooms; }

vector<bool> Room::getAvailableRooms() { return availableRooms; }

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

bool Room::operator==(const string other) const { return (name == other); }
