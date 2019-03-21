// 2019_03_14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	Point3 RandomPoints;
	Triangle RandyTriangle;
	int a, b, c;
	cin >> a >> b >> c;
	RandomPoints.SetX(a);
	RandomPoints.SetY(b);
	RandomPoints.SetZ(c);
	double one=RandomPoints.GetX();
	double two=RandomPoints.GetY();
	double three=RandomPoints.GetZ();
	RandomPoints.TranslateByVector(RandomPoints);
	RandomPoints.GetSymetry(RandomPoints);
	cout << RandomPoints.GetX() << RandomPoints.GetY() << RandomPoints.GetZ() << endl;

	Point3 NewPoints;
	RandyTriangle.SetA(NewPoints);
	RandyTriangle.SetB(NewPoints);
	RandyTriangle.SetC(NewPoints);
	cout << RandyTriangle.GetPerimeter()<<endl;


}

class Point3
{

public:

	Point3(double = 0, double = 0, double = 0);



	double GetX() const;

	double GetY() const;

	double GetZ() const;

	void SetX(double xparam);

	void SetY(double yparam);

	void SetZ(double zparam);



	void TranslateByVector(const Point3& vector);
	void Input(int n, Point3 array[]);
	void Symmetry(int n, Point3 array[]);
	void Output(int n, Point3 array[]);
	Point3& GetSymetry(const Point3&);
	double Length2(const Point3&);

private:

	double m_x;

	double m_y;

	double m_z;

};
Point3::Point3(double a, double b, double c)
{
	m_x = a;
	m_y = b;
	m_z = c;
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

void Point3::SetX(double xparam)
{
	m_x = xparam;
}

void Point3::SetY(double yparam)
{
	m_y = yparam;
}

void Point3::SetZ(double zparam)
{
	m_z = zparam;
}

void Point3::Input(int n, Point3 array[])
{
	int a, b, c;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b >> c;
		array[i].SetX(a);
		array[i].SetY(b);
		array[i].SetZ(c);
	}
}
void Point3::Symmetry(int n, Point3 array[])
{
	for (int i = 0; i < n; i++)
	{
		array[i].GetSymetry(array[i]);
	}
}
void Point3::Output(int n, Point3 array[])
{
	for (int i = 0; i < n; i++)
	{
		cout << array[i].GetX() << endl;
		cout << array[i].GetY() << endl;
		cout << array[i].GetZ() << endl;

	}
}
void Point3::TranslateByVector(const Point3& vector)
{
	int secondary_x, secondary_y, secondary_z;
	secondary_x = vector.GetX + m_x;
	secondary_y = vector.GetY + m_y;
	secondary_z = vector.GetZ + m_z;

	m_x = secondary_x;
	m_y = secondary_y;
	m_z = secondary_z;
}

Point3& Point3::GetSymetry(const Point3& Point)
{
	Point3 returnPoint;
	returnPoint.SetX(Point.GetX()*(-1));
	returnPoint.SetY(Point.GetY()*(-1));
	returnPoint.SetZ(Point.GetZ()*(-1));
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
void Triangle::SetA(const Point3& coords1)
{
	m_a.SetX(coords1.GetX());
	m_a.SetY(coords1.GetY());
	m_a.SetZ(coords1.GetZ());
}
void Triangle::SetB(const Point3& coords2)
{
	coords2.GetX;
	coords2.GetY;
	coords2.GetZ;
}
void Triangle::SetC(const Point3& coords3)
{
	coords3.GetX;
	coords3.GetY;
	coords3.GetZ;
}
Triangle::Triangle()
{
	Point3 Point(0, 0, 0);
	SetA(Point);
	SetB(Point);
	SetC(Point);
}
double Triangle::GetPerimeter() 
{
	double a, b, c, p;

	a = m_a.Length2(m_b);
	b = m_b.Length2(m_c);
	c = m_c.Length2(m_a);
	p = a + b + c;
	return p;

}
double Point3::Length2(const Point3& f) 
{
	double a, b, c, s, e, p, g;
	a = f.GetX();
	b = f.GetY();
	c = f.GetZ();
	e = abs(a - m_x);
	p = abs(b - m_y);
	g = abs(c - m_z);
	s = sqrt(pow(e, 2) + pow(p, 2) + pow(g, 2));
	return s;
}