#include "Object.h"

using namespace std;

Object::Object(const string& name, const string& desc)
    : name(name), desc(desc) { }

string Object::getName() const { return name; }
string Object::getDesc() const { return desc; }
