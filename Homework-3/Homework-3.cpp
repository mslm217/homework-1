/* Müslüm Türk
Program that finds out how many different ways to cross the river 
according to the number of stones between 1 to 72. */
#include <iostream>
#include <vector>
#include <iomanip>
#include <chrono>
using namespace std;

//aþaðýdaki satýrlarý yoruma alarak kodunuzu farklý þekillerde test edebilirsiniz.
#define _TEST_ITERATIVE_
#define _TEST_RECURSIVE_

// Bu odevde global veya statik degisken tanimlanamaz!!!

/* Ozyinelemeli olarak zip zip kurbaganin kac farkli yoldan gittigini bulan fonksiyondur.
 * Bu fonksiyon icinde for ve while kullanamazsiniz ve en az bir kez recursiveFunction
 * fonksiyonu cagri yapilmalidir.
 */
long long recursiveFunction(int numberOfStones)
{
	if (numberOfStones == 1)
	{
		return 1;
	}
	else if (numberOfStones == 2)
	{
		return 2;
	}
	else if (numberOfStones == 3)
	{
		return 4;
	}
	
	
	return recursiveFunction(numberOfStones-1)+ recursiveFunction(numberOfStones - 2)+ recursiveFunction(numberOfStones - 3);
}

/* Yinelemeli olarak zip zip kurbaganin kac farkli yoldan gittigini bulan fonksiyondur.
 * Bu fonksiyon icinde for ve while dongusu kullanilmalidir.
 * Bu fonksiyon icinde baska bir fonksiyona (kendisi dahil) cagri yapilamaz.
 */
long long iterativeFunction(int numberOfStones)
{
	long long numberOfWays[72] = { 1,2,4 };

	if (numberOfStones == 1)
	{
		return numberOfWays[0];
	}		
	else if (numberOfStones == 2)
	{
		return numberOfWays[1];
	}
	else if (numberOfStones == 3)
	{
		return numberOfWays[2];
	}
	else
	{		
		for (int i = 3; i < numberOfStones; ++i)
		{ 
			numberOfWays[i] = numberOfWays[i-1] + numberOfWays[i-2] + numberOfWays[i-3];
		}
		return numberOfWays[numberOfStones-1];
	}
		
}



int main()
{
	const int MAX_NUMBER_OF_STONES{ 72 };
	cout << setfill(' ');

	cout.imbue(locale(""));

	for (auto i = 1; i <= MAX_NUMBER_OF_STONES; ++i)
	{

#ifdef _TEST_ITERATIVE_
		{
			long long tempResult = { 0 };

			auto start = std::chrono::steady_clock::now();
			tempResult = iterativeFunction(i);
			auto stop = std::chrono::steady_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();

			cout << "iterative" << setw(4) << i << " -> " << tempResult << " ( " << duration << "us )\n";
		}
#endif

#ifdef _TEST_RECURSIVE_
		{
			long long tempResult = { 0 };

			auto start = std::chrono::steady_clock::now();
			tempResult = recursiveFunction(i);
			auto stop = std::chrono::steady_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();

			cout << "recursive" << setw(4) << i << " -> " << tempResult << " ( " << duration << "us )\n\n";
		}
#endif

	}

	return 0;
}