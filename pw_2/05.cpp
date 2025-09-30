#include <iostream>
#include <random>
using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 100);

    int random_number = dist(gen), user_number;
    cout << "The number is hidden." << endl;

    int maxAttempts = 10, currentAttemps = 0;
    cout << "You have " << maxAttempts << " attemps." << endl << endl;

    do {
        ++currentAttemps;

        cout << "Guess the number: ";
        cin >> user_number;

        if (user_number == random_number) break;
        
        cout << "Your number is " 
                << (user_number > random_number ? "greater" : "less") 
                << " then the hidden." << endl;

        cout << "There are " << attempts << " attemps left." << endl << endl;
    } while (attempts > 0);

    cout << "The number is guessed!" << endl;
}