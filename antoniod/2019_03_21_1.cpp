// 2019_03_21_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream fileName("MYFIRSTFILE1.txt", ios::out);
	
	fileName << "Hello Stream!" << endl;
	fileName.close();

	//ofstream* OtherFileName = new ofstream();
	//OtherFileName->open("MYSECONDFILE.txt");
	//OtherFileName->operator<< "Hello Stream!" << endl;
	//OtherFileName->close();
	//delete OtherFileName;

	system("pause");
	return 0;
}


