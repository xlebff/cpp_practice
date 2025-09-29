#include <iostream>
using namespace std;

char getChoice() {
    char choice;

    do {
        cout << "Wanna receive the next visitor? (y/n): ";
        cin >> choice;
        choice = tolower(choice);
    } while (choice != 'y' && choice != 'n');

    cout << endl;
    return choice;
}

int main() {
    string helloMsg = "Hello! What`s your age? ",
            ticketMsg = "Cool! Enter your ticket type: ",
            welcomeMsg = "Welcome to the festival!",
            errorMsg = "Sorry, but the ticket doesn't match your age.",
            youngMsg = "Sorry! You`re too young.";

    int age, ticketType;
    char choice;

    do {
        cout << helloMsg;
        cin >> age;

        if (age <= 0) {
            cout << "Liar :(" << endl;
            choice = getChoice();
            continue;
        } else {
            if (age >= 5) {
                cout << ticketMsg;
                cin >> ticketType;

                if (((age >= 5 && age <= 12) && ticketType == 2) ||
                    ((age >= 13 && age <= 49) && (ticketType == 1 || ticketType == 4)) ||
                    ((age >= 50 && age <= 64) && (ticketType != 2)) ||
                    ((age >= 65) && (ticketType == 3 || ticketType == 4))) {
                    cout << welcomeMsg << endl;
                } else {
                    cout << errorMsg << endl;
                }
            } else {
                cout << youngMsg << endl;
            }

            choice = getChoice();
        }
    } while (choice != 'n');

    return 0;
}