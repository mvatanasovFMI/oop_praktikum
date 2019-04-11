#include "pch.h"
#include "Point3DManager.h"


void Point3DManager::Input(int n, Point3D arr[])
{
	double x, y, z;
	for (int i = 0; i < n; i++)
	{
		std::cin >> x >> y >> z;
		arr[i].SetX(x);
		arr[i].SetY(y);
		arr[i].SetZ(z);
	}
}

void Point3DManager::Symmetry(int n, Point3D arr[])
{
	for (int i = 0; i < n; i++)
	{
		arr[i].GetSymetry();
	}
}