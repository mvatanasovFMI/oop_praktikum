#pragma once
//problem 1
//Създайте клас Vector2DD<ТYPE_COORDINATES>.
//
//Класа трябва да съдържа в себе си :
//
//-Конструктор с подразбиращи параметри
//
//- Copy конструктор
//
//- Деструктор
//
//- Set и Get методи за X и Y координатите
//
//- Предефинирани оператори(=, +(инфиксен), -(префиксен), << , >> )
//
//- Метод за намиране на големината на вектора
#include <iostream>

using namespace std;

template <class TYPE_COORDINATES>
class Vector2D
{
public:
	Vector2D(TYPE_COORDINATES = 0, TYPE_COORDINATES = 0);
	Vector2D(const  Vector2D<TYPE_COORDINATES>& point);
	Vector2D<TYPE_COORDINATES>& operator=(const  Vector2D<TYPE_COORDINATES>& point);
	~Vector2D();

	TYPE_COORDINATES GetX() const;
	TYPE_COORDINATES GetY() const;
	void SetX(TYPE_COORDINATES);
	void SetY(TYPE_COORDINATES);
	
	void SetPoint(const Vector2D<TYPE_COORDINATES>& vector);

	Vector2D<TYPE_COORDINATES>& operator-();
	Vector2D<TYPE_COORDINATES> operator+(const Vector2D<TYPE_COORDINATES>& vectorToAdd);
	
	std::ostream& operator<< (std::ostream& o);
	std::istream& operator>> (std::istream& o);

	TYPE_COORDINATES DistanceToCenter();

	template<typename NType1>
	friend std::ostream& operator<<(std::ostream& out, Vector2D<NType1>& node);

	template<typename NType1>
	friend std::istream& operator>> (std::istream& in, Vector2D<NType1>& vector);

private:
	TYPE_COORDINATES m_x;
	TYPE_COORDINATES m_y;
};

template <class TYPE_COORDINATES>
Vector2D<TYPE_COORDINATES>::Vector2D(TYPE_COORDINATES x, TYPE_COORDINATES y)
{
	SetX(x);//m_x = x;
	SetY(y);//m_y = y;
}

template <class TYPE_COORDINATES>
Vector2D<TYPE_COORDINATES>::Vector2D(const Vector2D<TYPE_COORDINATES>& point)
{
	SetPoint(point);
}

template <class TYPE_COORDINATES>
Vector2D<TYPE_COORDINATES>& Vector2D<TYPE_COORDINATES>::operator=(const Vector2D<TYPE_COORDINATES>& point)
{
	if (this != &point)
	{
		SetPoint(point);
	}

	return *this;
}

template <class TYPE_COORDINATES>
Vector2D<TYPE_COORDINATES>& Vector2D<TYPE_COORDINATES>::operator-() {
	SetX(-GetX());
	SetY(-GetY());
	
	return *this;
}

template <class TYPE_COORDINATES>
TYPE_COORDINATES Vector2D<TYPE_COORDINATES>::DistanceToCenter()
{
	return sqrt(m_x*m_x + m_y * m_y);
}

template <class TYPE_COORDINATES>
std::ostream& Vector2D<TYPE_COORDINATES>::operator<< (std::ostream& offstream)
{
	offstream << "X = " << GetX() << endl << "Y = "
		<< GetY() << std::endl;
	
	return offstream;
}

template<typename NType1>
std::ostream& operator<<(std::ostream& offstream, Vector2D<NType1>& vector)
{
	return vector.operator<<(offstream);
}

template <class TYPE_COORDINATES>
std::istream& Vector2D<TYPE_COORDINATES>::operator>>(std::istream& instream)
{
	TYPE_COORDINATES cordinate;
	cout << "X = ";
	instream >> cordinate;
	SetX(cordinate);
	cout << "Y = ";
	instream >> cordinate;
	SetY(cordinate);

	return instream;
}

template<typename NType1>
std::istream& operator>> (std::istream& o, Vector2D<NType1>& vector);
template<typename NType1>
std::istream& operator>>(std::istream& instream, Vector2D<NType1>& vector)
{
	return vector.operator>>(instream);
}


template <class TYPE_COORDINATES>
Vector2D<TYPE_COORDINATES> Vector2D<TYPE_COORDINATES>::operator+(const Vector2D<TYPE_COORDINATES>& vectorToAdd)
{
	Vector2D<TYPE_COORDINATES> resultVector = Vector2D<TYPE_COORDINATES>();
	
	resultVector.SetX(GetX() + vectorToAdd.GetX());
	resultVector.SetY(GetY() + vectorToAdd.GetY());

	return resultVector;
}

template <class TYPE_COORDINATES>
Vector2D<TYPE_COORDINATES>::~Vector2D()
{}

template <class TYPE_COORDINATES>
TYPE_COORDINATES Vector2D<TYPE_COORDINATES>::GetX() const { return m_x; }

template <class TYPE_COORDINATES>
TYPE_COORDINATES Vector2D<TYPE_COORDINATES>::GetY() const { return m_y; }

template <class TYPE_COORDINATES>
void Vector2D<TYPE_COORDINATES>::SetX(TYPE_COORDINATES coordinateValue) { this->m_x = coordinateValue; }

template <class TYPE_COORDINATES>
void Vector2D<TYPE_COORDINATES>::SetY(TYPE_COORDINATES coordinateValue) { m_y = coordinateValue; }

template <class TYPE_COORDINATES>
void Vector2D<TYPE_COORDINATES>::SetPoint(const Vector2D<TYPE_COORDINATES>& vector)
{
	SetX(vector.GetX());
	SetY(vector.GetY());
}
