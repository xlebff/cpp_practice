#include "CombineManager.h"

using namespace std;

static void yarnWithCat(Item* item0, Item* item1) {
	Inventory* inventory = Inventory::getInstance();

	inventory->removeItem(item0);
	delete item0;
	inventory->removeItem(item1);
	delete item1;

	inventory->addItem(new Item("Coin on a string", "A coin tied on a woolen thread. But why..?"));
}

bool CombineManager::processCombine(Item* item0, Item* item1) {
	if ((*item0 == items.at(YARN) && *item1 == items.at(COIN))
		|| (*item0 == items.at(COIN) && (*item1 == items.at(YARN)))) {
		yarnWithCat(item0, item1);
		return true;
	}
	else return false;
}