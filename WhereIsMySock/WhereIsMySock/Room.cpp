#include "Room.h"

using namespace std;

Room::Room(const std::string& name, const std::string& desc,
	const std::vector<Object*>& objs) :
	name(name), desc(desc), objs(objs) { }

Object* Room::findObject(const std::string& name) {
    Object* target = nullptr;

    for (Object* obj : objs) {
        if (obj->getName() == name) return obj;
        else continue;
    }
}

bool Room::addObj(Object* item) {
	objs.push_back(item);
    return true;
}

bool Room::removeObj(Object* item) {

}

string Room::getName() const { return name; }

string Room::getDesc() const { return desc; }

vector<Object*> Room::getObjs() const { return objs; }
