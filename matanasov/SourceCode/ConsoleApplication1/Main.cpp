// KontrolnoPredi.cpp : Defines the entry point for the console application.
//
#include "pch.h"
#include "stdafx.h"
#include <iostream>
#include "Point3D.h"
#include "ColorPoint3D.h"
#include "Triangle.h"
#include "Point3DManager.h"




int main()
{
	Point3D point(3.0);
	std::cin >> point;

	ColorPoint3D colorPoint;
	colorPoint = ColorPoint3D(point, 0.2);

	ColorPoint3D copyColorPoint = colorPoint;
	std::cout << copyColorPoint;
	std::cin.get();
	//colorPoint
	/*Point3D copyOfPoint = point;
	std::cout << point;
	point.TranslateByVector(Point3D(3, 1, 0));

	
	point = -point;
	
	std::cout << point.GetX() << ", " << point.GetY() << ", " << point.GetZ() << std::endl;
	Point3D points[3];
	
	points[0] = Point3D(1, 0, 0);
	points[1] = Point3D(1, 1, 0)++;
	points[2] = --Point3D(0, 1, 0);

	Triangle tr;
	tr.SetA(points[0]);
	tr.SetB(points[1]);
	tr.SetC(points[2]);

	double perimeter = tr;
	std::cout << perimeter << std::endl;
	std::cout << tr.GetPerimeter() << std::endl;
	std::cout << tr.GetPerimeterAlt();

	std::cout << points[0];
	Point3DManager::Input(1, points);
	Point3DManager::Symmetry(3, points);
	Point3DManager::Output(3, points); 
	
	std::cin.get();*/

	return 0;
}

