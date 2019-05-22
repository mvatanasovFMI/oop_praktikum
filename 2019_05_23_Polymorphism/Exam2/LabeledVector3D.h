#pragma once

//Задача 3.
//
//Създайте клас LabeledVector3D<ТYPE_COORDINATES, TYPE_LABEL>, който наследява LabeledVector2D<ТYPE_COORDINATES, TYPE_LABEL>.
//
//Класа трябва да съдържа в себе си :
//
//-Конструктор с подразбиращи параметри
//
//- Copy конструктор
//
//- Деструктор
//
//- Set и Get методи за z координатата
//
//- Предефинирайте наследените методи, където е необходимо.

#include <iostream>
#include <string>
#include "LabeledVector2D.h"

using namespace std;

template <class TYPE_COORDINATES, class TYPE_LABEL>
class LabeledVector3D : public LabeledVector2D<TYPE_COORDINATES, TYPE_LABEL>
{
public:
	LabeledVector3D(TYPE_COORDINATES = 0, TYPE_COORDINATES = 0, TYPE_COORDINATES = 0);
	LabeledVector3D(const  LabeledVector3D<TYPE_COORDINATES, TYPE_LABEL>& point);
	LabeledVector3D<TYPE_COORDINATES, TYPE_LABEL>& operator=(const  LabeledVector3D<TYPE_COORDINATES, TYPE_LABEL>& point);
	~LabeledVector3D();

	TYPE_COORDINATES GetZ() const;
	void SetZ(TYPE_COORDINATES);

	void SetPoint(const LabeledVector3D<TYPE_COORDINATES, TYPE_LABEL>& vector);

	TYPE_COORDINATES DistanceToCenter();

	LabeledVector3D<TYPE_COORDINATES, TYPE_LABEL>& operator-();
	LabeledVector3D<TYPE_COORDINATES, TYPE_LABEL> operator+(const LabeledVector3D<TYPE_COORDINATES, TYPE_LABEL>& vectorToAdd);

	std::ostream& operator<< (std::ostream& o);
	std::istream& operator>> (std::istream& o);

	//FIX Review class vs typename
	template<typename COORDINATES, typename LABEL>
	friend std::ostream& operator<<(std::ostream& out, LabeledVector3D<COORDINATES, LABEL>& node);

	template<typename COORDINATES, typename LABEL>
	friend std::istream& operator>> (std::istream& in, LabeledVector3D<COORDINATES, LABEL>& vector);

private:
	TYPE_COORDINATES m_z;
};

template <class TYPE_COORDINATES, class TYPE_LABEL>
LabeledVector3D<TYPE_COORDINATES, TYPE_LABEL>::LabeledVector3D(TYPE_COORDINATES x, TYPE_COORDINATES y, TYPE_COORDINATES z) : LabeledVector2D<TYPE_COORDINATES, TYPE_LABEL>(x, y)
{
	SetZ(z);
}

template <class TYPE_COORDINATES, class TYPE_LABEL>
LabeledVector3D<TYPE_COORDINATES, TYPE_LABEL>::LabeledVector3D(const LabeledVector3D<TYPE_COORDINATES, TYPE_LABEL>& point) : LabeledVector2D<TYPE_COORDINATES, TYPE_LABEL>(point)
{
	SetZ(point.GetZ());
}

template <class TYPE_COORDINATES, class TYPE_LABEL>
LabeledVector3D<TYPE_COORDINATES, TYPE_LABEL>& LabeledVector3D<TYPE_COORDINATES, TYPE_LABEL>::operator=(const LabeledVector3D<TYPE_COORDINATES, TYPE_LABEL>& point)
{
	if (this != &point)
	{
		LabeledVector2D<TYPE_COORDINATES, TYPE_LABEL>::operator=(point);
		SetZ(point.GetZ());
	}

	return *this;
}

template <class TYPE_COORDINATES, class TYPE_LABEL>
LabeledVector3D<TYPE_COORDINATES, TYPE_LABEL>& LabeledVector3D<TYPE_COORDINATES, TYPE_LABEL>::operator-() {
	LabeledVector2D<TYPE_COORDINATES, TYPE_LABEL>::operator-();
	SetZ(-GetZ());
	return *this;
}

template <class TYPE_COORDINATES, class TYPE_LABEL>
std::ostream& LabeledVector3D<TYPE_COORDINATES, TYPE_LABEL>::operator<< (std::ostream& offstream)
{
	LabeledVector2D<TYPE_COORDINATES, TYPE_LABEL>::operator<<(offstream);
	offstream << "Z " << GetZ() << std::endl;

	return offstream;
}

template<typename COORDINATES, typename LABEL>
std::ostream& operator<<(std::ostream& offstream, LabeledVector3D<COORDINATES, LABEL>& vector)
{
	return vector.operator<<(offstream);
}

template <class TYPE_COORDINATES, class TYPE_LABEL>
std::istream& LabeledVector3D<TYPE_COORDINATES, TYPE_LABEL>::operator>>(std::istream& instream)
{
	LabeledVector2D<TYPE_COORDINATES, TYPE_LABEL>::operator>>(instream);
	TYPE_COORDINATES coordinate;

	cout << "Z = ";
	instream >> coordinate;
	SetZ(coordinate);

	return instream;
}

template<typename COORDINATES, typename LABEL>
std::istream& operator>> (std::istream& in, LabeledVector3D<COORDINATES, LABEL>& vector)
{
	return vector.operator>>(in);
}

template <class TYPE_COORDINATES, class TYPE_LABEL>
LabeledVector3D<TYPE_COORDINATES, TYPE_LABEL> LabeledVector3D<TYPE_COORDINATES, TYPE_LABEL>::operator+(const LabeledVector3D<TYPE_COORDINATES, TYPE_LABEL>& vectorToAdd)
{
	LabeledVector3D<TYPE_COORDINATES, TYPE_LABEL> resultVector;

	LabeledVector2D<TYPE_COORDINATES, TYPE_LABEL> resultAdd = LabeledVector2D<TYPE_COORDINATES, TYPE_LABEL>::operator+(vectorToAdd);
	resultVector.SetZ(vectorToAdd.GetZ() + GetZ());
	
	return resultVector;
}

template <class TYPE_COORDINATES, class TYPE_LABEL>
LabeledVector3D<TYPE_COORDINATES, TYPE_LABEL>::~LabeledVector3D()
{}

template <class TYPE_COORDINATES, class TYPE_LABEL>
TYPE_COORDINATES LabeledVector3D<TYPE_COORDINATES, TYPE_LABEL>::GetZ() const { return m_z; }

template <class TYPE_COORDINATES, class TYPE_LABEL>
void LabeledVector3D<TYPE_COORDINATES, TYPE_LABEL>::SetZ(TYPE_COORDINATES z) { this->m_z = z; }

template <class TYPE_COORDINATES, class TYPE_LABEL>
TYPE_COORDINATES LabeledVector3D<TYPE_COORDINATES, TYPE_LABEL>::DistanceToCenter()
{
	return sqrt(
		Vector2D <TYPE_COORDINATES>::GetX() * Vector2D <TYPE_COORDINATES>::GetX() +
		Vector2D <TYPE_COORDINATES>::GetY() * Vector2D <TYPE_COORDINATES>::GetY() + 
		GetZ() * GetZ());
}

template <class TYPE_COORDINATES, class TYPE_LABEL>
void LabeledVector3D<TYPE_COORDINATES, TYPE_LABEL>::SetPoint(const LabeledVector3D<TYPE_COORDINATES, TYPE_LABEL>& vector)
{
	LabeledVector2D<TYPE_COORDINATES, TYPE_LABEL>::SetPoint(vector);
	SetLabel(vector.GetZ());
}