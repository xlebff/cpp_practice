/* �������� ��������� ��� ������� ���������� ����� �����������. 
� �������� ���� ���������� � ������� ������ ������: ������������� ������ � ��������� ������. 
�� ������������� ������ � �������� �������� 15 �����������, ��� ������� �� ������� ���������� ���� ������. 
���������� ����������� �� ��������� ������ ���������� ���������� (��� ������� ����� ���������� ���� ������). 
��������� ������ ���������� � �������:
����� ���� ���������� ����� �� ����� ��� ���� �����������.
����� ��� ������ � ������� ������ ���������� ������� ������? (������� �����).
���������� ����������� � ���������� ���� �������� �� ���� ��������.
��� ��������� ����������� ������� ���������� ���, ��� �������� ���� ����������� ������������� ������ � ��������.
��������� ������ ���� ��������� �� ��� ���, ���� ������������ �� ����� �����. 
��������� ��������� �� 3 �����: main.cpp; .h, ��� ����� ���������� �������; .cpp, ��� ����� ����������� �������.*/

#include <iostream>
#include <string>
#include <format>
#include "cinHandler.h"
#include "array.h"
#include "continuation.h"

using namespace std;

int main() {
	const int FIX_EMPLOYEES_COUNT = 15;
	const int HOURS_OF_WORK = 160;

	const char EMPLOYEE_MSG[] = "Employee ";

	do {
		float fixEmployeesRate[FIX_EMPLOYEES_COUNT];

		cout << format("Fill out the fixed rates for {} employees.", FIX_EMPLOYEES_COUNT) << endl;
		fillArray(EMPLOYEE_MSG, fixEmployeesRate, FIX_EMPLOYEES_COUNT, 22440.0f, 1000000.0f);

		cout << endl;

		int hourlyEmployees;
		cout << "Enter the number of employees with hourly pay: ";
		getValue(hourlyEmployees, 0, 10000, "Enter the number of employees with hourly pay: ", "Error: Not a number.");

		float* hourlyEmployeesRate = new float[hourlyEmployees];

		cout << format("Fill out the hourly rate of {} employees.", hourlyEmployees);
		fillArray(EMPLOYEE_MSG, hourlyEmployeesRate, hourlyEmployees, 121.96f, 10000.0f);

		cout << endl;

		float fixEmployeesFund = getSum(fixEmployeesRate, FIX_EMPLOYEES_COUNT);
		float hourlyEmployeesFund = getSum(hourlyEmployeesRate, hourlyEmployees) * HOURS_OF_WORK;

		float salaryFund = fixEmployeesFund + hourlyEmployeesFund;
		cout << "Total salary fund: " << salaryFund << endl;

		cout << endl;

		if (fixEmployeesFund > hourlyEmployeesFund)
			cout << format("The {} fund required a larger budget ({}, {} more than the {} one).",
				"fixed", fixEmployeesFund, fixEmployeesFund - hourlyEmployeesFund, "hourly");
		else if (fixEmployeesFund < hourlyEmployeesFund)
			cout << format("The {} fund required a larger budget ({}, {} more than the {} one).",
				"hourly", hourlyEmployeesFund, hourlyEmployeesFund - fixEmployeesFund, "fixed");
		else cout << "The salaries of fixed and hourly workers are the same.";
		cout << endl;

		float averageSalaryRate = salaryFund / (FIX_EMPLOYEES_COUNT + hourlyEmployees);

		int coolEmployees = 0;

		for (int i = 0; i < FIX_EMPLOYEES_COUNT; ++i) coolEmployees += fixEmployeesRate[i] > averageSalaryRate;
		for (int i = 0; i < hourlyEmployees; ++i) coolEmployees += hourlyEmployeesRate[i] > averageSalaryRate;

		cout << endl << "The number of employees with earnings above the average throughout the company: " << coolEmployees << endl;

		float minFixEmployeeRate = getMinValue(fixEmployeesRate, FIX_EMPLOYEES_COUNT);

		int notCoolHourlyEmployees = 0;

		for (int i = 0; i < hourlyEmployees; ++i) notCoolHourlyEmployees += (hourlyEmployeesRate[i] * HOURS_OF_WORK) < minFixEmployeeRate;

		cout << endl << "The number of hourly employees whose salary is below the minimum fixed rate in the company: " << notCoolHourlyEmployees << endl;

		delete[] hourlyEmployeesRate;

	} while (getChoice());

	return 0;
}