/* Напишите рекурсивную функцию подсчета всех цифр в числе. */

#include <iostream>
using namespace std;

int getSum(int n) {
    if (n == 0) return 0;
    return (n % 10) + getSum(n / 10);
}

int main() {
    cout << (getSum(12)) << endl;
    return 0;
}