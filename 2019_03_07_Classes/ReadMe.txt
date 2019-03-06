PROBLEM 1.1: IMPLEMENT METHODS FOR CLASS PERSON.   YOU ARE PROVIDED WITH FOLLOWING CODE.

class Person
{
private: // encapsulation of data
	char * m_pFullName; // you can use std::string
int m_age;
float m_salary;
public:
	void Init(const char* pName, int age, float salary);
	~Person(); /* Using special method call  Destructor, to free allocated memory for m_pFullName*/
	// Setters
	void SetFullName(const char* pName);
	void SetAge(int age);
	void SetSalary(float age);
	// Setters
	char* GetFullName() const; /* without const Try  call GetFullName() in Print() or in const Person object. It will not compile */
int GetAge() const;
float GetSalary() const;
// Print methods
void Print() const; 
void PrintMembersOffsetsAndSizeOf () const;
};



PROBLEM 1.2: USE PERSON OBJECTS
A) Create instance “person” of Class Person with: 
* Full Name: Ivan Georgiev 
* Age: 22 
* Salary: 0.5
B) Print before and after setting Full Name with new name Nedqlko Bogdanov and new age 23.
C) Call PrintMembersOffsetsAndSizeOf() for that instance.

PROBLEM 1.3: MODIFY CLASS PERSON:

* Write Default Constructors and with parameters
* Use constructors in main function

PROBLEM 2:  IMPLEMENT METHODS IN CLASS POINT.
class Point
{
private:
double m_x;
double m_y;
public:
Point(double, double);
double GetX() const; 
double GetY() const;
};






PROBLEM 3:  IMPLEMENT METHODS IN CLASS POINT.
class Line
{
   private:
	Point m_pointA;
	Point m_pointB;
   public:
	Line(const Point&, const Point&);
	Point PointA() const;
	Point PointB() const;
	double Lenght() const;
	double GetSlope() const;
	Point Intersaction(const Line& fistLine, const Line& secondLine) const;
};


