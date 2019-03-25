#pragma once

class Point3
{
public:
	Point3(double = 0, double = 0, double = 0);
	double GetX() const;
	double GetY() const;
	double GetZ() const;
	void SetX(double);
	void SetY(double);
	void SetZ(double);
	void TranslateByVector(const Point3& vector);
	Point3& GetSymetry();
	double Distance(Point3&) const;
private:
	double m_x;
	double m_y;
	double m_z;
};

