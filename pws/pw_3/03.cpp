/* Реализуйте шифр Цезаря для следующего преобразования текста: 
каждая буква исходного текста заменяется буквой, стоящей на x символов впереди неё. 
Будем полагать что алфавит зацикленный, т.е. после буквы z идет буква a.
Шифр Цезаря — это вид шифра подстановки, в котором каждый символ в 
открытом тексте заменяется символом, находящимся на некотором постоянном 
числе позиций левее или правее него в алфавите. Пользователь вводит строку и сдвиг.
Например, вот, как будет выглядеть шифр Цезаря со сдвигом на 3:
A заменяется на D
B заменяется на E
и так далее
Z заменяется на C
*/

#include <iostream>
#include <string>
#include "continuation.h"
#include "inputError.h"
#include "consts.h"
using namespace ErrorMsg;
using namespace std;

const int CAPACITY = 1000;
const int LETTERS = 26;

const string START_MSG = "Enter your string: ";
const string SHIFT_MSG = "Enter shift value: ";
const string RESULT_MSG = "Your string: "; 

int main() {
    do {
        char str[CAPACITY];
        int currentLength = 0;

        cout << START_MSG;
        cin.getline(str, CAPACITY);

        int shift = 0;
        do {
            cout << SHIFT_MSG;
            if (!(cin >> shift)) errorClear();
            else if (shift <= 0) cout << ERROR_NEGOTIVE_MSG << endl;
            else break;
            shift = 0;
        } while (!shift);

        for (; str[currentLength]; ++currentLength);

        for (int i = 0; i < currentLength; ++i) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                str[i] += shift;
                if (str[i] > 'Z') str[i] -= LETTERS;
                else continue;
            } else if (str[i] >= 'a' && str[i] <= 'z') {
                str[i] += shift;
                if (str[i] > 'z') str[i] -= LETTERS;
                else continue;
            } else continue;
        }

        cout << RESULT_MSG;
        for (int i = 0; i < currentLength; ++i) cout << str[i];
        cout << endl << endl;
    } while (getChoice());

    return 0;
}