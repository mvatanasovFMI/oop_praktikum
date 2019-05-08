#pragma once
#include "Point3D.h"

class ColorPoint3D: public Point3D
{
public:
	ColorPoint3D(Point3D = Point3D(0, 0, 0), double = 0);
	ColorPoint3D(const ColorPoint3D& point);
	ColorPoint3D& operator=(const ColorPoint3D& point);
	~ColorPoint3D();

	double GetColor() const;
	void SetColor(double color);
protected:
	void SetPoint(const ColorPoint3D& point3D)
	{
		Point3D::SetPoint(point3D);
		SetColor(point3D.GetColor());
	}
private:
	double m_color;
};

