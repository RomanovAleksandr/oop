#include "catch2/catch.hpp"
#include "Shapes/CLineSegment.h"

TEST_CASE("CLineSegment")
{
	CPoint start{ 2, 0 };
	CPoint end{ 2, 100 };
	CLineSegment line(start, end, 0);

	REQUIRE(line.GetStartPoint() == start);
	REQUIRE(line.GetEndPoint() == end);
	REQUIRE(line.GetArea() == 0);
	REQUIRE(line.GetOutlineColor() == 0);
	REQUIRE(line.GetPerimeter() == 100);

	std::string expectedString = "LineSegment (start: point (2.00, 0.00), end: point (2.00, 100.00),\n\tarea: 0.00, perimeter 100.00, outline color 000000)";
	REQUIRE(line.ToString() == expectedString);
}