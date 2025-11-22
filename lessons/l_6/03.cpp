#include <iostream>
using namespace std;

int main() {
    int duration = 30;
    double percent = 1.05;

    double startBalance;
    cout << "Enter yout balance: ";
    cin >> startBalance;

    double targetBalance;
    cout << "Enter your target balance: ";
    cin >> targetBalance;

    if (startBalance > targetBalance) {
        cout << "Incorrect data.";
        return 1;
    }

    if (startBalance == targetBalance) {
        cout << "The desired amount has already been accumulated.";
        return 0;
    }

    int counter = 0;
    while (startBalance < targetBalance) {
        counter++;
        startBalance *= percent;
    }

    if (counter <= duration) {
        cout << "The amount will be accumulated on time.";
    } else {
        cout << "The amount will not be accumulated. It will take " << counter 
            << " days in total (" << counter - duration << " more)." << endl;
    }
}