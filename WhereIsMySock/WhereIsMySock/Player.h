#pragma once
#include "Room.h"

class Player {
public:
	static Player* getInstance();
	Room* getCurRoom() const;
	void setRoom(Room* room);

private:
	static Player* instance;
	Room* curRoom;
};

