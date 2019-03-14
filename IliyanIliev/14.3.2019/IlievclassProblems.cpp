#include <iostream>
#include <math.h>
using namespace std;

class Person
{
private:
	string m_pFullName;
    int m_age;
    float m_salary;
public:
    Person()
    {
        m_pFullName = "Insert name here";
        m_age = 0;
        m_salary = 0;
    }
    Person(const char* pName, int age, float salary)
    {
        Init(pName, age, salary);
    }
	void Init(const char* pName, int age, float salary)
	{
	    SetFullName(pName);
	    SetAge(age);
	    SetSalary(salary);
	}
	~Person()
	{
	    //if  m_pFullName was char*:
	    //delete[] m_pFullName;
	}
	// Setters
	void SetFullName(const char* pName)
	{
	    if(pName != NULL)
            m_pFullName = pName;
	}
	void SetAge(int age)
	{
	    if (age >= 0)
            m_age = age;
	}
	void SetSalary(float salary)
	{
	    if (salary >= 0)
            m_salary = salary;
	}
	// Getters
	string GetFullName() const
	{
	    return m_pFullName;
	}
    int GetAge() const
    {
        return m_age;
    }
    float GetSalary() const
    {
        return m_salary;
    }
    // Print methods
    void Print() const
    {
        cout << "Name: " << m_pFullName << "\nAge: " << m_age << "\nSalary: " << m_salary << '\n';
    }
    void PrintMembersOffsetsAndSizeOf () const;
};

class Point
{
private:
    double m_x;
    double m_y;
public:
    Point(double x, double y)
    {
        m_x = x;
        m_y = y;
    }
    void SetX(double x)
    {
        m_x = x;
    }
    void SetY(double y)
    {
        m_y = y;
    }
    double GetX() const
    {
        return m_x;
    }
    double GetY() const
    {
        return m_y;
    }
};


class Line
{
private:
	Point m_pointA;
	Point m_pointB;
public:
	Line(const Point& a, const Point& b)
	{
        m_pointA.SetX(a.GetX());
        m_pointA.SetY(a.GetY());
        m_pointB.SetX(b.GetX());
        m_pointB.SetY(b.GetY());
	}
	Point PointA() const
	{
	    return m_pointA;
	}
	Point PointB() const
	{
	    return m_pointB;
	}
	double Lenght() const
	{
	    return (sqrt((m_pointA.GetX() - m_pointB.GetX()) * (m_pointA.GetX() - m_pointB.GetX()) + (m_pointA.GetY() - m_pointB.GetY()) * (m_pointA.GetY() - m_pointB.GetY())));
	}
	double GetSlope() const;
	Point Intersaction(const Line& fistLine, const Line& secondLine) const;
};


int main()
{
    Person person;
    person.Print();
    person.Init("Ivan Georgiev", 22, 0.5);
    person.Print();
    person.SetFullName("Nedqlko Bogdanov");
    person.SetAge(23);
    person.Print();
    return 0;
}
