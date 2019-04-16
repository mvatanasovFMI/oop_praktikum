#pragma once
#include <math.h>


template <class T>
class Point3D
{
public:
	Point3D(T = 0, T = 0, T = 0);
	
	T GetX() const;
	T GetY() const;
	T GetZ() const;
	void SetX(T);
	void SetY(T);
	void SetZ(T);
	void SetPoint(const Point3D<T>& vector);
	
	void Print() const
	{
		std::cout << GetX() << std::endl;
		std::cout << GetY() << std::endl;
		std::cout << GetZ() << std::endl;
	}

	static double Distance(const  Point3D<T>& pointA, const  Point3D<T>& PointB);
	double Distance(const  Point3D<T>& vector) const;
	void TranslateByVector(const  Point3D<T>& vector);
	Point3D<T>& GetSymetry();

	//Override this methods
	Point3D(const  Point3D<T>& point);
	Point3D<T>& operator=(const  Point3D<T>& point);
	~Point3D();

	Point3D<T>& operator++();//prefix
	Point3D<T>& operator--();   //prefix
	Point3D<T> operator++(int); // create copy of object and return it
	Point3D<T> operator--(int);
	
	Point3D<T>& operator-();
	template<typename NType1>
	friend std::ostream& operator<<(std::ostream& out, Point3D<NType1>& node);
	std::ostream& operator<< (std::ostream& o);

	//friend std::ostream& operator<< (std::ostream& o, Point3D<double>& vector);
	std::istream& operator>> (std::istream& o);
	template<typename NType1>
	friend std::istream& operator>> (std::istream& o, Point3D<NType1>& vector);


private:
	T m_x;
	T m_y;
	T m_z;

private:
	double DistanceToCenter()
	{
		return sqrt(m_x*m_x + m_y*m_y + m_z*m_z);
	}
};


//template <class T>
//Point3D<T>::Point3D(T x, T y, T z)
//{
//	SetX(x);//m_x = x;
//	SetY(y);//m_y = y;
//	SetZ(z);//m_z = z;
//}




