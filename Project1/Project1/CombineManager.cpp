#include "CombineManager.h"

using namespace std;

static void yarnWithCat(Item* item0, Item* item1) {
	Inventory* inventory = Inventory::getInstance();

	inventory->removeItem(item0);
	delete item0;
	inventory->removeItem(item1);
	delete item1;

	inventory->addItem(new Item("Coin on a string", 
		"A coin tied on a woolen thread. But why..?"));

	cout << "You tied a coin to a string... Why did you do that?" << endl;
}

static void screwdriver(Item* item0, Item* item1) {
	Inventory* inventory = Inventory::getInstance();

	inventory->removeItem(item0);
	inventory->removeItem(item1);
	inventory->addItem(new Item("Screwdriver", "A regular screwdriver with a blue stripe."));
	delete item0;
	delete item1;

	cout << "You've assembled a screwdriver!" << endl;
}

bool CombineManager::processCombine(Item* item0, Item* item1) {
	if ((*item0 == items.at(YARN) && *item1 == items.at(COIN))
		|| (*item0 == items.at(COIN) && (*item1 == items.at(YARN)))) {
		yarnWithCat(item0, item1);
	}
	else if ((*item0 == items.at(SCREWDRIVER_BASE) && *item1 == items.at(SCREWDRIVER_TIP))
		|| (*item1 == items.at(SCREWDRIVER_BASE) && *item0 == items.at(SCREWDRIVER_TIP))) {
		screwdriver(item0, item1);
	}
	else return false;

	return true;
}