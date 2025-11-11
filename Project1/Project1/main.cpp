#include <string>
#include "Facade.h"

using namespace std;

int main() {
    Facade* game = Facade::getInstance();
    game->showWelcome();

    string input;
    bool shouldQuit = false;

    while (!shouldQuit && getline(cin, input)) {
        shouldQuit = game->processInput(input);
    }

    return 0;
}