#include <iostream>
#include <string>
#include "cinHandler.h"
#include "continuation.h"
#include "myMath.h"
#include "consts.h"

using namespace std;


int main() {
    const char EXPRESSION_MSG[] = "Enter the expression (e.g., 5 + 3, 5!, ~5, 5 & 3): ";
    const char WRONG_EXPRESSION_MSG[] = "Wrong expression.";
    const char RESULT_MSG[] = "Result: ";

    float num1 = 0, num2 = 0;
    char sign;
    float result = 0;

    do {
        string input;

        cout << EXPRESSION_MSG;
        getline(cin, input);

        if (readExpression(input, num1, sign, num2)) {
            if (calculateExpression(num1, sign, num2, result)) {
                cout << RESULT_MSG << result << endl;
            }
            else {
                cout << WRONG_EXPRESSION_MSG << endl;
            }
        }
        else {
            cout << WRONG_EXPRESSION_MSG << endl;
        }
    } while (getChoice());

    return 0;
}