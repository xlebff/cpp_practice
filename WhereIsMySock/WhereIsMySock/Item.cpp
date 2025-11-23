#include "Item.h"

using namespace std;

Item::Item(const string& name,
	const string& desc,
	const bool detachable) :
	Object(name, desc), detachable(detachable) {
}

bool Item::isDetachable() const { return detachable; }
