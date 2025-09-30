#include <iostream>
using namespace std;

const string COFFEE_MSG = "Welcome! Choose your desired drink: "
                          "1 - espresso, 2 - cappuccino, "
                          "3 - latte, 4 - tea, 5 - hot chocolate: ";

const string SIZE_MSG = "Choose the size of the drink: S - small, M - medium, L - large: ";
const string ESPRESSO_MSG = "The drink will be of size S.";
const string ADDITIVES_MSG = "Would you like to add something to the drink? "
                            "(1 - nothing, 2 - milk, 3 - syrup, 4 - cream): ";

const string COFFEE_ERROR_MSG = "The drink was chosen incorrectly! "
                            "You're going to have an espresso, I've decided.";
const string ADDITIVE_ERROR_MSG = "The supplement was selected incorrectly! You've clearly loose, go away lol.";

const string RECEIPT_MSG[] = { "Drink: ", "Size: ", "Additive: ", "Total price: " };

const string DRINKS[] = { "Espresso", "Cappuccino", "Latte", "Tea", "Hot Chocolate" };
const string ADDITIVES[] = { "Nothing", "Milk", "Syrup", "Cream" };
const string SIZES[] = { "Small", "Medium", "Large" };

enum Drink { ESPRESSO, CAPPUCCINO, LATTE, TEA, HOT_CHOCOLATE };
enum Additive { NOTHING, MILK, SYRUP, CREAM };
enum Size { SMALL, MEDIUM, LARGE };

const int COFFEE_PRICES[] = { 50, 80, 100, 60, 90 };
const float SIZE_MULTIPLIERS[] = { 1.0f, 1.3f, 1.5f };
const int ADDITIVE_PRICES[] = { 0, 10, 15, 20 };


bool getChoice() {
    char choice;

    do {
        cout << "Wanna continue? (y/n): ";
        cin >> choice;
        choice = tolower(choice);
    } while (choice != 'y' && choice != 'n');

    cout << endl;
    return (choice == 'y');
}


int main() {
    Drink drink;
    Size size;
    Additive additive;
    int drinkInp, additiveInp, total;
    char sizeChar;

    do {
        cout << COFFEE_MSG;
        cin >> drinkInp;

        if (drinkInp < 1 || drinkInp > 5) {
            cout << COFFEE_ERROR_MSG << endl;
            drink = ESPRESSO;
        } else {
            drink = static_cast<Drink>(drinkInp - 1);
        }

        if (drink == ESPRESSO) {
            cout << ESPRESSO_MSG << endl;
            size = SMALL;
        } else {
            cout << SIZE_MSG;

            do {
                cin >> sizeChar;
                sizeChar = tolower(sizeChar);
            } while (sizeChar != 's' && sizeChar != 'm' && sizeChar != 'l');

            switch (sizeChar)
            {
                case 'm':
                    size = MEDIUM;
                    break;
                case 'l':
                    size = LARGE;
                    break;
                case 's':
                default:
                    size = SMALL;
                    break;
            }
        }

        cout << ADDITIVES_MSG;
        cin >> additiveInp;

        if (additiveInp < 1 || additiveInp > 4) {
            cout << ADDITIVE_ERROR_MSG << endl;
            continue;
        } else {
            additive = static_cast<Additive>(additiveInp - 1);
        }

        total = COFFEE_PRICES[drink] * SIZE_MULTIPLIERS[size] + ADDITIVE_PRICES[additive];

        cout << endl << RECEIPT_MSG[0] << DRINKS[drink] << endl
            << RECEIPT_MSG[1] << SIZES[size] << endl
            << RECEIPT_MSG[2] << ADDITIVES[additive] << endl
            << RECEIPT_MSG[3] << total << endl;

    } while (getChoice());

    return 0;
}