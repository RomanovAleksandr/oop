#include "catch2/catch.hpp"
#include "Shapes/CTriangle.h"

TEST_CASE("CTriangle")
{
	CPoint v1{ 0, -10 };
	CPoint v2{ 0, 10 };
	CPoint v3{ 0, 0 };
	CTriangle triangle(v1, v2, v3, 0, 0);

	REQUIRE(triangle.GetArea() == 0);
	REQUIRE(triangle.GetPerimeter() == 40);
	REQUIRE(triangle.GetOutlineColor() == 0);
	REQUIRE(triangle.GetFillColor() == 0);
	REQUIRE(triangle.GetVertex1() == v1);
	REQUIRE(triangle.GetVertex2() == v2);
	REQUIRE(triangle.GetVertex3() == v3);

	std::string expectedString = "Triangle (vertices; point (0.00, -10.00) point (0.00, 10.00) point (0.00, 0.00),\n\tarea: 0.00, perimeter: 40.00, outlineColor: 000000, fillColor: 0)";
	REQUIRE(triangle.ToString() == expectedString);
}