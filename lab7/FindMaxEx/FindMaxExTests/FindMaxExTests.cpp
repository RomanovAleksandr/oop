#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "FindMaxEx/FindMaxEx.h"

TEST_CASE("Find max int")
{
	std::vector<int> intVector = { 1, 2, 3, 1, 5 };
	int maxValue;
	CHECK(FindMax(intVector, maxValue, std::less<int>()));
	CHECK(maxValue == 5);
}

TEST_CASE("Empty vector")
{
	std::vector<double> doubleVector = {};
	double maxValue;
	CHECK_FALSE(FindMax(doubleVector, maxValue, std::less<double>()));
}