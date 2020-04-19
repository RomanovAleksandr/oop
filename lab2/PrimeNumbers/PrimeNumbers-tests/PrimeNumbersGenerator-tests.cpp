#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "PrimeNumbers/PrimeNumbers/PrimeNumbersGenerator.h"

using namespace std;

TEST_CASE("Generate prime numbers with upper bound 0")
{
	set<int> primeNumbers = GeneratePrimeNumbersSet(0);
	set<int> expectedSet = { };
	REQUIRE(primeNumbers == expectedSet);
}

TEST_CASE("Generate prime numbers with upper bound 23")
{
	set<int> primeNumbers = GeneratePrimeNumbersSet(23);
	set<int> expectedSet = { 2, 3, 5, 7, 11, 13, 17, 19, 23 };
	REQUIRE(primeNumbers == expectedSet);
}

TEST_CASE("Check count of prime numbers with upper bound 100000000")
{
	set<int> primeNumbers = GeneratePrimeNumbersSet(100000000);
	int expectedCount = 5761455;
	REQUIRE(expectedCount == primeNumbers.size());
}