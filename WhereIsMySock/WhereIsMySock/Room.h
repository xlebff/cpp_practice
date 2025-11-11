#pragma once
#include <vector>
#include <string>
#include "Object.h"

class Room {
public:
	Room(const std::string& name, const std::string& desc,
		const std::vector<Object*>& objs);

	Object* findObject(const std::string& name);
	bool addObj(Object* item);
	bool removeObj(Object* item);

	std::string getName() const;
	std::string getDesc() const;
	std::vector<Object*> getObjs() const;

private:
	std::string name;
	std::string desc;
	std::vector<Object*> objs;
};
