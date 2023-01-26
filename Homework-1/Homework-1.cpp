/*Homework-1
Müslüm Türk
Program that shapes the stars according to the entered value*/

#include<iostream>
using namespace std;

void duzUcgen(int deger) //Makes a straight triangle shape
{
	int i,line = (deger + 1) / 2;
	for (i = 1; i <= line; ++i)
	{
		for (int j = 1; j <= line-i; ++j) 
			cout << " ";
		
		for (int k = 1; k <=i*2-1; ++k)
			cout << "*";
		
		cout << endl;
	}
}

void tersUcgen(int deger) // Makes an inverted triangle shape
{
	int line = (deger + 1) / 2;
	int i = line;
	
	while (i>0)
	{
		int a = line-i;
		while (a > 0) 
		{
			cout << " ";
			--a;
		}
		
		int b = i * 2 - 1;
		while (b > 0)
		{
			cout << "*";
			--b;
		}

		cout << endl;
		--i;
	}

}

void elmas(int deger) //Makes a diamond shape
{
	duzUcgen(deger);
	tersUcgen(deger);	
}

int main()
{
	int action;//Action to choose
	label://Returns here if an invalid action is selected
	cout << "1: Straight triangle" << endl << "2: Inverted triangle" << endl << "3: Diamond" << endl << "0: Exit" << endl;
	cout << "Choose an action: ";
	cin >> action;

	switch(action)
	{
	case 1://Calls the function that prints the inverted triangular shape after taking the size
	{
		int size;
		int incorrectCount = 0;

		while (incorrectCount < 3)
		{
			cout << "Enter the odd number value in the range [3,15]:";
			cin >> size;
			if (size >= 3 && size <= 15 && size % 2 == 1)
			{
				duzUcgen(size);
				return 0;
			}

			cout << "Incorrect value!" << endl;
			incorrectCount++;

		}

		cout << "Three incorrect value!";
		return 0;
	}
		
		break;
	case 2://Calls the function that prints the straight triangular shape after taking the size
	{
		int size;
		int incorrectCount = 0;

		while (incorrectCount < 3)
		{
			cout << "Enter the odd number value in the range [3,15]:";
			cin >> size;
			if (size >= 3 && size <= 15 && size % 2 == 1)
			{
				tersUcgen(size);
				return 0;
			}

			cout << "Incorrect value!" << endl;
			incorrectCount++;
		}
		cout << "Three incorrect value!";
		return 0;
	}
		break;
	case 3://Calls the function that prints the diamond shape after taking the size
	{
		int size;
		int incorrectCount = 0;

		while (incorrectCount < 3)
		{
			cout << "Enter the odd number value in the range [5,15]:";
			cin >> size;
			if (size >= 5 && size <= 15 && size % 2 == 1)
			{
				elmas(size);
				return 0;
			}

			cout << "Incorrect value!" << endl;
			incorrectCount++;

		}

		cout << "Three incorrect value!";
		return 0;
	}
	case 0://exits the program
		return 0;
	default://Returns to the selection screen if an invalid action is selected
		cout << "Invalid transaction!" << endl << endl;
		goto label;
		break;
	}
	return 0;
}
