#include <iostream>

struct Rect {
	float m_width;
	float m_height;

	void Print();
	void Init(float width, float height);
	float Perimeter();
	float Area();
};

void Rect::Print() 
{
	std::cout << "Width = " << m_width << std::endl << "Height = " << this->m_height << std::endl;
}

void Rect::Init(float width, float height)
{
	this->m_width = width;
	m_height = height;
}

float Rect::Perimeter()
{
	return(m_height + m_width)*2.0;
}

float Rect::Area()
{
	return(m_height*m_width);
}

int main() {
	Rect rect;
	rect.Init(10.0, 5.0);

	Rect* pRect = &rect;
	std::cout << pRect->Area() << std::endl;
	std::cout << pRect->Perimeter() << std::endl;


	return 0;
}