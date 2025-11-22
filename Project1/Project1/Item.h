#pragma once
#include <string>
#include "Object.h"

class Item : public Object {
public:
	Item(const std::string& name, 
		const std::string& desc = "",
		const bool detachable = true);

	bool isDetachable() const;

private:
	std::string name;
	std::string desc;
	bool detachable;
};
