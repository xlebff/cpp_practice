#include <iostream>
using namespace std;

int main() {
    double rent;
    cout << "Enter the rent price: ";
    cin >> rent;
    
    if (rent <= 0) {
        cout << "The rent price is incorrect." << endl;
        return 2;
    }

    double shawarma;
    cout << "Enter the cost of the shawarma: ";
    cin >> shawarma;

    if (shawarma < 0) {
        cout << "The price of shawarma is incorrect." << endl;
        return 1;
    }

    if (shawarma == 0) {
        cout << "Mikhail doesn't work for free!" << endl;
        return 1;
    }

    float sales;
    cout << "Enter the average number of sales: ";
    cin >> sales;

    if (sales <= 0) {
        cout << "The average number of sales is incorrect." << endl;
        return 3;
    }

    double sum = 0;
    int duration = 30;

    int counter = 0;
    while (sum < rent) {
        counter++;
        sum += sales * shawarma;
    }

    if (counter < duration) {
        cout << "Mikhail will have time to pay the rent.";
    } else {
        cout << "Mikhail won't have time to pay the rent. There will be " << counter - duration << " days left." << endl;
    }
}