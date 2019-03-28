#pragma once
#include <math.h>

class Point3D
{
public:
	Point3D(double = 0, double = 0, double = 0);
	// Add operator=, copy constructor, constructor with params, destructor
	double GetX() const;
	double GetY() const;
	double GetZ() const;
	void SetX(double);
	void SetY(double);
	void SetZ(double);
	void SetPoint(const Point3D& vector);
	
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
private:
	double m_x;
	double m_y;
	double m_z;

private:
	double DistanceToCenter()
	{
		return sqrt(m_x*m_x + m_y*m_y + m_z*m_z);
	}
};
