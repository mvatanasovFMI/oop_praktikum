#include "pch.h"
#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

int main()
{
	fstream* myfile;
	myfile = new fstream(); 
	myfile->open("myfirstfile.txt");
	*myfile << "Hello Stream"<< endl;
	myfile->close();
	delete myfile;
	return 0;
}
