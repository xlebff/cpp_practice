/* Разработать программу для управления списком задач. 
Изначально список пустой. Каждая задача идентифицируется уникальным числовым ID, 
хранить описание задач не нужно. Пользователь может добавлять новые задачи, 
удалять существующие задачи и просматривать весь список.*/

#include <iostream>
#include "array.h"
#include "continuation.h"
using namespace std;

const int MIN_CAPACITY = 5;
const string MENU_MSG = 
    "=== Task Manager ===\n"
    "1. Add task\n"
    "2. Remove task\n"
    "3. Show all tasks\n"
    "4. Exit\n"
    "Choose option: ";

int main() {
    int *taskList = new int[MIN_CAPACITY];

    do {

    } while (getChoice());

    return 0;
}