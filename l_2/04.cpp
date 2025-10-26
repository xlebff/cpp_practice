#include <iostream>
using namespace std;

int main() {
    bool doorIsOpen, 
        windowIsOpen, 
        ownerAtHome;
    
    cout << "Is the door open? ";
    cin >> doorIsOpen;

    cout << "Is the window open? ";
    cin >> windowIsOpen;

    cout << "Is the owner at home? ";
    cin >> ownerAtHome;

    cout << endl << (((doorIsOpen || windowIsOpen) && !ownerAtHome) ? "The alarm will go off" : "The alarm won't work");
}