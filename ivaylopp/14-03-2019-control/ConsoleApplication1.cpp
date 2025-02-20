// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Point3.h"
#include "Triangle.h"
using namespace std;

void Input(int n, Point3 array[]) {
	int t_x, t_y, t_z;
	for (int i = 0; i < n; i++) {
		cout << "Input coords for point " << i << endl;
		cout << "X="; cin >> t_x; array[i].SetX(t_x);
		cout << "Y="; cin >> t_y; array[i].SetY(t_y);
		cout << "Z="; cin >> t_z; array[i].SetZ(t_z);
		cout << endl;
	}
}

void Symmetry(int n, Point3 array[]) {
	for (int i = 0; i < n; i++)
		array[i] = array[i].GetSymetry();
}

void Output(int n, Point3 array[]) {
	for (int i = 0; i < n; i++) {
		cout << "A[" << i << "].x = " << array[i].GetX() << endl;
		cout << "A[" << i << "].y = " << array[i].GetY() << endl;
		cout << "A[" << i << "].z = " << array[i].GetZ() << endl;
		cout << endl;
	}
}

int main()
{
	Point3 pA, pB(1, 2, 5);
	cout << "A.x = " << pA.GetX() << endl;
	cout << "A.y = " << pA.GetY() << endl;
	cout << "A.z = " << pA.GetZ() << endl;
	cout << "B.x = " << pB.GetX() << endl;
	cout << "B.y = " << pB.GetY() << endl;
	cout << "B.z = " << pB.GetZ() << endl;
	cout << endl;

	pA.SetX(1);
	pB.SetY(-1);
	cout << "A.x = " << pA.GetX() << endl;
	cout << "A.y = " << pA.GetY() << endl;
	cout << "A.z = " << pA.GetZ() << endl;
	cout << "B.x = " << pB.GetX() << endl;
	cout << "B.y = " << pB.GetY() << endl;
	cout << "B.z = " << pB.GetZ() << endl;
	cout << endl;

	pA.TranslateByVector(pB);
	cout << "A.x = " << pA.GetX() << endl;
	cout << "A.y = " << pA.GetY() << endl;
	cout << "A.z = " << pA.GetZ() << endl;
	cout << endl;

	Point3 pAs = pA.GetSymetry();
	cout << "sA.x = " << pAs.GetX() << endl;
	cout << "sA.y = " << pAs.GetY() << endl;
	cout << "sA.z = " << pAs.GetZ() << endl;
	cout << endl;
	
	Triangle ABC;
	cout << "P(ABC) = " << ABC.GetPerimeter();
	cout << endl;

	Point3 arr[4];
	Output(4, arr);

	Input(4, arr);
	Output(4, arr);

	Symmetry(4, arr);
	Output(4, arr);

	system("pause");
    return 0;
}

