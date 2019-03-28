#include "Person.h"
#include <iostream>
#include <cstring>
using namespace std;

void Person::Init(const char* pName, int age, float salary) {
	m_age = age;
	m_salary = salary;

	if (!pName)
	{
		delete[] m_pFullName;
		m_pFullName = NULL;
		return;
	}
	
	size_t BufferSize = strlen(pName) + 1;

	char* buffer = new char[BufferSize];
	delete[] m_pFullName;
	m_pFullName = buffer;
	// strcpy_s(m_pFullName, BufferSize, pName);
}

Person::~Person() {
	if (m_pFullName != NULL)
		delete[] m_pFullName;
}

void Person::SetFullName(const char* pName) {
	if (!pName)
	{
		delete[] m_pFullName;
		m_pFullName = NULL;
		return;
	}
	
	size_t BufferSize = strlen(pName) + 1;

	char* buffer = new char[BufferSize];
	delete[] m_pFullName;
	m_pFullName = buffer;
	strcpy_s(m_pFullName, BufferSize, pName);
}

void Person::SetAge(int age) {
	m_age = age;
}

void Person::SetSalary(float salary) {
	m_salary = salary;
}

char* Person::GetFullName() const {
	return m_pFullName;
}

int Person::GetAge() const {
	return m_age;
}

float Person::GetSalary() const {
	return m_salary;
}

void Person::Print() const {
	cout << "Name: " << m_pFullName << endl;
	cout << "Age: " << m_age << endl;
	cout << "Salary: " << m_salary << endl;
}

void Person::PrintMembersOffsetsAndSizeOf() const {
	cout << "FullName offset: " << offsetof(Person, m_pFullName) << endl;
	cout << "Age offset: " << offsetof(Person, m_age) << endl;
	cout << "Salary offset: " << offsetof(Person, m_salary) << endl;

	cout << "The size of this object: " << sizeof(this) << endl;
	cout << "The size of Person: " << sizeof(Person) << endl;
}


Person::Person() {
	m_pFullName = NULL;
	m_age = 0;
	m_salary = 0;
}

Person::Person(const char* pName, int age, float salary) {
	m_age = age;
	m_salary = salary;

	if (!pName)
	{
		delete[] m_pFullName;
		m_pFullName = NULL;
		return;
	}
	
	size_t BufferSize = strlen(pName) + 1;

	char* buffer = new char[BufferSize];
	delete[] m_pFullName;
	m_pFullName = buffer;
	strcpy_s(m_pFullName, BufferSize, pName);
}
