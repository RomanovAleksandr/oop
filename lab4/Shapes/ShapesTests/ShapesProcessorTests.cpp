#include "catch2/catch.hpp"
#include "Shapes/ShapesProcessor.h"
#include "Shapes/CCircle.h"
#include "Shapes/CRectangle.h"
#include "Shapes/CTriangle.h"
#include "Shapes/CLineSegment.h"
#include "Shapes/CPoint.h"

using namespace std;

TEST_CASE("Read line segment")
{
	ShapesProcessor processor;
	istringstream input("lineSegment 2 0 2 100 ff0000");
	processor.ReadShapes(input);
	string expectedString = "LineSegment (start: point (2.00, 0.00), end: point (2.00, 100.00),\n\tarea: 0.00, perimeter 100.00, outline color ff0000)";
	REQUIRE(processor.GetShapeByIndex(0)->ToString() == expectedString);
}

TEST_CASE("Read triangle")
{
	ShapesProcessor processor;
	istringstream input("triangle 0 -10 0 10 0 0 ff00ff ff002");
	processor.ReadShapes(input);
	string expectedString = "Triangle (vertices; point (0.00, -10.00) point (0.00, 10.00) point (0.00, 0.00),\n\tarea: 0.00, perimeter: 40.00, outlineColor: ff00ff, fillColor: ff002)";
	REQUIRE(processor.GetShapeByIndex(0)->ToString() == expectedString);
}

TEST_CASE("Read rectangle")
{
	ShapesProcessor processor;
	istringstream input("rectangle 0 -10 10 10 0 0");
	processor.ReadShapes(input);
	string expectedString = "Rectangle (left top: point (0.00, -10.00), width: 10.00, height: 10.00,\n\tarea: 100.00, perimeter: 40.00, outlineColor: 000000, fillColor: 0)";
	REQUIRE(processor.GetShapeByIndex(0)->ToString() == expectedString);
}

TEST_CASE("Read circle")
{
	ShapesProcessor processor;
	istringstream input("circle 0 0 10 ff00ff ffffff");
	processor.ReadShapes(input);
	string expectedString = "Circle (center: point (0.00, 0.00), radius: 10.00,\n\tarea: 314.00, perimeter: 62.80, outlineColor: ff00ff, fillColor: ffffff)";
	REQUIRE(processor.GetShapeByIndex(0)->ToString() == expectedString);
}