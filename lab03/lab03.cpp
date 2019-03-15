/*
After you have setup your lab directory it's time to write a program.  You
will write a program that simulates an investment account balance over the
course of a few years.  This investment account has a fixed annual return rate
and the interest is compounding yearly.  That means that you add the amount
gained due to interest each year to the existing balance.

Your program will start by reading in the starting balance, interest rate, and
number of years.  They it will print a table showing the balance each
year. All inputs should be integers.

Here is an example run of the program:

Enter starting balance: 5000
Enter interest rate: 5
Enter number of years: 10

Year 1 $5250.0
Year 2 $5512.5
Year 3 $5788.125
Year 4 $6077.53125
Year 5 $6381.4078125
Year 6 $6700.478203125
Year 7 $7035.50211328125
Year 8 $7387.277218945313
Year 9 $7756.641079892578
Year 10 $8144.473133887207

Your program should generate the same output (it's ok if the number of decimal
places is different) as this example.
*/

//Evan Miller
//Lab03 CS260

#include <iostream>
using namespace std;

int main()
{
	double startingBal = 0;
	double interestRate = 0;
	double years = 0;

	cout << "Enter starting balance: ";
	cin >> startingBal;
	cout << "\n Enter interest rate: ";
	cin >> interestRate;
	cout << "\n Enter number of years: ";
	cin >> years;

	double interest = 0;
	int i = 1;
	while( i <= years)
	{
		double interest = ((startingBal * interestRate)/100);
		cout << "Year " << i << " " <<  startingBal + interest << endl;
		startingBal = startingBal + interest;
		i++;
	}

}
