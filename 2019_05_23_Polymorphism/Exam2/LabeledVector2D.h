#pragma once

#pragma once

//Задача 2.
//
//Създайте клас LabeledLabeledVector2DD<ТYPE_COORDINATES, TYPE_LABEL>, който наследява LabeledVector2DD<ТYPE_COORDINATES> и има допълнителна информация, която идентифицира вектора - TYPE_LABEL  label.
//
//Класа трябва да съдържа в себе си :
//
//-Конструктор с подразбиращи параметри
//
//- Copy конструктор
//
//- Деструктор
//
//- Set и Get методи за label
//
//- Предефинирайте наследените методи, където е необходимо.
#include <iostream>
#include <string>
#include "Vector2D.h"

using namespace std;

template <class TYPE_COORDINATES, class TYPE_LABEL>
class LabeledVector2D: public Vector2D<TYPE_COORDINATES>
{
public:
	LabeledVector2D(TYPE_COORDINATES = 0, TYPE_COORDINATES = 0);
	LabeledVector2D(const  LabeledVector2D<TYPE_COORDINATES, TYPE_LABEL>& point);
	LabeledVector2D<TYPE_COORDINATES, TYPE_LABEL>& operator=(const  LabeledVector2D<TYPE_COORDINATES, TYPE_LABEL>& point);
	~LabeledVector2D();

	TYPE_LABEL GetLabel() const;
	void SetLabel(TYPE_LABEL);
	
	TYPE_COORDINATES DistanceToCenter()
	{
		return 100 * sqrt(
			Vector2D <TYPE_COORDINATES>::GetX() * Vector2D <TYPE_COORDINATES>::GetX() +
			Vector2D <TYPE_COORDINATES>::GetY() * Vector2D <TYPE_COORDINATES>::GetY()); // 100 is just for testing
	}

	void SetPoint(const LabeledVector2D<TYPE_COORDINATES, TYPE_LABEL>& vector);

	LabeledVector2D<TYPE_COORDINATES, TYPE_LABEL>& operator-();
	LabeledVector2D<TYPE_COORDINATES, TYPE_LABEL> operator+(const LabeledVector2D<TYPE_COORDINATES, TYPE_LABEL>& vectorToAdd);

	std::ostream& operator<< (std::ostream& o);
	std::istream& operator>> (std::istream& o);

	//FIX Review class vs typename
	template<typename COORDINATES, typename LABEL>
	friend std::ostream& operator<<(std::ostream& out, LabeledVector2D<COORDINATES, LABEL>& node);

	template<typename COORDINATES, typename LABEL>
	friend std::istream& operator>> (std::istream& in, LabeledVector2D<COORDINATES, LABEL>& vector);

private:
	TYPE_LABEL m_label;
};

//FIX to be reviewed
template <class TYPE_COORDINATES, class TYPE_LABEL>
LabeledVector2D<TYPE_COORDINATES, TYPE_LABEL>::LabeledVector2D(TYPE_COORDINATES x, TYPE_COORDINATES y): Vector2D<TYPE_COORDINATES>(x, y)
{
	
}

template <class TYPE_COORDINATES, class TYPE_LABEL>
LabeledVector2D<TYPE_COORDINATES, TYPE_LABEL>::LabeledVector2D(const LabeledVector2D<TYPE_COORDINATES, TYPE_LABEL>& point): Vector2D<TYPE_COORDINATES>(point)
{
	SetLabel(point.GetLabel());
}

template <class TYPE_COORDINATES, class TYPE_LABEL>
LabeledVector2D<TYPE_COORDINATES, TYPE_LABEL>& LabeledVector2D<TYPE_COORDINATES, TYPE_LABEL>::operator=(const LabeledVector2D<TYPE_COORDINATES, TYPE_LABEL>& point)
{
	if (this != &point)
	{
		Vector2D<TYPE_COORDINATES>::operator=(point);
		SetLabel(point.GetLabel());
	}

	return *this;
}

template <class TYPE_COORDINATES, class TYPE_LABEL>
LabeledVector2D<TYPE_COORDINATES, TYPE_LABEL>& LabeledVector2D<TYPE_COORDINATES, TYPE_LABEL>::operator-() {
	Vector2D<TYPE_COORDINATES>::operator-();
	
	return *this;
}

template <class TYPE_COORDINATES, class TYPE_LABEL>
std::ostream& LabeledVector2D<TYPE_COORDINATES, TYPE_LABEL>::operator<< (std::ostream& offstream)
{
	Vector2D<TYPE_COORDINATES>::operator<<(offstream);
	offstream << "Label = " << GetLabel() << std::endl;

	return offstream;
}

template<typename COORDINATES, typename LABEL>
std::ostream& operator<<(std::ostream& offstream, LabeledVector2D<COORDINATES, LABEL>& vector)
{
	return vector.operator<<(offstream);
}

template <class TYPE_COORDINATES, class TYPE_LABEL>
std::istream& LabeledVector2D<TYPE_COORDINATES, TYPE_LABEL>::operator>>(std::istream& instream)
{
	Vector2D<TYPE_COORDINATES>::operator>>(instream);
	TYPE_LABEL label;
	cout << "Label = ";
	instream >> label;
	SetLabel(label);
	
	return instream;
}

template<typename COORDINATES, typename LABEL>
std::istream& operator>> (std::istream& in, LabeledVector2D<COORDINATES, LABEL>& vector)
{
	return vector.operator>>(in);
}

template <class TYPE_COORDINATES, class TYPE_LABEL>
LabeledVector2D<TYPE_COORDINATES, TYPE_LABEL> LabeledVector2D<TYPE_COORDINATES, TYPE_LABEL>::operator+(const LabeledVector2D<TYPE_COORDINATES, TYPE_LABEL>& vectorToAdd)
{
	LabeledVector2D<TYPE_COORDINATES, TYPE_LABEL> resultVector;

	Vector2D<TYPE_COORDINATES> resultAdd = Vector2D<TYPE_COORDINATES>::operator+(vectorToAdd);
	resultVector.SetX(resultAdd.GetX());
	resultVector.SetY(resultAdd.GetY());
	resultVector.SetLabel(vectorToAdd.GetLabel());

	return resultVector;
}

template <class TYPE_COORDINATES, class TYPE_LABEL>
LabeledVector2D<TYPE_COORDINATES, TYPE_LABEL>::~LabeledVector2D()
{}

template <class TYPE_COORDINATES, class TYPE_LABEL>
TYPE_LABEL LabeledVector2D<TYPE_COORDINATES, TYPE_LABEL>::GetLabel() const { return m_label; }

template <class TYPE_COORDINATES, class TYPE_LABEL>
void LabeledVector2D<TYPE_COORDINATES, TYPE_LABEL>::SetLabel(TYPE_LABEL label) { this->m_label = label; }

template <class TYPE_COORDINATES, class TYPE_LABEL>
void LabeledVector2D<TYPE_COORDINATES, TYPE_LABEL>::SetPoint(const LabeledVector2D<TYPE_COORDINATES, TYPE_LABEL>& vector)
{
	Vector2D<TYPE_COORDINATES>::SetPoint(vector);
	SetLabel(vector.GetLabel());
}
