#pragma once
#include "pch.h"
#include "Point3DManager.h"

template <class T>
void Point3DManager<T>::Input(int n, Point3D<T> arr[])
{
	for (int i = 0; i < n; i++)
	{
		std::cout << "Point number " << n + 1 << std::endl;
		//std::cin >> 
		arr[i].operator>>(std::cin);
	}
}

template <class T>
void Point3DManager<T>::Symmetry(int n, Point3D<T> arr[])
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = -arr[i];
	}
}
