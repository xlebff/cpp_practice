#include <iostream>
using namespace std;

int main() {
    float temp;
    bool ownerAtHome;
    
    cout << "What is the temperature outside now? ";
    cin >> temp;

    cout << "Is the owner at home? ";
    cin >> ownerAtHome;

    cout << endl << ((((temp < 18.0) && !ownerAtHome) || (temp < 10.0)) ?
                    "The heating should turn on"
                    : "The heating should not turn on");
}