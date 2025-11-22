#include <iostream>
#include <random>
using namespace std;

const string START_MSG = "The number is hidden.";
const string GUESS_MSG = "Guess the number: ";
const string GUESSED_MSG = "The number is guessed! The count of attemps: ";
const string ERROR_MSG = "The number must be more then 0 and less then 20!";

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 20);

    int random_number = dist(gen), user_number;
    cout << START_MSG << endl;

    int maxAttempts = 10, currentAttemps = 0;
    cout << "You have " << maxAttempts << " attemps." << endl << endl;

    do {
        cout << GUESS_MSG;
        cin >> user_number;

        if (user_number == random_number) {
            ++currentAttemps;
            cout << GUESSED_MSG << currentAttemps << endl;
            return 0;
        }
        else if (user_number < 1 || user_number > 20) {
            cout << ERROR_MSG << endl;
            continue;
        }
        else {
            ++currentAttemps;

            cout << "Your number is " 
                    << (user_number > random_number ? "greater" : "less") 
                    << " then the hidden." << endl;

            cout << "There are " << maxAttempts - currentAttemps << " attemps left." << endl << endl;
        }
    } while (currentAttemps < maxAttempts);

    return 0;
}