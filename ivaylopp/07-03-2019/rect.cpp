// ConsoleApplication7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct Rect {
	float m_width;
	float m_height;
	
	void Print()
	{
		cout << "Width = " << m_width << endl << "\nHeigth = " << m_height << endl;
	}
	void Init(float width, float height);
	float Perimeter();
	float Area();
};

void Rect::Init(float width, float height)
{
	this->m_width = width;
	m_height = height;
}

float Rect::Perimeter()
{
	return (m_height + m_width) * 2;
}

float Rect::Area()
{
	return m_height * m_width;
}

int main()
{
	Rect rect;
	rect.Init(7.0, 9.0);
	Rect* pRect = &rect;
	cout << "Area= " << pRect->Area() << endl;
	cout << "Perimeter= " << pRect->Perimeter() << endl;
	system("pause");
    return 0;
}
