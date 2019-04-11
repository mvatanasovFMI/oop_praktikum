#include "pch.h"
#include "stdafx.h"
#include "Point3D.h"
#include "Triangle.h"

void Triangle::SetA(const Point3D& point) 
{ 
	GetA().SetPoint(point);
} //using helper function or operator =

void Triangle::SetB(const Point3D& point) 
{
	GetB().SetPoint(point);
}

void Triangle::SetC(const Point3D& point) 
{ 
	GetC().SetPoint(point);
}

void Triangle::SetPoints(const Triangle& tri)
{
	SetA(tri.GetA());
	SetB(tri.GetB());
	SetC(tri.GetC());
}


Triangle::Triangle()
{
	Point3D point(0,0,0);
	this->SetA(point);
	this->SetB(point);
	this->SetC(point);
}

double Triangle::GetPerimeter() const
{
	return GetA().Distance(GetB()) + GetB().Distance(GetC()) + GetA().Distance(GetC());
};

double Triangle::GetPerimeterAlt()
{
	return Point3D::Distance(GetA(), GetB()) + 
		Point3D::Distance(GetA(), GetC()) +
		Point3D::Distance(GetC(), GetB());
};

Triangle::Triangle(const Triangle& tri)
{
	SetPoints(tri);
}

Triangle& Triangle::operator=(const Triangle& tri)
{
	if (this != &tri) {
		SetPoints(tri);
	}
	return *this;
}

Triangle::~Triangle(){}

Triangle::operator double() const
{
	return GetPerimeter();
}
