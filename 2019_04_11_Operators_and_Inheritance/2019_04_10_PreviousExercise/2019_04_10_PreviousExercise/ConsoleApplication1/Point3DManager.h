#pragma once
#include "stdafx.h"
#include "Point3D.h"

class Point3DManager
{
public:
	static void Output(double size, const Point3D* points)
	{
		for (int i = 0; i < size; i++)
		{
			points[i].Print();
		}
	}
		// Make manager with static fields Manager::Input(3, points)
	/*Symmetry(3, points);
	Output(3, points);*/
};