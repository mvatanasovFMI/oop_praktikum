#include <iostream>
using namespace std;

class Point
{
private:
	double m_x;
	double m_y;
public:
	Point(double, double);
	double GetX() const; 
	double GetY() const;
};

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

int main() {

	return 0;
}
