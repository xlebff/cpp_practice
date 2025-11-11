#pragma once
#include <vector>
#include "Item.h"
#include "Room.h"

class Inventory {
public:
	Inventory(const int capacity);

	int getCapacity() const;
	std::vector<Item*> getItems() const;

	bool takeItem(Item* item);
	bool dropItem(Item* item);
	bool dropAllItems(Room* room);

	Item* getItem(const std::string& name) const;

	void show();

private:
	const int capacity;
	std::vector<Item*> items;
};
