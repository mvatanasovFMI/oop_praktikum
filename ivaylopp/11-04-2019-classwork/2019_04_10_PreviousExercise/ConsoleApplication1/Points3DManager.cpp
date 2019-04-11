#include "pch.h"
#include "Point3DManager.h"

void Point3DManager::Input(int n, Point3D arr[])
{
	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}
}

void Point3DManager::Symmetry(int n, Point3D arr[])
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = -arr[i];
	}
}


