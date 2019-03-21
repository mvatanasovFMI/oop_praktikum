#include "pch.h"
#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

int main()
{
		ofstream myfile;
		myfile.open("myfirstfile.txt");
		myfile << "Hello Stream";
		myfile.close();
		return 0;
}
