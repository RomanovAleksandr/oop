#include "catch2/catch.hpp"
#include "Shapes/CPoint.h"

TEST_CASE("CPoint")
{
	CPoint p1{ 2, 2.5 };
	REQUIRE(p1.x == 2);
	REQUIRE(p1.x == 2);
	REQUIRE(p1 == p1);

	std::string expectedString = "point (2.00, 2.50)";
	REQUIRE(p1.ToString() == expectedString);
}