#pragma once
#include "pch.h"
#include "stdafx.h"
#include "Point3D.h"
#include "Triangle.h"

template <class T>
void Triangle<T>::SetA(const Point3D<T>& point) 
{ 
	GetA().SetPoint(point);
} //using helper function or operator =

template <class T>
void Triangle<T>::SetB(const Point3D<T>& point) 
{
	GetB().SetPoint(point);
}

template <class T>
void Triangle<T>::SetC(const Point3D<T>& point) 
{ 
	GetC().SetPoint(point);
}


template <class T>
Triangle<T>::Triangle()
{
	Point3D<T> point(0,0,0);
	this->SetA(point);
	this->SetB(point);
	this->SetC(point);
}

template <class T>
void Triangle<T>::SetTriangle(const Triangle& triangle)
{
	this->SetA(triangle.GetA());
	this->SetB(triangle.GetB());
	this->SetC(triangle.GetC());
}

template <class T>
Triangle<T>::Triangle(const Triangle& triangle)
{
	SetTriangle(triangle);
}

template <class T>
Triangle<T>& Triangle<T>::operator=(const Triangle<T>& triangle)
{
	if (this != &triangle)
	{
		SetTriangle(triangle);
	}
	return *this;
}

template <class T>
double Triangle<T>::GetPerimeter() const
{
	return GetA().Distance(GetB()) + GetB().Distance(GetC()) + GetA().Distance(GetC());
};

template <class T>
double Triangle<T>::GetPerimeterAlt()
{
	return Point3D<T>::Distance(GetA(), GetB()) + 
		Point3D<T>::Distance(GetA(), GetC()) +
		Point3D<T>::Distance(GetC(), GetB());
};

template <class T>
Triangle<T>::operator double() const
{
	return GetPerimeter();
}


