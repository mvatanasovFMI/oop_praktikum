#include "stdafx.h"
#include "Point3.h"
#include <cmath>


Point3::Point3(double x, double y, double z) {
	m_x = x;
	m_y = y;
	m_z = z;
}

double Point3::GetX() const {
	return m_x;
}
double Point3::GetY() const {
	return m_y;
}
double Point3::GetZ() const {
	return m_z;
}

void Point3::SetX(double x) {
	m_x = x;
}
void Point3::SetY(double y) {
	m_y = y;
}
void Point3::SetZ(double z) {
	m_z = z;
}

void Point3::TranslateByVector(const Point3& vector) {
	m_x += vector.GetX();
	m_y += vector.GetY();
	m_z += vector.GetZ();
}

Point3& Point3::GetSymetry() {
	Point3 symPoint(-m_x, -m_y, -m_z);
	return symPoint;
}

double Point3::Distance(Point3& a) const {
	return sqrt((m_x - a.GetX()) * (m_x - a.GetX()) + (m_y - a.GetY()) * (m_y - a.GetY()) + (m_z - a.GetZ()) * (m_z - a.GetZ()));
}
