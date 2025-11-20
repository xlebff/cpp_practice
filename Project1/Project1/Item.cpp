#include "Item.h"

using namespace std;

Item::Item(const string& name,
	const string& desc,
	const vector<Item*>& combineItems,
	const vector<Item*>& decombineItems,
	const bool detachable) :
	Object(name, desc), combineItems(combineItems),
	decombineItems(decombineItems), detachable(detachable) {
}

bool Item::isDetachable() const { return detachable; }
vector<Item*> Item::getCombineItems() const { return combineItems; }
vector<Item*> Item::getDecombineItems() const { return decombineItems; }
