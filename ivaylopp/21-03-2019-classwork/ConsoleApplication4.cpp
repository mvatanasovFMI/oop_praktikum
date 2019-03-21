// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>

using namespace std;

int main()
{
	ofstream myfile;
	myfile.open("myfirstfile.txt");
	myfile << "Hello stream";
	myfile.close();

	ofstream* file = new ofstream();
	file->open("mysecondfile.txt");
	*file << "Hello stream";
	file->close();
	delete file;
    return 0;
}

