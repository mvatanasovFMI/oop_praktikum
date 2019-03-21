// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <fstream>
#include <iostream>

using namespace std;
int main()
{
	//fstream fileName("MYFIRSTFILE.txt", ios::out);

	//fileName << "Hello Stream!" << endl;
	//fileName.close();

	//ofstream* OtherFileName = new ofstream();
	//OtherFileName->open("MYSECONDFILE.txt");
	//OtherFileName->operator<< "Hello Stream!" << endl;
	//OtherFileName->close();
	//delete OtherFileName;

	fstream NewFile("MYFIRSTFILE.txt", ios::out | ios::in | ios::app);
	NewFile << "Hello Stream!" << endl;
	NewFile.close();

	system("pause");
	return 0;
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
