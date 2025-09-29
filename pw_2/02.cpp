/* В системе учёта результатов тестирования студент вводит: балл за основной тест (целое число от 0 до 100), 
выполнение дополнительных заданий (количество), наличие бонусного балла (есть или нет). Вывести итоговую оценку по критериям:
90–100 — "Отлично".
75–89 — "Хорошо".
60–74 — "Удовлетворительно".
Меньше 60 — "Неудовлетворительно".
Каждое выполненное доп.задание дает +3 к основному баллу (но итог не превышает 100). 
Бонусный балл дает +15 к основному баллу (но итог не превышает 100). Программа должна работать 
циклично до тех пор, пока пользователь не решит выйти из программы.
*/

#include <iostream>
using namespace std;

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
    string mainMsg = "Enter the score for the main test: ",
            additionaltMsg = "Enter the number of completed additional tasks: ",
            bonusMsg = "Do you have a bonus point? (y/n): ",
            finalMsg = "Your final score: ",
            errorMsg = "Wrong data.";

    int main, additional;
    char choice;

    do {
        if (main < 0) {
            errorMsg
        }
        choice = getChoice();
    } while (choice != 'n');

    return 0;
}