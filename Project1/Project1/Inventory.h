#pragma once
#include <vector>
#include "Item.h"

class Inventory {
public:
	Inventory(const int capacity = 5);

	static Inventory* getInstance();

	int getCapacity() const;
	std::vector<Item*> getItems() const;

	bool addItem(Item* item);
	bool removeItem(Item* item);
	bool clearItems();

	Item* getItem(const std::string& name) const;

	void display();

private:
	static Inventory* instance;
	const int capacity;
	std::vector<Item*> items;
};

