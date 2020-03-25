// vector.tests.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <sstream>
#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "task1/vector/VectorProcess.h"

using namespace std;

TEST_CASE("Read array from empty input")
{

	istringstream input("");
	vector<double> array;
	vector<double> testArray;
	ReadVector(input, array);
	REQUIRE(array == testArray);
}

TEST_CASE("Read array from input")
{

	istringstream input("3.14 2 5 13.37");
	vector<double> array;
	vector<double> testArray{ 3.14, 2, 5, 13.37 };
	ReadVector(input, array);
	REQUIRE(array == testArray);
}

TEST_CASE("Read array from input with non double value")
{

	istringstream input("a");
	vector<double> array;
	vector<double> testArray;
	REQUIRE(array == testArray);
}

TEST_CASE("Multiplay on minimal")
{
	vector<double> array{ 3.14, 2 };
	vector<double> testArray{ 6.28, 4 };
	MultiplyOnMinimal(array);
	REQUIRE(array == testArray);

	array = { 3.14, -4 };
	testArray = { -12.56, 16 };
	MultiplyOnMinimal(array);
	REQUIRE(array == testArray);

	array = { 3.14, 0 };
	testArray = { 0, 0 };
	MultiplyOnMinimal(array);
	REQUIRE(array == testArray);
}

TEST_CASE("Sort vector")
{
	vector<double> array{ 3.14, 2, 0 };
	vector<double> testArray{ 0, 2, 3.14 };
	SortVector(array);
	REQUIRE(array == testArray);
}

TEST_CASE("Print vector")
{
	ostringstream output;
	vector<double> array{ 3.14, 2, 0 };
	PrintVector(output, array);
	REQUIRE(output.str() == "3.14 2 0 ");
}