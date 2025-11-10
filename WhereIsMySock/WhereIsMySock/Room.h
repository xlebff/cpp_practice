#pragma once
#include <vector>
#include "Item.h"

class Room {
public:
	Room(char* name, char* desc, std::vector<Item*> items);
	const char* getName();
	const char* getDesc();
	const std::vector<Item*> getItems();
	bool addItem(Item* item);
	
private:
	char* name;
	char* desc;
	std::vector<Item*> items;
};
