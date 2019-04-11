#include "stdafx.h"
#include "Point3D.h"

Point3D::Point3D(double x, double y, double z)
{
	SetX(x);//m_x = x;
	SetY(y);//m_y = y;
	SetZ(z);//m_z = z;
}

double Point3D::GetX() const { return m_x; }
double Point3D::GetY() const { return m_y; }
double Point3D::GetZ() const { return m_z; }

void Point3D::SetX(double coordinateValue) { this->m_x = coordinateValue; }
void Point3D::SetY(double coordinateValue) { m_y = coordinateValue; }
void Point3D::SetZ(double coordinateValue) { m_z = coordinateValue; }


void Point3D::TranslateByVector(const Point3D& vector) {
	this->SetY(vector.GetX() + this->GetX());
	this->SetX(vector.GetY() + this->GetY());
	this->SetZ(vector.GetZ() + this->GetZ());
}

Point3D& Point3D::GetSymetry() {
	this->SetX(-GetX());
	this->SetY(-GetY());
	this->SetZ(-GetZ());

	return *this;
}

void Point3D::SetPoint(const Point3D& vector)
{
	SetX(vector.GetX());
	SetY(vector.GetY());
	SetZ(vector.GetZ());
}

 double Point3D::Distance(const Point3D& pointA, const Point3D& pointB) {
	return pointA.Distance(pointB);
}

double Point3D::Distance(const Point3D& vector) const
{
	Point3D point(m_x - vector.GetX(), m_y - vector.GetY(), m_z - vector.GetZ());
	return point.DistanceToCenter();
}

 //static double Distance(const Point3D& vector) const
 //{
	// Point3D point(m_x - vector.GetX(), m_y - vector.GetY(), m_z - vector.GetZ());
	// return point.DistanceToCenter();
 //}

