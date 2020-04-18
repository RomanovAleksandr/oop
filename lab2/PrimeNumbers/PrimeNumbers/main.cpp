#include <iostream>
#include <set>
#include <optional>
#include <string>
#include "PrimeNumbersGenerator.h"

using namespace std;

optional<int> parseArgs(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: PrimeNumbers.exe <upper bound>\n";
		return std::nullopt;
	}

	string upperBoundStr = argv[1];
	size_t badPos = 0;
	int upperBound = stoi(upperBoundStr, &badPos, 10);
	if (badPos == upperBoundStr.length())
	{
		return upperBound;
	}

	return nullopt;
}

int main(int argc, char* argv[])
{
	auto upperBound = parseArgs(argc, argv);
	if (!upperBound)
	{
		return 1;
	}

	if (upperBound.value() < 0)
	{
		cout << "upper bound must be positive" << endl;
		return 1;
	}

	set<int> primeNumbers = GeneratePrimeNumbersSet(upperBound.value());


	for (int prime : primeNumbers)
	{
		cout << prime << ' ';
	}
	cout << endl;
}