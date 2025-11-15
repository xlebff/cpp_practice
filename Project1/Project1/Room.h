#pragma once
#include <vector>
#include <string>
#include "Object.h"

class Room {
public:
	Room(const std::string& name,
		const std::string& desc = "",
		const std::vector<Object*> objs = {},
		const bool available = true);

	Object* findObject(const std::string& name);

	bool addObj(Object* item);
	bool removeObj(Object* item);

	static void initializeRooms();
	static Room* getCurrentRoom();
	static void setCurrentRoom(Room* room);

	static Room* getRoom(const std::string& objName);
	static bool setAvailability(const std::string& roomName, const bool available);
	static bool isAvailable(const std::string& roomName);

	int getIndex() const;
	std::string getName() const;
	std::string getDesc() const;
	std::vector<Object*> getObjs() const;

	static std::vector<Room*> getAllRooms();
	static std::vector<bool> getAvailableRooms();
	static std::vector<std::string> getAvailableRoomsNames();

private:
	int index;
	std::string name;
	std::string desc;
	std::vector<Object*> objs;

	static Room* currentRoom;
	static std::vector<Room*> allRooms;
	static std::vector<bool> availableRooms;
};
