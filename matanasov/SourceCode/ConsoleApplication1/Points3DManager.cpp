#include "pch.h"
#include "Point3DManager.h"

void Point3DManager::Input(int n, Point3D arr[])
{
	for (int i = 0; i < n; i++)
	{
		std::cout << "Point number " << n + 1 << std::endl;
		//std::cin >> 
		arr[i].operator>>(std::cin);
	}
}

void Point3DManager::Symmetry(int n, Point3D arr[])
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = -arr[i];
	}
}
