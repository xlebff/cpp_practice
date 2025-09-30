#include <iostream>
using namespace std;

const string AMOUNT_MSG = "Welcome! How many items do you want to buy? ";
const string PRICE_MSG = "Enter the price of item: ";
const string BONUS_MSG = "Do you have our bonus card? (0/1): ";
const string WITHOUT_DISCOUNT_MSG = "Purchase price without discount: ";
const string DISCOUNT_MSG = "Your discount: ";
const string WITH_DISCOUNT_MSG = "The payment amount is ";
const string PAYMENT_MSG = "Please, pay for the purchase: ";
const string CHANGE_MSG = "Your change: ";
const string ERROR_MSG = "What do you mean..?";
const string NOT_ENOUGH = "That`s not enough..";

const double DISCOUNT_PRICE = 5000;

const double PRICE_DISCOUNT = 0.9;
const double BONUS_DISCOUNT = 0.95;

int main() {
    int count;
    double full = 0, total, given, discount, change, price;
    bool bonusCard;

    cout << AMOUNT_MSG;
    cin >> count;
    cout << endl;

    for (int i = 0; i < count; ++i) {
        cout << PRICE_MSG;
        cin >> price;

        if (price < 0) {
            cout << ERROR_MSG << endl;
            --i;
            continue;
        } else { ; }

        full += price;
    }

    cout << BONUS_MSG;
    cin >> bonusCard;

    if (full >= DISCOUNT_PRICE) {
        total = full * PRICE_DISCOUNT;
        cout << total;
    } else {
        total = full;
    }
    
    if (bonusCard) {
        total = full * BONUS_DISCOUNT;
    } else {
        total = full;
    }

    discount = full - total;

    cout << endl << WITHOUT_DISCOUNT_MSG << full << endl;
    cout << DISCOUNT_MSG << discount << endl;
    cout << WITH_DISCOUNT_MSG << total << endl;

    cout << PAYMENT_MSG;
    
    cin >> given;
    while (given < total) {
        cout << NOT_ENOUGH << endl;
        cin >> given;
    }

    change = given - total;

    if (change > 0) {
        cout << CHANGE_MSG << change << endl;
    } else ;

    return 0;
}