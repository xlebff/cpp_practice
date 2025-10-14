/* Разработать программу для управления списком задач. 
Изначально список пустой. Каждая задача идентифицируется уникальным числовым ID, 
хранить описание задач не нужно. Пользователь может добавлять новые задачи, 
удалять существующие задачи и просматривать весь список.*/

#include <iostream>
#include "array.h"
#include "continuation.h"
using namespace std;

const string ERROR_MSG = "Error: The value must be between 1 and 4";

const int MIN_CAPACITY = 5;
const string MENU_MSG = 
    "=== Task Manager ===\n"
    "1. Add task\n"
    "2. Remove task\n"
    "3. Show all tasks\n"
    "4. Exit\n"
    "Choose option: ";
const string ADD_VALUE = "Enter the ID of new task: ";
const string OPERATION_COMPLETED = "The operation is completed!";
const string SHOW_TASKS = "Your tasks: ";

enum OPTIONS { ADD_TASK = 1, REMOVE_TASK, SHOW_ALL_TASKS, EXIT };

int main() {
    int *taskList = new int[MIN_CAPACITY];
    int size = MIN_CAPACITY;
    clearArray(taskList, size);

    cout << endl;

    do {
        int option = 0;
        do {
            cout << MENU_MSG;
            int tmp;

            if (!(cin >> tmp)) errorClear();
            else option = tmp;
        } while (!option);

        cout << endl;

        switch (option) {
            case ADD_TASK:
                size = addUniqValue(ADD_VALUE, taskList, size);
                cout << OPERATION_COMPLETED << endl << taskList + (size - 1) << endl << *(taskList + (size -1));
                break;
            case SHOW_ALL_TASKS:
                cout << SHOW_TASKS;
                printExeptValue(taskList, size, 0);
                break;
            default:
                cout << ERROR_MSG;
                break;
        }

        cout << endl;

    } while (getChoice());

    delete[] taskList;
    return 0;
}