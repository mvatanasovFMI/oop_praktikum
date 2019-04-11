#include "pch.h"
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

Point3D::~Point3D()
{

}

Point3D& Point3D::operator++()
{
	SetX(GetX() + 1);
	SetY(GetY() + 1);
	SetZ(GetZ() + 1);
	return *this;
}

Point3D& Point3D::operator--()
{
	this->SetX(GetX() - 1);
	this->SetY(GetY() - 1);
	this->SetZ(GetZ() - 1);
	return *this;
}

Point3D Point3D::operator++(int)
{
	Point3D returnPoint = *this;
	returnPoint.SetX(returnPoint.GetX() + 1);
	returnPoint.SetY(returnPoint.GetY() + 1);
	returnPoint.SetZ(returnPoint.GetZ() + 1);
	return returnPoint;
}

Point3D Point3D::operator--(int)
{
	Point3D returnPoint = *this;
	returnPoint.SetX(returnPoint.GetX() - 1);
	returnPoint.SetY(returnPoint.GetY() - 1);
	returnPoint.SetZ(returnPoint.GetZ() - 1);
	return returnPoint;
}

Point3D& Point3D::operator-()
{
	SetX(-GetX());
	SetY(-GetY());
	SetZ(-GetZ());

	return *this;
}

std::ostream& Point3D::operator<< (std::ostream& ostream)
{
	ostream << GetX() << ", " << GetY() << ", " << GetZ() << std::endl;
	return ostream;
}

std::ostream& operator<< (std::ostream& o, Point3D& vector)
{
	return vector.operator<<(o);
}

std::istream& Point3D::operator>> (std::istream& istream)
{
	double coordinate;
	istream >> coordinate;
	SetX(coordinate);
	istream >> coordinate;
	SetY(coordinate);
	istream >> coordinate;
	SetZ(coordinate);

	return istream;
}

std::istream& operator>> (std::istream& istream, Point3D& vector)
{
	return vector.operator>>(istream);
}

