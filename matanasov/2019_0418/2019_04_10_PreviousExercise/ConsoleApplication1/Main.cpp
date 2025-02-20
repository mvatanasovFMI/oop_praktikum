// KontrolnoPredi.cpp : Defines the entry point for the console application.
//
#include "pch.h"
#include "stdafx.h"
#include <iostream>
#include "Point3D.hpp"
#include "Triangle.hpp"
#include "Point3DManager.hpp"



//https://www.codeproject.com/Articles/48575/How-to-define-a-template-class-in-a-h-file-and-imp
int main()
{
	Point3D<double> point(3.0);
	std::cin >> point;

	Point3D<double> copyOfPoint = point;
	std::cout << point;
	point.TranslateByVector(Point3D<double>(3, 1, 0));

	
	point = -point;
	
	std::cout << point.GetX() << ", " << point.GetY() << ", " << point.GetZ() << std::endl;
	Point3D<double> points[3];
	
	points[0] = Point3D<double>(1, 0, 0);
	points[1] = Point3D<double>(1, 1, 0)++;
	points[2] = --Point3D<double>(0, 1, 0);

	Triangle<double> tr;
	tr.SetA(points[0]);
	tr.SetB(points[1]);
	tr.SetC(points[2]);

	double perimeter = tr;
	std::cout << perimeter << std::endl;
	std::cout << tr.GetPerimeter() << std::endl;
	std::cout << tr.GetPerimeterAlt();

	std::cout << points[0];
	Point3DManager<double>::Input(1, points);
	Point3DManager<double>::Symmetry(3, points);
	Point3DManager<double>::Output(3, points);
	
	std::cin.get();
	return 0;
}

