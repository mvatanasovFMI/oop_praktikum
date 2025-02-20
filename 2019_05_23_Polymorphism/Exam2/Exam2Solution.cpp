// Exam2Solution.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
//#include "Vector2D.h"
//#include "LabeledVector2D.h"
#include "LabeledVector3D.h"

using namespace std;

int main()
{
	//Problem 1
	Vector2D<double> vectorToTest;
	std::cout << "Before set 1 3" << endl << vectorToTest << endl;
	vectorToTest.SetX(1);
	vectorToTest.SetY(3);
	Vector2D<double> sum = (vectorToTest + vectorToTest);
	cout << sum << endl;;
    
	cin >> vectorToTest;
	vectorToTest = -vectorToTest;
	cout << "-vector = " << endl << vectorToTest << endl;

	cout << "distance = " << vectorToTest.DistanceToCenter() << endl;

	//Problem 2
	LabeledVector2D<double, string> labeledVectorToTest;
	std::cout << "Before set 1 2 " << endl << labeledVectorToTest << endl;
	labeledVectorToTest.SetX(1);
	labeledVectorToTest.SetY(2);
	labeledVectorToTest.SetLabel("Label One");
	LabeledVector2D<double, string> sumLabeled = (labeledVectorToTest + labeledVectorToTest);
	cout << sumLabeled << endl;;

	cin >> labeledVectorToTest;
	labeledVectorToTest = -labeledVectorToTest;
	cout << "-vector = " << endl << labeledVectorToTest << endl;

	cout << "distance = " << labeledVectorToTest.DistanceToCenter() << endl;

	//Problem 3
	LabeledVector3D<double, string> vector3DToTest;
	std::cout << "Before set 1 2 " << endl << vector3DToTest << endl;
	vector3DToTest.SetX(1);
	vector3DToTest.SetY(2);
	vector3DToTest.SetLabel("Label One");
	LabeledVector3D<double, string> sum3DLabeled = (vector3DToTest + vector3DToTest);
	cout << sum3DLabeled << endl;;

	cin >> vector3DToTest;
	vector3DToTest = -vector3DToTest;
	cout << "-vector = " << endl << vector3DToTest << endl;

	cout << "distance = " << vector3DToTest.DistanceToCenter() << endl;

	
	////Polymorphism Test
	//Vector2D<double> testVector2d = Vector2D<double>(3, 4.2);
	//LabeledVector2D<double, string> testLabeledVector2d = LabeledVector2D<double, string>(3, 4.2);
	//LabeledVector3D<double, string> testLabeledVector3d = LabeledVector3D<double, string>(3, 4.2, 10);
	////Test 
	//cout << endl << endl << "test 1" << endl;
	//Vector2D<double> base = testVector2d;
	//cout << base << base.DistanceToCenter()<< endl;
	//base = testLabeledVector2d;
	//cout << base << base.DistanceToCenter() << endl;
	//base = testLabeledVector3d;
	//cout << base << base.DistanceToCenter() << endl;

	////Test 2
	//cout << endl << endl << "test 2 by ref" << endl; // when virtual , maybe dynamic cast
	//Vector2D<double> & baseByRef = testVector2d;
	//cout << baseByRef << baseByRef.DistanceToCenter() << endl;
	//baseByRef = testLabeledVector2d;
	//cout << baseByRef << baseByRef.DistanceToCenter() << endl;
	//baseByRef = testLabeledVector3d;
	//cout << baseByRef << baseByRef.DistanceToCenter() << endl;

	////Test 3
	//cout << endl << endl << "test 3 by pointer" << endl;
	//Vector2D<double> * baseByPointer = &testVector2d;
	//cout << *baseByPointer << baseByPointer->DistanceToCenter() << endl;
	//baseByPointer = &testLabeledVector2d;
	//cout << *baseByPointer << baseByPointer->DistanceToCenter() << endl;
	//baseByPointer = &testLabeledVector3d;
	//cout << *baseByPointer << baseByPointer->DistanceToCenter() << endl;



}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

//Създайте клас Vector2D<ТYPE_COORDINATES>.
//
//Класа трябва да съдържа в себе си :
//
//-Конструктор с подразбиращи параметри
//
//- Copy конструктор
//
//- Деструктор
//
//- Set и Get методи за X и Y координатите
//
//- Предефинирани оператори(=, +(инфиксен), -(префиксен), << , >> )
//
//- Метод за намиране на големината на вектора
//
//
//
//Задача 2.
//
//Създайте клас LabeledVector2D<ТYPE_COORDINATES, TYPE_LABEL>, който наследява Vector2D<ТYPE_COORDINATES> и има допълнителна информация, която идентифицира вектора - TYPE_LABEL  label.
//
//Класа трябва да съдържа в себе си :
//
//-Конструктор с подразбиращи параметри
//
//- Copy конструктор
//
//- Деструктор
//
//- Set и Get методи за label
//
//- Предефинирайте наследените методи, където е необходимо.
//
//Задача 3.
//
//Създайте клас LabeledVector3D<ТYPE_COORDINATES, TYPE_LABEL>, който наследява LabeledVector2D<ТYPE_COORDINATES, TYPE_LABEL>.
//
//Класа трябва да съдържа в себе си :
//
//-Конструктор с подразбиращи параметри
//
//- Copy конструктор
//
//- Деструктор
//
//- Set и Get методи за z координатата
//
//- Предефинирайте наследените методи, където е необходимо.
//
//Задача 4. В Main фукнцията създайте инстанции от класовете LabeledVector3D<double, int> и LabeledVector3D<int, string>, като осигурете извикване на всички методи в класа LabeledVector3D(включително наследените)