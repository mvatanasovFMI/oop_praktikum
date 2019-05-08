#pragma once
#include <math.h>
#include <iostream>


class Point3D
{
public:
	Point3D(double = 0, double = 0, double = 0);
	//Override this methods
	Point3D(const Point3D& point);
	Point3D& operator=(const Point3D& point);
	~Point3D();
	
	double GetX() const;
	double GetY() const;
	double GetZ() const;
	void SetX(double);
	void SetY(double);
	void SetZ(double);
	
	void Print() const
	{
		std::cout << GetX() << std::endl;
		std::cout << GetY() << std::endl;
		std::cout << GetZ() << std::endl;
	}

	static double Distance(const Point3D& pointA, const Point3D& PointB);
	double Distance(const Point3D& vector) const;
	void TranslateByVector(const Point3D& vector);
	Point3D& GetSymetry();


	Point3D& operator++();//prefix
	Point3D& operator--();   //prefix
	Point3D operator++(int); // create copy of object and return it
	Point3D operator--(int);
	
	Point3D& operator-();
	std::ostream& operator<< (std::ostream& o);
	friend std::ostream& operator<< (std::ostream& o, Point3D& vector);
	std::istream& operator>> (std::istream& o);
	friend std::istream& operator>> (std::istream& o, Point3D& vector);

	void SetPoint(const Point3D& vector);

private:
	double DistanceToCenter()
	{
		return sqrt(m_x*m_x + m_y*m_y + m_z*m_z);
	}

private:
	double m_x;
	double m_y;
	double m_z;
};
