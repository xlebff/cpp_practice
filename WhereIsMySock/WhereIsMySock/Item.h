#pragma once

class Item {
public:
	Item(char* name, char* desc, Item* mergeWith, Item* subItems);
	const char* getName();
	const char* getDesc();
	const Item* getSubItems();
	const Item* getMergeWith();

private:
	char* name;
	char* desc;

	int mergeWithCount;
	Item* mergeWith;

	int subItemsCount;
	Item* subItems;
};
