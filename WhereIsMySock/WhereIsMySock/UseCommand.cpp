#include <iostream>
#include "UseCommand.h"

using namespace std;

UseCommand::UseCommand() : Command("use", "Use an item on an object") { }

bool UseCommand::execute(const std::vector<std::string>& args) {
    if (!validate(args)) {
        cout << "Specify which object you want to use and on what." << endl;
        return false;
    }
    else;

    string item = args[0];
    string target = args[1];

    cout << "You`re using the " << item << " on the " << target << endl;



    return true;
}

bool UseCommand::validate(const vector<string>& args) {
    return args.size() >= 2;
}
