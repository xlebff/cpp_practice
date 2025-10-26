#include <iostream>
#include <string>
#include "cinHandler.h"

using namespace std;

const string EXPRESSION_MSG = "Enter the expression: ";

int main() {
	float num1 = 0, num2 = 0;
	char sign = 0;

	cout << EXPRESSION_MSG;

	getValue(num1);
	getValue(sign);
	getValue(num2);

	return 0;
}