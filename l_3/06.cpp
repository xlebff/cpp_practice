#include <iostream>
using namespace std;

int main() {
    float price;
    cout << "Enter the purchase price: ";
    cin >> price;

    while (price <= 0) {
        cout << "Incorrect price. ";
        cin >> price;
    }

    string paymentMethods[3] {"cash", "card", "installment"};
    string payment;
    cout << "Choose a payment method (cash, card, installment): ";
    cin >> payment;

    while (payment != paymentMethods[0]
        && payment != paymentMethods[1]
        && payment != paymentMethods[2]) {
        cout << "The wrong payment method is selected! ";
        cin >> payment;
    }

    if (payment == paymentMethods[0]) cout << "The price has not changed";
    else if (payment == paymentMethods[1]) cout << "Your price is " << price * 0.9;
    else cout << "Your price is " << price * 1.2;
}