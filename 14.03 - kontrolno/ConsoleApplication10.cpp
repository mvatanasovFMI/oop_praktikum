// ConsoleApplication10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <math.h>
using namespace std;
class Point3

{

public:

	Point3(double = 0, double = 0, double = 0);


	double GetX() const;

	double GetY() const;

	double GetZ() const;



	void SetX(double);

	void SetY(double);

	void SetZ(double);



	void TranslateByVector(const Point3& vector);

	void Print();

	Point3& GetSymetry();

private:

	double m_x;

	double m_y;

	double m_z;

};




Point3::Point3(double x, double y, double z)
{
	m_x = x;
	m_y = y;
	m_z = z;
}
void Point3::Print()
{
	cout << m_x << "  " << m_y << "  " << m_z;
}
double Point3::GetX() const
{
	return m_x;
}

double Point3::GetY() const
{
	return m_y;
}

double Point3::GetZ() const
{
	return m_z;
}

void Point3::SetX(double x)
{
	m_x = x;
}

void Point3::SetY(double y)
{
	m_y = y;
}

void Point3::SetZ(double z)
{
	m_z = z;
}

void Point3::TranslateByVector(const Point3& vector)
{
	m_x += vector.m_x;
	m_y += vector.m_y;
	m_z += vector.m_z;

}
class Triangle

{

public:

	Triangle();



	void SetA(const Point3&);

	void SetB(const Point3&);

	void SetC(const Point3&);

	double GetPerimeter();

private:

	Point3 m_a;

	Point3 m_b;

	Point3 m_c;

};

Triangle::Triangle()
{
	
}

void Triangle::SetA(const Point3& x)
{
	m_a.SetX(x.GetX());
}

void Triangle::SetB(const Point3& y)
{
	m_b.SetY(y.GetY());
}

void Triangle::SetC(const Point3& z)
{
	m_c.SetZ(z.GetZ());
}

double Triangle::GetPerimeter()
{
	double vec1 = sqrt(pow((m_a.GetX() - m_b.GetX()), 2) + pow((m_a.GetY() - m_b.GetY()), 2) + pow((m_a.GetZ() - m_b.GetZ()), 2));
	double vec2 = sqrt(pow(m_a.GetX() - m_c.GetX(), 2) + pow(m_a.GetY() - m_c.GetY(), 2) + pow(m_a.GetZ() - m_c.GetZ(), 2));
	double vec3 = sqrt(pow(m_b.GetX() - m_c.GetX(), 2) + pow(m_b.GetY() - m_c.GetY(), 2) + pow(m_b.GetZ() - m_c.GetZ(), 2));
	return vec1 + vec2 + vec3;
}





void Input(int n, Point3 a[])
{
	for (int i = 0; i < n; i++)
	{
		double x, y, z;
		cin >> x;
		a[i].SetX(x);
		cin >> y;
		a[i].SetY(y);
		cin >> z;
		a[i].SetZ(z);
	}
}

void Output(int n, Point3 a[])
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i].GetX() << " ";
		cout << a[i].GetY() << " ";
		cout << a[i].GetZ() << " ";
	}
}



int main()
{
	Point3 a (1, 2, 0);
	Point3 b (-1, -2, 0);
	Point3 c (0, 2, 3);
	Point3 points[3];
	Triangle triangle;
	triangle.SetA(a);
	triangle.SetB(b);
	triangle.SetC(c);
	cout << triangle.GetPerimeter();
	cout << endl << endl;
	Input(3, points);
	Output(3, points);
	


}