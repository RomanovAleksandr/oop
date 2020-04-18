#include <iostream>
#include <set>
#include "PrimeNumbersGenerator.h"

using namespace std;

int main(int argc, char* argv[])
{
	set<int> primeNumbers = GeneratePrimeNumbersSet(23);
	if (primeNumbers.empty())
	{
		cout << "empty";
	}
	for (int prime : primeNumbers)
	{
		cout << prime << ' ';
	}
	cout << endl;
}