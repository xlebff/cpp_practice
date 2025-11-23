#include "Object.h"

using namespace std;

Object::Object(const string& name, const string& desc)
    : name(name), desc(desc) {
}

string Object::getName() const { return name; }
string Object::getDesc() const { return desc; }

void Object::setDesc(const string& newDesc) { desc = newDesc; }
void Object::setDesc(const char* newDesc) { desc = newDesc; }

bool Object::operator==(const std::string other) { return (name == other); }
