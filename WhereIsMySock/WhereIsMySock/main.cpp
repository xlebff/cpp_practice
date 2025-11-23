#include <string>
#include "Facade.h"

using namespace std;

int main() {
    Facade* game = Facade::getInstance();

    string input;
    bool running = true;

    while (running && getline(cin, input)) {
        running = game->processInput(input);
        if (running) cout << endl << ">  ";
        else continue;
    }

    game->quitGame();
    return 0;
}