/*
Evan Miller 
cs260
3.3.19
*/

#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int temp;
	int count = 0;
	vector<int> numbers;
	cout << "How many values will you enter: ";
	cin >> count;
	cout << endl;
	for(int i = 0; i < count; i++)
	{
		cout << "Enter a number between 0 and 10 (inclusive): ";
		cin >> temp;
		if(temp >= 0 && temp < 11)
		{	
		numbers.push_back(temp);
		}
		else
		{
		cout << "Invalid value. Try again." << endl;
		}
	}
	for(int i = 10; i > 0; i--)
	{
		for(int n : numbers)
		{
			if(n >= i)
			{
				cout << "*";
				count--;
			}
			else
			{
				cout << " ";
			}
		}	
		cout << endl;
	}
	/*
	//for testing 
	cout <<"input count: " <<  count << endl;
	cout << "number vector: ";
	for(int n : numbers)
	{
	cout << n << ' ';
	}
	cout << endl;
	*/
	return 0;
}

