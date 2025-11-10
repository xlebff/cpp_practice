#pragma once
#include <vector>
#include "Item.h"
#include "Room.h"

class Inventory {
public:
	Inventory(int capacity);
	const int getCapacity();
	const std::vector<Item*> getItems();
	bool takeItem(Item* item);
	bool dropItem(Item* item, Room* room);
	bool dropAllItems();

private:
	const int capacity;
	std::vector<Item*> items;
};
