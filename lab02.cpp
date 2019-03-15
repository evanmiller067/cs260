//Lab 02 Evan Miller 2.9.19 cs260
#include <iostream>

using namespace std;

void recursivePrint(int, int);

int main()
{
	cout << " The numbers 0 to 100 printed recursively: ";
	recursivePrint(1, 100);

	cout << " The numbers 100 to 0 printed recursively: ";
	recursivePrint(100, 1); 
}

void recursivePrint(int start, int end)
{
	if(start < end)
	{
		recursivePrint(start, end -1);
		cout << end << ", ";
	}
	else if(start > end)
	{
		recursivePrint(start, end+1);
		cout << end << ", ";
	}
	else
	{
		cout << start << ", ";
	}
}
