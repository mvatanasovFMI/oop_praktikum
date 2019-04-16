#pragma once
#include "stdafx.h"
#include "Point3D.hpp"

template <class T>
class Point3DManager
{
public:
	static void Output(double size, Point3D<T> points[])
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << points[i];// .Print();
		}
	}
	static void Input(int n, Point3D<T> arr[]);
	static void Symmetry(int n, Point3D<T> arr[]);
	
};