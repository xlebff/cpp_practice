#include <iostream>
#include "array.h"
#include "cinHandler.h"
#include "consts.h"
#include "asking.h"

using namespace std;

int main() {
    const char INCOME_MSG[] = "Enter your income: ";
    const char EXPENSE_MSG_PREFIX[] = "Expense ";
    const char WANNA_ADD_EXPENSE_MSG[] = "Wanna add an expense? (y/n): ";
    const char HOW_MANY_EXPENSES_MSG[] = "How many? ";
    const char NECESSERY_EXPENSES_MSG[] = "The amount of necessery expenses: ";
    const char UNPLANNED_EXPENSES_MSG[] = "The amount of unplanned expenses: ";
    const char AVG_NECESSERY_EXPENSES_MSG[] = "Average necessery expenses: ";
    const char AVG_UNPLANNED_EXPENSES_MSG[] = "Average unplanned expenses: ";
    const char UNPLANNED_EXCEEDED_MSG[] = "Unplanned expenses exceeded the mandatory ones.";
    const char UNPLANNED_AVG_HIGHER_MSG[] = "The average value of unplanned expenses is ";
    const char CONGRATULATIONS_MSG[] = "Congratulations, you are not in debt!";
    const char REST_MONEY_MSG[] = "Rest of your money: ";
    const char MAX_ALLOWABLE_EXPENSES_MSG[] = "Maximum allowable unplanned expenses: ";

    const double MIN_INCOME = 22440;
    const double MAX_INCOME = 5000000000;
    const int MIN_EXPENSES = 1;
    const int MAX_EXPENSES = 20;

    const double UTILITIES = 5800,
        CHILDREN_ACTIVITIES = 6200,
        TRANSPORT = 4700,
        PRODUCTS = 10500,
        HOUSEHOLD_CHEMICALS = 5000,
        CONNECTION = 3600,
        CREDITS = 23700;
    const int NECESSERY_EXPENSES_COUNT = 7;

    double necesseryExpenses = UTILITIES + CHILDREN_ACTIVITIES
        + TRANSPORT + PRODUCTS + CREDITS
        + HOUSEHOLD_CHEMICALS + CONNECTION;

    do {
        cout << RelatedMsg::SEPARATOR << endl << endl;

        double income;
        getValue(income, MIN_INCOME, MAX_INCOME, INCOME_MSG);

        cout << endl;

        int unplannedExpensesCount = 0;
        if (getChoice(WANNA_ADD_EXPENSE_MSG)) {
            getValue(unplannedExpensesCount, MIN_EXPENSES, MAX_EXPENSES, HOW_MANY_EXPENSES_MSG);
        }
        else;
        double* unplannedExpenses = new double[unplannedExpensesCount];

        fillArray(EXPENSE_MSG_PREFIX, unplannedExpenses, unplannedExpensesCount, (double)1, (double)1000000);

        double unplannedExpensesSum = getSum(unplannedExpenses, unplannedExpensesCount);

        cout << endl;

        cout << NECESSERY_EXPENSES_MSG << necesseryExpenses << endl
            << UNPLANNED_EXPENSES_MSG << unplannedExpensesSum << endl;

        cout << endl;

        double necesseryExpensesAverage = necesseryExpenses / NECESSERY_EXPENSES_COUNT;
        double unplannedExpensesAverage = unplannedExpensesCount ?
            getAverage(unplannedExpenses, unplannedExpensesCount) :
            0;

        cout << AVG_NECESSERY_EXPENSES_MSG
            << necesseryExpensesAverage << endl
            << AVG_UNPLANNED_EXPENSES_MSG << unplannedExpensesAverage << endl;

        cout << endl;

        if (unplannedExpensesSum > necesseryExpenses) {
            cout << UNPLANNED_EXCEEDED_MSG << endl
                << UNPLANNED_AVG_HIGHER_MSG
                << (unplannedExpensesAverage - necesseryExpensesAverage) / necesseryExpensesAverage * 100
                << "% more than necessery." << endl;
        }
        else;

        double expenses = unplannedExpensesSum + necesseryExpenses;

        double rest = income - expenses;

        if (rest > 0) {
            cout << CONGRATULATIONS_MSG << endl;
        }
        else;

        cout << REST_MONEY_MSG << rest << endl;

        double saveExpenses = (income - necesseryExpenses) - (income / 10);

        cout << MAX_ALLOWABLE_EXPENSES_MSG << saveExpenses << endl;

        delete[] unplannedExpenses;

        cout << endl << RelatedMsg::SEPARATOR << endl;

    } while (getChoice());

    return 0;
}