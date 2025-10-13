#include <iostream>
using namespace std;

const int SIZE = 10;

const string START_MSG = "Product IDs: ";
const string REMOVE_MSG = "Enter the ID of the item being removed (enter -1 to stop): ";
const string END = "Finishing..";
const string REMOVED = " removed successfully.";
const string ELEMENT = "Product ";
const string COLON = ": ";

const int MAX_IGNORE_COUNT = 1000;
const char STOP_IGNORE_CHAR = '\n';

const string ERROR_CHAR_MSG = "Error: Not a number!";
const string ERROR_VALUE_MSG = "Error: Not found!";

int main() {
    int src[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    bool removed[SIZE] = {false};
    int removedCount = 0;

    cout << START_MSG << endl;
    for (int i = 0; i < SIZE; ++i) 
        cout << ELEMENT << i + 1 << COLON << src[i] << endl;
    
    int inputId;
    while (removedCount < SIZE) {
        cout << REMOVE_MSG;

        if (!(cin >> inputId)) {
            cin.clear();
            cin.ignore(MAX_IGNORE_COUNT, STOP_IGNORE_CHAR);
            cout << ERROR_CHAR_MSG << endl;
            continue;
        } else ;

        if (inputId == -1) {
            cout << END << endl;
            break;
        } else ;

        bool found = false;
        for (int i = 0; i < SIZE; ++i) {
            if (!removed[i] && src[i] == inputId) {
                removed[i] = true;
                found = true;
                ++removedCount;
                cout << ELEMENT << inputId << REMOVED << endl;
                break;
            }
        }

        if (!found) {
            cout << ERROR_VALUE_MSG << endl;
        } else ;
    }

    int remainingCount = SIZE - removedCount;
    int *res = new int[remainingCount];
    int lastIndex = 0;
    
    for (int i = 0; i < SIZE; ++i) {
        if (!removed[i]) {
            res[lastIndex] = src[i];
            ++lastIndex;
        } else ;
    }

    for (int i = 0; i < remainingCount; ++i) 
        cout << ELEMENT << i + 1 << COLON << res[i] << endl;

    delete[] res;
    return 0;
}