#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private: // encapsulation of data
	char * m_pFullName; // you can use std::string
	int m_age;
	float m_salary;
public:
	void Init(const char* pName, int age, float salary);
	Person();
	Person(const char* pName, int age, float salary);
	~Person(); /* Using special method call  Destructor, to free allocated memory for m_pFullName*/
	// Setters
	void SetFullName(const char* pName);
	void SetAge(int age);
	void SetSalary(float salary);
	// Setters
	char* GetFullName() const; /* without const Try  call GetFullName() in Print() or in const Person object. It will not compile */
	int GetAge() const;
	float GetSalary() const;
	// Print methods
	void Print() const; 
	void PrintMembersOffsetsAndSizeOf () const;
};

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
	strcpy_s(m_pFullName, BufferSize, pName);
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

int main() {
	Person person;
	person.Init("Ivan Georgiev", 22, 0.5);
	person.Print();
	person.SetFullName("Nedqlko Bogdanov");
	person.SetAge(23);
	person.Print();
	person.PrintMembersOffsetsAndSizeOf();

	Person person2;
	return 0;
}
