#include "PrimeNumbersGenerator.h"

using namespace std;

set<int> GeneratePrimeNumbersSet(const int upperBound)
{
	int isPrimeSize = upperBound + 1;
	vector<bool> isPrime(isPrimeSize, true);

	for (size_t i = 2; i <= upperBound; i++)
	{
		if (isPrime[i] == false)
		{
			continue;
		}
		for (size_t j = 2; i * j <= upperBound; j++)
		{
			isPrime[i * j] = false;
		}
	}

	set<int> primeNumbers;
	for (int i = 2; i <= upperBound; i++)
	{
		if (isPrime[i] == true)
		{
			primeNumbers.insert(i);
		}
	}

	return primeNumbers;
}