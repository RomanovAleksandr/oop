#include "catch2/catch.hpp"
#include "Shapes/CRectangle.h"

TEST_CASE("CRectangle")
{
	CPoint leftToop{ 0, -10 };
	CPoint rightBottom{ 10, -20 };
	double width = 10;
	double height = 10;
	CRectangle rectangle(leftToop, width, height, 0, 0);

	REQUIRE(rectangle.GetArea() == 100);
	REQUIRE(rectangle.GetPerimeter() == 40);
	REQUIRE(rectangle.GetOutlineColor() == 0);
	REQUIRE(rectangle.GetFillColor() == 0);
	REQUIRE(rectangle.GetLeftTop() == leftToop);
	REQUIRE(rectangle.GetWidth() == width);
	REQUIRE(rectangle.GetHeight() == height);

	std::string expectedString = "Rectangle (left top: point (0.00, -10.00), width: 10.00, height: 10.00,\n\tarea: 100.00, perimeter: 40.00, outlineColor: 000000, fillColor: 0)";
	REQUIRE(rectangle.ToString() == expectedString);
}