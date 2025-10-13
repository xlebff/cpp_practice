#include <iostream>
#include "array.h"
using namespace std;

const string START_MSG = "Enter the number of visitors: ";
const string NOBODY_CAME = "But nobody came..";
const string ELEMENT = "Visitor ";
const string COLON = ": ";
const string UNIQ_MSG = "The number of unique visitors: ";

int main() {
    int visitors = getSize(START_MSG, 0, 100);
    int uniq = 0;

    if (!visitors) {
        cout << NOBODY_CAME;
        return 0;
    } else ;

    int *visitorsArray = new int[visitors];

    fillArray(ELEMENT, COLON, visitorsArray, visitors, 1, 100);

    for (int i = 0; i < visitors; ++i) {
        bool isUniq = true;

        for (int j = 0; j < i; ++j) {
            if (visitorsArray[i] == visitorsArray[j]) {
                isUniq = false;
                break;
            } else continue;
        }

        uniq += isUniq;
    }

    cout << UNIQ_MSG << uniq;

    delete[] visitorsArray;
    return 0;
}