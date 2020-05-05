#include "catch2/catch.hpp"
#include "Shapes/CCircle.h"

TEST_CASE("CCircle")
{
	CPoint center{ 0, 0 };
	double radius = 10;
	CCircle circle(center, radius, 0, 0);

	REQUIRE(circle.GetArea() == 314);
	REQUIRE(circle.GetPerimeter() == 3.14 * 10 * 2);
	REQUIRE(circle.GetOutlineColor() == 0);
	REQUIRE(circle.GetFillColor() == 0);
	REQUIRE(circle.GetCenter() == center);
	REQUIRE(circle.GetRadius() == radius);

	std::string expectedString = "Circle (center: point (0.00, 0.00), radius: 10.00,\n\tarea: 314.00, perimeter: 62.80, outlineColor: 000000, fillColor: 0)";
	REQUIRE(circle.ToString() == expectedString);
}