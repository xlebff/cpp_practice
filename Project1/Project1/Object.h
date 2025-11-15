#pragma once
#include <string>
#include <vector>

class Object {
public:
    Object(const std::string& name, const std::string& desc);

    std::string getName() const;
    std::string getDesc() const;

private:
    std::string name;
    std::string desc;
};