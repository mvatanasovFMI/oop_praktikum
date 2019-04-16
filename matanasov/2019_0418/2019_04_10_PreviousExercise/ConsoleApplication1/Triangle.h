#pragma once
#include "Point3D.h"


template <class T>
class Triangle
{
public:
	Triangle(); 
	Triangle(const Triangle<T>& point);
	Triangle& operator=(const Triangle<T>& point);
	~Triangle() {}
	operator double() const; // return Perimeter

	void SetA(const Point3D<T>&); //using helper function or operator =
	void SetB(const Point3D<T>&);
	void SetC(const Point3D<T>&);

	const Point3D<T>& GetA() const { return m_a; } 
	const Point3D<T>& GetB() const { return m_b; }
	const Point3D<T>& GetC() const { return m_c; } // FIX TO do , call constuctor?

	Point3D<T>& GetA() { return m_a; } 
	Point3D<T>& GetB() { return m_b; }
	Point3D<T>& GetC() { return m_c; } 

	double GetPerimeter() const; // use getters and Distance helper

	double GetPerimeterAlt();
private:
	void SetTriangle(const Triangle<T>& triangle);

private:
	Point3D<T> m_a;
	Point3D<T> m_b;
	Point3D<T> m_c;
};
