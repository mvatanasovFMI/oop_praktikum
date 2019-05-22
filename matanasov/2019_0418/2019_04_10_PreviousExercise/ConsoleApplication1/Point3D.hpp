#pragma once
#include "pch.h"
#include "stdafx.h"
#include "Point3D.h"

template <class T>
Point3D<T>::Point3D(T x, T y, T z)
{
	SetX(x);//m_x = x;
	SetY(y);//m_y = y;
	SetZ(z);//m_z = z;
}

template <class T>
Point3D<T>::Point3D(const Point3D<T>& point)
{
	SetPoint(point);
}

template <class T>
Point3D<T>& Point3D<T>::operator=(const Point3D<T>& point)
{
	if (this != &point) 
	{
		SetPoint(point);
	} 

	return *this;
}

template <class T>
Point3D<T>& Point3D<T>::operator++() {
	SetX(GetX() + 1);
	SetY(GetY() + 1);
	SetZ(GetZ() + 1);
	return *this;
}

template <class T>
Point3D<T>& Point3D<T>::operator--() {
	SetX(GetX() - 1);
	SetY(GetY() - 1);
	SetZ(GetZ() - 1);

	return *this;
}

template <class T>
Point3D<T>& Point3D<T>::operator-() {
	SetX(-GetX());
	SetY(-GetY());
	SetZ(-GetZ());

	return *this;
}

template <class T>
std::ostream& Point3D<T>::operator<< (std::ostream& offstream)
{
	offstream << GetX() << std::endl;
	offstream << GetY() << std::endl;
	offstream << GetZ() << std::endl;

	return offstream;
}

//std::ostream& operator<< (std::ostream& o, Point3D<double>& vector) {
//	return o;
//}
//}
//std::ostream& operator<<(std::ostream& offstream, Point3D<double>& vector)
//{
//	return vector.operator<<(offstream);
//}

template<typename NType1>
std::ostream& operator<<(std::ostream& offstream, Point3D<NType1>& vector)
{
	return vector.operator<<(offstream);
}
//std::ostream& operator<<(std::ostream& offstream, Point3D<int>& vector)
//{
//	return vector.operator<<(offstream);
//}


class FunctionOverridingBase
{
public:
	virtual void method()
	{
		cout << "base method" << endl;
	}
};

class FunctionOverridingDerived :public FunctionOverridingBase
{
public:
	void method() 
	{
		cout << "derived method" << endl;
	}
};

//main function 
void main()
{
	FunctionOverridingDerived derived;
	FunctionOverridingBase *ptrBase = &derived;
	ptrBase->method();
}

class FunctionalOverloading
{
public:
	void print(int x)
	{
		cout << "x = " << x << endl;
	}

	void print(double x)
	{
		cout << "x = " << x << endl;
	}

	void print(int x, int y)
	{
		cout << "x and y = " << x << ", " << y << endl;
	}
};

template <class T>
std::istream& Point3D<T>::operator>>(std::istream& instream)
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

template<typename NType1>
std::istream& operator>>(std::istream& instream, Point3D<NType1>& vector)
{
	return vector.operator>>(instream);
}

//std::istream& operator>>(std::istream& instream, Point3D<double>& vector)
//{
//	return vector.operator>>(instream);
//}

//std::istream& operator>>(std::istream& instream, Point3D<double>& vector)
//{
//	return vector.operator>>(instream);
//}

template <class T>
Point3D<T> Point3D<T>::operator++(int number)
{
	Point3D<T>& newPoint=*this;
	SetX(GetX() + 1);
	SetY(GetY() + 1);
	SetZ(GetZ() + 1);

	return newPoint;
}

template <class T>
Point3D<T> Point3D<T>::operator--(int number)
{
	Point3D<T>& newPoint = *this;
	SetX(GetX() - 1);
	SetY(GetY() - 1);
	SetZ(GetZ() - 1);

	return newPoint;
}

template <class T>
Point3D<T>::~Point3D()
{}

template <class T>
T Point3D<T>::GetX() const { return m_x; }

template <class T>
T Point3D<T>::GetY() const { return m_y; }

template <class T>
T Point3D<T>::GetZ() const { return m_z; }

template <class T>
void Point3D<T>::SetX(T coordinateValue) { this->m_x = coordinateValue; }

template <class T>
void Point3D<T>::SetY(T coordinateValue) { m_y = coordinateValue; }

template <class T>
void Point3D<T>::SetZ(T coordinateValue) { m_z = coordinateValue; }

template <class T>
void Point3D<T>::TranslateByVector(const Point3D<T>& vector) {
	this->SetY(vector.GetX() + this->GetX());
	this->SetX(vector.GetY() + this->GetY());
	this->SetZ(vector.GetZ() + this->GetZ());
}

template <class T>
Point3D<T>& Point3D<T>::GetSymetry() {
	this->SetX(-GetX());
	this->SetY(-GetY());
	this->SetZ(-GetZ());

	return *this;
}

template <class T>
void Point3D<T>::SetPoint(const Point3D<T>& vector)
{
	SetX(vector.GetX());
	SetY(vector.GetY());
	SetZ(vector.GetZ());
}

template <class T>
 double Point3D<T>::Distance(const Point3D<T>& pointA, const Point3D<T>& pointB) {
	return pointA.Distance(pointB);
}

template <class T>
double Point3D<T>::Distance(const Point3D<T>& vector) const
{
	Point3D<T> point(m_x - vector.GetX(), m_y - vector.GetY(), m_z - vector.GetZ());
	return point.DistanceToCenter();
}



