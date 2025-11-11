#pragma once
#include <string>

class Object {
public:
    Object(const std::string& name, const std::string& desc);

    std::string getName() const;
    std::string getDesc() const;

protected:
    std::string name;
    std::string desc;
};

