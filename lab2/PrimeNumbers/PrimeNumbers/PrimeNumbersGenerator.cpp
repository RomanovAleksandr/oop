#include "PrimeNumbersGenerator.h"

using namespace std;

set<int> GeneratePrimeNumbersSet(const int upperBound)
{
	if (upperBound < 0)
	{
		return {};
	}

	set<int> primeNumbers;
	vector<bool> isPrime(upperBound + 1, true);

	set<int>::iterator p = primeNumbers.begin();

	for (int i = 2; i <= upperBound; i++)
	{
		if (isPrime[i] == false)
		{
			continue;
		}
		p = primeNumbers.insert(p, i);
		for (size_t j = 2; i * j <= upperBound; j++)
		{
			isPrime[i * j] = false;
		}
	}

	return primeNumbers;
}