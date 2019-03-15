#include <iostream>
#include "resultdata.h"

using namespace std;

void resultdata::add(int ID, int x, int y, int corescan)
{
	data[0] = ID;
	data[1] = x;
	data[2] = y;
	data[3] = corescan;
}
void resultdata::print()
{
	cout << "Reading from rover #" << data[0];
	cout << " at " << data[1] << ", ";
	cout << data[2] << " is " << data[3] << endl;
}
