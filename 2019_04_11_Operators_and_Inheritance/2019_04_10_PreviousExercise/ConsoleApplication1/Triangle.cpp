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

Triangle::Triangle()
{
	Point3D point(0,0,0);
	this->SetA(point);
	this->SetB(point);
	this->SetC(point);
}

void Triangle::SetTriangle(const Triangle& triangle)
{
	this->SetA(triangle.GetA());
	this->SetB(triangle.GetB());
	this->SetC(triangle.GetC());
}

Triangle::Triangle(const Triangle& triangle)
{
	SetTriangle(triangle);
}

Triangle& Triangle::operator=(const Triangle& triangle)
{
	if (this != &triangle)
	{
		SetTriangle(triangle);
	}
	return *this;
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

Triangle::operator double() const
{
	return GetPerimeter();
}


