#include "pch.h"
#include <iostream>
#include <math.h>

using namespace std;
class Point
{
private:
	double m_x;

	double m_y;

	double m_z;

public:

	Point(double = 0, double = 0, double = 0);

	double getx();

	double gety();

	double getz();

	void setx(double a);

	void sety(double a);

	void setz(double a);

	void TranslateByVector(Point& vector);

	Point& GetSymetry();
	
	double Lenght(Point f);

	void kajix() {
		cout << m_x;
	}

};

void Input(int n, Point arr[]) {

	int a, b, c, i;
	for (i = 0; i < n; i++) {
		cin >> a >> b >> c;
		arr[i].setx(a);
		arr[i].sety(b);
		arr[i].setz(c);
	}

}

void Symmetry(int n, Point arr[]) {
	int i,a,b,c;
	for (i = 0; i < n; i++) {
		a = arr[i].getx();
		b = arr[i].gety();
		c = arr[i].getz();
		arr[i].setx(-a);
		arr[i].sety(-b);
		arr[i].setz(-c);
	}
}

void Output(int n, Point arr[]) {

	int a, b, c, i;
	for (i = 0; i < n; i++) {
		cout << arr[i].getx();
		cout << arr[i].gety();
		cout << arr[i].getz();
	}

}

double Point::Lenght(Point f) {
	double a, b, c, s, e, p, g;
	a = f.getx();
	b = f.gety();
	c = f.getz();
	e = abs(a - m_x);
	p = abs(b - m_y);
	g = abs(c - m_z);
	s = sqrt(pow(e, 2) + pow(p, 2) + pow(g, 2));
	return s;
}

Point& Point::GetSymetry() {
	double a, b, c;
	Point Sym;
	a = m_x;
	b = m_y;
	c = m_z;
	Sym.setx(-a);
	Sym.sety(-b);
	Sym.setz(-c);
	return Sym;
};

Point::Point(double a, double b, double c) {
	m_x = a;
	m_y = b;
	m_z = c;
}

void Point::TranslateByVector(Point& vector) {
	double a, b, c;
	a = vector.getx() + m_x;
	b = vector.gety() + m_y;
	c = vector.getz() + m_z;
	m_x = a;
	m_y = b;
	m_z = c;
}

double Point::getx() {
	return m_x;
}

double Point::gety() {
	return m_y;
}

double Point::getz() {
	return m_z;
}

void Point::setx(double a) {
	m_x = a;
 }

void Point::sety(double a) {
	m_y = a;
}

void Point::setz(double a) {
	m_z = a;
}

class Triangle
{
private:
	Point m_a;

	Point m_b;

	Point m_c;

public:
	Triangle(){};
	Triangle(Point a, Point b, Point c);

	void SetA(Point& t);

	void SetB(Point& t);

	void SetC(Point& t);

	double GetPerimeter();


};

double Triangle::GetPerimeter() {
	double a, b, c, p;

	a = m_a.Lenght(m_b);
	b = m_b.Lenght(m_c);
	c = m_c.Lenght(m_a);
	p = a + b + c;
	return p;

}

void Triangle::SetA(Point& t) {
	double a, b, c;
	a = t.getx();
	b = t.gety();
	c = t.getz();
	m_a.setx(a);
	m_a.sety(b);
	m_a.setz(c);
}

void Triangle::SetB(Point& t) {
	double a, b, c;
	a = t.getx();
	b = t.gety();
	c = t.getz();
	m_b.setx(a);
	m_b.sety(b);
	m_b.setz(c);
}

void Triangle::SetC(Point& t) {
	double a, b, c;
	a = t.getx();
	b = t.gety();
	c = t.getz();
	m_c.setx(a);
	m_c.sety(b);
	m_c.setz(c);
}

Triangle::Triangle(Point a, Point b, Point c) {
	double a1, b1, c1, a2, b2, c2, a3, b3, c3;
	a1 = a.getx();
	b1 = a.gety();
	c1 = a.getz();
	a2 = b.getx();
	b2 = b.gety();
	c2 = b.getz();
	a3 = c.getx();
	b3 = c.gety();
	c3 = c.getz();
	m_a.setx(a1);
	m_a.sety(b1);
	m_a.setz(c1);
	m_b.setx(a2);
	m_b.sety(b2);
	m_b.setz(c2);
	m_c.setx(a3);
	m_c.sety(b3);
	m_c.setz(c3);
}

int main()
{ 
	double a, b, c, e, f, g,a2,b2,c2,p;
	cin >> a >> b >> c >> e >> f >> g >> a2 >> b2 >> c2;
	Point pesho;
	Point gosho;
	Point tosho;
	pesho.setx(a);
	pesho.sety(b);
	pesho.setz(c);
	gosho.setx(e);
	gosho.sety(f);
	gosho.setz(g);
	tosho.setx(a);
	tosho.sety(b);
	tosho.setz(c);
	cout << pesho.getx() <<"  \n";
	cout << pesho.gety() <<"  \n";
	cout << pesho.getz() <<"  \n";
	pesho.TranslateByVector(gosho);
	cout << pesho.getx() << "  \n";
	cout << pesho.gety() << "  \n";
	cout << pesho.getz() << "  \n";
	Triangle tr1;
	tr1.SetA(pesho);
	tr1.SetB(gosho);
	tr1.SetC(tosho);
	p = tr1.GetPerimeter();
	cout << "\n" << p;
	

	return 0;
}
