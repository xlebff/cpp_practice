#pragma once
#include <vector>
#include "Item.h"

class Inventory {
public:
	Inventory(const int capacity = 5);

	~Inventory();
	static void cleanup();

	static Inventory* getInstance();

	int getCapacity() const;
	std::vector<Item*> getItems() const;

	bool addItem(Item* item);
	bool removeItem(const Item* item);
	bool clearItems();

	Item* getItem(const std::string& itemName) const;

	void display();

private:
	static Inventory* instance;
	const int capacity;
	std::vector<Item*> items;
};

