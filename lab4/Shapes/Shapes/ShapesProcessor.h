#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "IShape.h"
#include "CPoint.h"
#include "CLineSegment.h"
#include "CTriangle.h"
#include "CCircle.h"

class ShapesProcessor
{
public:
	void ReadShapes(std::istream& input);
	std::shared_ptr<IShape> FindLargestAreaShape() const;
	std::shared_ptr<IShape> FindSmallestPerimeterShape() const;
	const std::vector<std::shared_ptr<IShape>>& GetShapes() const;

private:
	std::vector<std::shared_ptr<IShape>> m_shapes;
	std::shared_ptr<IShape> ReadLineSegment(std::istream& parameters) const;
	std::shared_ptr<IShape> ReadTriangle(std::istream& parameters) const;
	std::shared_ptr<IShape> ReadRectangle(std::istream& parameters) const;
	std::shared_ptr<IShape> ReadCircle(std::istream& parameters) const;
};