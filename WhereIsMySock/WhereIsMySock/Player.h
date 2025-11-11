#pragma once

class Room;
class Inventory;

class Player {
public:
	static Player* getInstance();
	Room* getCurRoom() const;
	Inventory* getInventory() const;
	void setRoom(Room* room);
	void completeGame();

private:
	Player();
	static Player* instance;
	Room* curRoom;
	Inventory* inventory;
};