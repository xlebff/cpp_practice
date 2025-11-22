#include <iostream>
#include <string>
using namespace std;

const string mainMsg = "Enter the score for the main test: ",
            additionaltMsg = "Enter the number of completed additional tasks: ",
            bonusMsg = "Do you have a bonus point? (0/1): ",
            finalMsg = "Your final score: ",
            errorMsg = "Wrong data.",
            infoMsg = "You have ",
            badMsg = ". Unsatisfactory..",
            notbadMsg = ". Satisfactory.",
            niceMsg = ". Nice!",
            greatMsg = ". Great!";

char getChoice() {
    char choice;

    do {
        cout << "Wanna continue? (y/n): ";
        cin >> choice;
        choice = tolower(choice);
    } while (choice != 'y' && choice != 'n');

    cout << endl;
    return choice;
}

int main() {
    int main, additional, total;
    bool bonus;
    char choice;

    do {
        cout << mainMsg;
        cin >> main;

        cout << additionaltMsg;
        cin >> additional;

        if ((main < 0 || main > 100) || (additional < 0)) {
            cout << errorMsg;
            choice = getChoice();
            continue;
        } else continue;

        cout << bonusMsg;
        cin >> bonus;

        total = main + (additional * 3) + (bonus ? 15 : 0);
        if (total > 100) {
            total = 100;
        }

        if (total < 60) {
            cout << infoMsg << total << badMsg << endl;
        } else if (total <= 75) {
            cout << infoMsg << total << notbadMsg << endl;
        } else if (total <= 89) {
            cout << infoMsg << total << niceMsg << endl;
        } else {
            cout << infoMsg << total << greatMsg << endl;
        }

        choice = getChoice();
    } while (choice != 'n');

    return 0;
}