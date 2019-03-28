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
