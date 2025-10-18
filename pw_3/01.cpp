/* Разработать программу для управления списком задач. 
Изначально список пустой. Каждая задача идентифицируется уникальным числовым ID, 
хранить описание задач не нужно. Пользователь может добавлять новые задачи, 
удалять существующие задачи и просматривать весь список.*/

#include <iostream>
#include "array.h"
#include "continuation.h"
#include "consts.h"
using namespace ErrorMsg;
using namespace RelatedMsg;
using namespace std;

const int MIN_CAPACITY = 5;

const string MENU_MSG = 
    "=== Task Manager ===\n"
    "1. Add task\n"
    "2. Remove task\n"
    "3. Show all tasks\n"
    "4. Exit\n"
    "Choose option: ";

const string ADD_VALUE_MSG = "Enter the ID of new task: ";
const string REMOVE_VALUE_MSG = "Enter the ID of task to remove: ";
const string OPERATION_COMPLETED_MSG = "The operation is completed!";
const string SHOW_TASKS_MSG = "Your tasks: ";

enum OPTIONS { ADD_TASK = 1, REMOVE_TASK, SHOW_ALL_TASKS, EXIT };

int main() {
    int capacity = MIN_CAPACITY;
    int *taskList = new int[capacity];
    
    clearArray(taskList, capacity);

    cout << endl;

    do {
        int option = 0;
        do {
            cout << MENU_MSG;
            int tmp;

            if (!(cin >> tmp)) errorClear();
            else if (tmp < ADD_TASK || tmp > EXIT) cout << ERROR_INCORRECT_RANGE_MSG << ADD_TASK << AND << EXIT << endl;
            else option = tmp;
        } while (!option);

        cout << endl;

        switch (option) {
            case ADD_TASK:
                capacity = addUniqValue(ADD_VALUE_MSG, taskList, capacity);
                cout << OPERATION_COMPLETED_MSG << endl;
                break;
            case REMOVE_TASK:
                removeValue(REMOVE_VALUE_MSG, taskList, capacity);
                cout << OPERATION_COMPLETED_MSG << endl;
                break;
            case SHOW_ALL_TASKS:
                cout << SHOW_TASKS_MSG;
                printExceptValue(taskList, capacity, 0);
                cout << endl;
                break;
            case EXIT:
                delete[] taskList;
                return 0;
            default:
                cout << ERROR_INCORRECT_RANGE_MSG << ADD_TASK << AND << EXIT;
                break;
        }

        cout << endl;

    } while (getChoice());

    delete[] taskList;
    return 0;
}