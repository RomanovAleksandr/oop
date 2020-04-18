#include <iostream>
#include <set>
#include <optional>
#include <string>
#include "PrimeNumbersGenerator.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: PrimeNumbers.exe <upper bound>\n";
		return 1;
	}

	int upperBound = atoi(argv[1]);
	
	if (upperBound < 0)
	{
		cout << "upper bound must be positive" << endl;
		return 1;
	}

	set<int> primeNumbers = GeneratePrimeNumbersSet(upperBound);


	for (int prime : primeNumbers)
	{
		cout << prime << ' ';
	}
	cout << endl;
}