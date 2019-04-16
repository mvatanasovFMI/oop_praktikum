#pragma once
#include "stdafx.h"
#include "Point3D.h"

class Point3DManager
{
public:
	static void Output(double size, Point3D points[])
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << points[i];// .Print();
		}
	}
	static void Input(int n, Point3D arr[]);
	static void Symmetry(int n, Point3D arr[]);
	
};