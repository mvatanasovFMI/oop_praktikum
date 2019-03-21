// 2019_03_21_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	fstream fileName;
	fileName.open("MYFIRSTFILE.txt");
	fileName << "Hello Stream!" << endl;
	fileName.close();

	fstream* OtherFileName = new fstream();
	OtherFileName->open("MYSECONDFILE.txt");
	*OtherFileName << "Hello Stream!" << endl;
	OtherFileName->close();
	delete OtherFileName;

	system("pause");
	return 0;
}


