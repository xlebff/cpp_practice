#pragma once
#include <string>
#include <vector>
#include "Object.h"

class Item : public Object {
public:
	Item(const std::string& name, 
		const std::string& desc = "",
		const std::vector<Item*>& combineItems = {},
		const std::vector<Item*>& decombineItems = {},
		const bool detachable = true);

	bool isDetachable() const;
	std::vector<Item*> getCombineItems() const;
	std::vector<Item*> getDecombineItems() const;

private:
	bool detachable;
	std::vector<Item*> combineItems;
	std::vector<Item*> decombineItems;
};
