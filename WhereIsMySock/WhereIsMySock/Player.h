#pragma once
#include "Room.h"
#include "Inventory.h"

class Player {
public:
	static Player* getInstance();
	Room* getCurRoom() const;
	Inventory* getInventory() const;
	void setRoom(Room* room);
	void completeGame();

private:
	static Player* instance;
	Inventory* inventory;
	Room* curRoom;
};

