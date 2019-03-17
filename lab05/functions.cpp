#include "functions.h"
#include <iostream>
using namespace std;
//cout's added to main.cpp for functions
void doAverage(int x,int y) 
{
  int sum = x+y;
  int average = sum/2;
  cout << "Average of " << x << " and " << y << " is " << average << endl;
}
int doGCD(int x, int y)
{
	if(x == 0 || y == 0)
	{
		return 0;
	}
	if(x == y)
	{
		return x;
	}
	if(x > y)
	{
		return doGCD(x-y, y);
	}
	return doGCD(x, y-x);
}
int doLCM(int x, int y)
{
	return (x*y)/doGCD(x,y);
}
