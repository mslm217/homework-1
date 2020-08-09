/*Homework-2
Müslüm Türk
Program that processes complex numbers with member functions*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Complex
{
public:
	Complex() : real(0), imag(0)//Makes the complex number's default value 0
	{}
	Complex(int intNumb) :imag(intNumb), real(0)//Makes the integer number to complex number
	{}
	Complex(double doubleNumb) :imag(doubleNumb), real(0)//Makes the double number to complex number
	{}

	Complex(string stringNumb)//Makes the string to complex number
	{
		real = stoi(stringNumb);
		int i=0;
		int flag = 0;

		for(i=0;stringNumb[i]!='i';++i)
		{
			if (stringNumb[i] == '+' || (i != 0 && stringNumb[i] == '-'))
			{
				flag = 1;
				break;
			}	
			
		}
		for (i = 0;; ++i)
		{
			if (stringNumb[i] == '+' || (i!=0 && stringNumb[i] == '-') )
			{
				break;
			}
			else if (i == 0 && stringNumb[i] == '-' && flag==0)
			{
				real = 0;
				imag = stoi(stringNumb);
				break;
			}
		}
		char temp[20];
		int a = 0;
		if (stringNumb[i + 1] == ' ')
		{
			stringNumb[i + 1] = stringNumb[i];
			i = i + 1;
		}
		
		for (i; stringNumb[i] != 'i'; i++)
		{
			temp[a] = stringNumb[i];
			++a;
		}
		string tempString = temp;
		imag = stoi(tempString);

	}

	Complex(double a, double b)//Makes the double a and b to complex number
	{
		this->real = a;
		this->imag = b;
	}
	double getReal() const//Return the complex number's real value
	{
		return real;
	}
	void setReal(double real)//Set the complex number's real value
	{
		this->real = real;
	}
	double getÝmag() const//Return the complex number's imaginary value
	{
		return imag;
	}
	void setÝmag(double vrtl)//Set the complex number's imaginary value
	{
		this->imag = vrtl;
	}
	void add(Complex& a)//Adds the complex number to itself
	{
		this->real += a.real;
		this->imag += a.imag;
	}
	void subtract(Complex& a)//Subtracts the complex number with itself
	{
		this->real -= a.real;
		this->imag -= a.imag;
	}
	void divide(Complex& a)//Divides the complex number with itself
	{
		this->real /= a.real;
		this->imag /= a.imag;
	}
	void print()//Prints the complex number
	{
		if (imag < 0)
		{
			cout << real << imag << "i" << endl;
		}
		else
		{
			cout << real << "+" << imag << "i" << endl;
		}
	}

private://complex number's real and imaginary values
	double real;
	double imag;
};

bool vectorSort(vector<Complex>& vec)//Sorts the vector's real and imaginary values
{
	cout << endl << "Sorted of real values:" << endl;
	double arr[5];
	for (int i = 0; i < 5; i++)
	{
		arr[i] = vec[i].getReal();
	}
	double temp;
	for (int i = 0; i < 5; i++)
	{
		for (int j = i + 1; j < 5; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}

		}
		cout << arr[i] << " ";
	}
	cout << endl << "Sorted of imaginary values:" << endl;
	double arr2[5];
	for (int i = 0; i < 5; i++)
	{
		arr2[i] = vec[i].getÝmag ();
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = i + 1; j < 5; j++)
		{
			if (arr2[i] > arr2[j])
			{
				temp = arr2[j];
				arr2[j] = arr2[i];
				arr2[i] = temp;
			}

		}
		cout << arr2[i] << " ";
	}
	cout << endl;

	return true;
}

int main()
{
	Complex test1; //To test default constructor
	test1.print();
	
	Complex test2(7);//To test conversion constructor
	test2.print();

	Complex test3(6.485);//To test conversion constructor
	test3.print();

	Complex test4("5+3i");//To test constructor to convert string to complex number
	test4.print();

	Complex test5(4,8.354);//To test constructor to convert two double number to complex number
	test5.setReal(6);//To test set real value
	test5.setÝmag(8.456);//set imaginary value
	cout << test5.getReal() << " " << test5.getÝmag()<<endl;//To test return real and imaginary value

	test3.add(test4);//To test add member function
	test3.print();

	test3.subtract(test4);//To test subtract member function
	test3.print();

	test3.divide(test4);//To test divide member function
	test3.print();

	vector <Complex> vec;//vector that occured of complex numbers
	vec.push_back(test1);//Assigning complex numbers to the indexes of the vector
	vec.push_back(test2);
	vec.push_back(test3);
	vec.push_back(test4);
	vec.push_back(test5);
	
	vectorSort(vec);//Calling the function to sorting vector's real and imaginary values
	
	return 0;
}