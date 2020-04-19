#include "PrimeNumbersGenerator.h"

using namespace std;

set<int> GeneratePrimeNumbersSet(const int upperBound)
{
	if (upperBound < 0)
	{
		return {};
	}

	int isPrimeSize = upperBound + 1;
	set<int> primeNumbers;
	vector<bool> isPrime(isPrimeSize, true);

	for (int i = 2; i <= upperBound; i++)
	{
		if (isPrime[i] == false)
		{
			continue;
		}
		primeNumbers.insert(i);
		for (size_t j = 2; i * j <= upperBound; j++)
		{
			isPrime[i * j] = false;
		}
	}

	return primeNumbers;
}