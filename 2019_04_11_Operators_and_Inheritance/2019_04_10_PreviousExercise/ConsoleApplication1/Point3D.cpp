#include "pch.h"
#include "stdafx.h"
#include "Point3D.h"

Point3D::Point3D(double x, double y, double z)
{
	SetX(x);//m_x = x;
	SetY(y);//m_y = y;
	SetZ(z);//m_z = z;
}

Point3D::Point3D(const Point3D& point)
{
	SetPoint(point);
}

Point3D& Point3D::operator=(const Point3D& point) 
{
	if (this != &point) 
	{
		SetPoint(point);
	} 

	return *this;
}

Point3D& Point3D::operator++() {
	SetX(GetX() + 1);
	SetY(GetY() + 1);
	SetZ(GetZ() + 1);
	return *this;
}

Point3D& Point3D::operator--() {
	SetX(GetX() - 1);
	SetY(GetY() - 1);
	SetZ(GetZ() - 1);

	return *this;
}

Point3D& Point3D::operator-() {
	SetX(-GetX());
	SetY(-GetY());
	SetZ(-GetZ());

	return *this;
}

std::ostream& Point3D::operator<< (std::ostream& offstream)
{
	offstream << GetX() << std::endl;
	offstream << GetY() << std::endl;
	offstream << GetZ() << std::endl;

	return offstream;
}

std::ostream& operator<<(std::ostream& offstream, Point3D& vector)
{
	return vector.operator<<(offstream);
}

std::istream& Point3D::operator>>(std::istream& instream)
{
	int cordinate;
	instream >> cordinate;
	SetX(cordinate);
	instream >> cordinate;
	SetY(cordinate);
	instream >> cordinate;
	SetZ(cordinate);

	return instream;
}

std::istream& operator>>(std::istream& instream, Point3D& vector)
{
	return vector.operator>>(instream);
}

Point3D Point3D::operator++(int number)
{
	Point3D& newPoint=*this;
	SetX(GetX() + 1);
	SetY(GetY() + 1);
	SetZ(GetZ() + 1);

	return newPoint;
}
Point3D Point3D::operator--(int number)
{
	Point3D& newPoint = *this;
	SetX(GetX() - 1);
	SetY(GetY() - 1);
	SetZ(GetZ() - 1);

	return newPoint;
}
Point3D::~Point3D()
{}

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



