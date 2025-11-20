#pragma once
#include <string>
#include <vector>

class Object {
public:
    Object(const std::string& name, const std::string& desc);

    virtual ~Object() = default;

    std::string getName() const;
    std::string getDesc() const;

    void setDesc(const std::string& newDesc);
    void setDesc(const char* newDesc);

    bool operator==(const std::string other);

private:
    std::string name;
    std::string desc;
};
