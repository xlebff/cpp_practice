#include "Command.h"

using namespace std;

Command::Command(const string& name, const string& desc) : name(name), desc(desc) {}

bool Command::validate(const vector<string>& args) { return !args.empty(); }

string Command::getName() const { return name; }

string Command::getDescription() const { return desc; }
