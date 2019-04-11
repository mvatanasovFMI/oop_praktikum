#pragma once
#include "Point3.h"
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
