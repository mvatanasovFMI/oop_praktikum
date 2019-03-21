#include "stdafx.h"
#include "Triangle.h"



Triangle::Triangle() {
	m_b.SetX(1);
	m_c.SetY(1);
}

void Triangle::SetA(const Point3& a) {
	m_a.SetX(a.GetX());
	m_a.SetY(a.GetY());
	m_a.SetZ(a.GetZ());
}
void Triangle::SetB(const Point3& b) {
	m_b.SetX(b.GetX());
	m_b.SetY(b.GetY());
	m_b.SetZ(b.GetZ());
}
void Triangle::SetC(const Point3& c) {
	m_c.SetX(c.GetX());
	m_c.SetY(c.GetY());
	m_c.SetZ(c.GetZ());
}

double Triangle::GetPerimeter() {
	double sideAB = m_a.Distance(m_b);
	double sideAC = m_a.Distance(m_c);
	double sideBC = m_b.Distance(m_c);
	return sideAB + sideAC + sideBC;
}

