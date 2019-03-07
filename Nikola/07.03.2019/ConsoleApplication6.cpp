// ConsoleApplication6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;
struct Rect 
{
	float m_width;
	float m_height;
	void Print();
	void Init(float width, float height);
	float Perimetur();
};

void Rect::Print()
{
	cout << "width = " << m_width << endl << "Height = " << m_height << endl;
}

float Rect::Perimetur()
{

	return 2 * (m_width + m_height);
}

void Rect::Init(float width, float height)
{
	this->m_width = width;
	m_height = height;
}

int main()
{
	
	Rect rect;
	rect.Init(4, 5);
	rect.Print();
	Rect  *point;
	point = &rect;
	cout<<point->Perimetur();
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
