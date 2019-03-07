#include <iostream>
using namespace std;
struct Rect {
	float m_width;
	float m_height;

	
	void Print();
	void Init(float width, float height);
	float Perimeter();
	float Area();
};
void Rect::Print() {
	cout << "Width = " << m_width << endl << "Height = " << this->m_height << endl;
}
void Rect::Init(float width, float height)
{
	this->m_width = width;
	m_height = height;
}

float Rect:: Perimeter()
{
	return (m_height + m_width)*2.0;
}

float Rect::Area()
{
	return m_height*m_width;
}

int main()
{
	Rect rect;
	rect.Init(10.0, 15.0);
	Rect* ptrrect = &rect;
	cout << ptrrect->Area() << endl;
	cout<< ptrrect->Perimeter()<<endl;

	return 0;
}