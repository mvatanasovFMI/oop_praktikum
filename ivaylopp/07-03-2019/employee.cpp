// ConsoleApplication7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstring>
#include <iostream>

using namespace std;

class Employee
{
	int age;
	int salary;
	char name[50];
public:
	Employee();
	void enterDetails();
	void printDetails();
};

Employee::Employee()
{
	age = 0;
	salary = 320;
	strcpy_s(name, "NO_NAME");
}

void Employee::enterDetails()
{
	cout << "Name: ";
	cin.getline(name, 100);
	cout << "Age: ";
	cin >> age;
	cout << "Salary: ";
	cin >> salary;
	cin.ignore();
}

void Employee::printDetails()
{
	cout << "Name: " << name << "\nAge: " << age << "\nSalary: " << salary << endl;
}

int main()
{
	Employee a[10];
	int n = 3;
	for (int i = 1; i < n; i++)
		a[i].enterDetails();
	for (int i = 0; i < n; i++)
		a[i].printDetails();
	system("pause");
    return 0;
}
