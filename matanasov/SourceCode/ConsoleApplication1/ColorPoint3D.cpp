#include "pch.h"
#include "ColorPoint3D.h"


ColorPoint3D::ColorPoint3D(Point3D point, double color): Point3D(point) //FIX SEE WHICH IS CALLED FIRST
{
	SetColor(color);
}

ColorPoint3D::ColorPoint3D(const ColorPoint3D& point)
{
	SetPoint(point);
}

ColorPoint3D& ColorPoint3D::operator=(const ColorPoint3D& point)
{
	if (this != &point)
	{
		Point3D::operator=(point);
		SetColor(point.GetColor());
		//SetPoint(point);
	}

	return *this;
}

ColorPoint3D::~ColorPoint3D()
{
}

double ColorPoint3D::GetColor() const
{
	return m_color;
}

void ColorPoint3D::SetColor(double color)
{
	m_color = color;
}



std::ostream& operator<<(std::ostream& offstream, ColorPoint3D& coloredPoint)
{
	return offstream << coloredPoint << "Color: " << coloredPoint.GetColor() << std::endl;	
}

std::istream& operator>>(std::istream& instream, ColorPoint3D& coloredPoint3D)
{
	double color;
	instream >> coloredPoint3D;
	instream >> color;
	coloredPoint3D.SetColor(color);

	return instream;
}
