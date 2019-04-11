#pragma once
#include "Point3D.h"

class Triangle
{
public:
	Triangle(); 
	//Triangle(const Triangle& point);
	//Triangle& operator=(const Triangle& point);
	//~Triangle();
	//operator float() const; // return Perimeter

	void SetA(const Point3D&); //using helper function or operator =
	void SetB(const Point3D&);
	void SetC(const Point3D&);

	const Point3D& GetA() const { return m_a; } 
	const Point3D& GetB() const { return m_b; }
	const Point3D& GetC() const { return m_c; } // FIX TO do , call constuctor?

	Point3D& GetA() { return m_a; } 
	Point3D& GetB() { return m_b; }
	Point3D& GetC() { return m_c; } 

	double GetPerimeter(); // use getters and Distance helper

	double GetPerimeterAlt();
private:
	Point3D m_a;
	Point3D m_b;
	Point3D m_c;
};
