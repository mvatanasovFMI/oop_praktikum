#include <iostream>
using namespace std;
struct Rect
{
	float m_width;
	float m_height;
	void Init(float width, float height);
	void Print();
};

void Rect::Print()
{
	cout << "Width = " << m_width << endl << "Height = " << this->m_height << endl;
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
	system("pause");
	return 0;
}