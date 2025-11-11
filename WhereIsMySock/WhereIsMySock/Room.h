#pragma once
#include <vector>
#include <string>
#include "Object.h"
#include "Item.h"
#include "Player.h"

class Room {
public:
	Room(const std::string& name, const std::string& desc,
		const bool available, const std::vector<Object*>& objs);

	Object *findObject(const std::string& name);

	bool addObj(Object* item);
	bool addObjs(std::vector<Item*>& items);

	bool removeObj(Object* item);
	bool removeObj(const std::string& name);

	static Room* getRoom(const std::string& name);
	static bool setAvailability(const std::string& roomName, bool available);
	static bool isAvailable(const std::string& roomName);
	static void cleanup();

	std::string getName() const;
	std::string getDesc() const;
	std::vector<Object*> getObjs() const;
	static std::vector<Room*> getAllRooms();
	static std::vector<bool> getAvailableRooms();

private:
	std::string name;
	std::string desc;
	std::vector<Object*> objs;

	static std::vector<Room*> allRooms;
	static std::vector<bool> availableRooms;
};