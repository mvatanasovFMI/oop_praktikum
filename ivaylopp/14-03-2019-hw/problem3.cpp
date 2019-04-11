#include <iostream>
#include <cmath>
using namespace std;

class Point
{
private:
	double m_x;
	double m_y;
public:
	Point();
	Point(double, double);
	double GetX() const; 
	double GetY() const;
};

Point::Point() {
	m_x = 0;
	m_y = 0;
}

Point::Point(double xCoordinate, double yCoordinate) {
	m_x = xCoordinate;
	m_y = yCoordinate;
}

double Point::GetX() const {
	return m_x;
}

double Point::GetY() const {
	return m_y;
}


class Line
{
private:
	Point m_pointA;
	Point m_pointB;
public:
	Line(const Point&, const Point&);
	Point PointA() const;
	Point PointB() const;
	double Lenght() const;
	double GetSlope() const;
	Point Intersection(const Line& fistLine, const Line& secondLine) const;
};

Line::Line(const Point& pA, const Point& pB) {
	m_pointA = pA;
	m_pointB = pB;
}

Point Line::PointA() const {
	return m_pointA;
}

Point Line::PointB() const {
	return m_pointB;
}

double Line::Lenght() const {
	return sqrt(m_pointA.GetX() * m_pointB.GetX() + m_pointA.GetY() * m_pointB.GetY());
}

double Line::GetSlope() const {
	return (m_pointB.GetY() - m_pointA.GetY()) / (m_pointB.GetX() - m_pointA.GetX());
}

Point Intersection(const Line& fistLine, const Line& secondLine) const {
	
}

int main() {

	return 0;
}
