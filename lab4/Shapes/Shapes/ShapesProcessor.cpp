#include "ShapesProcessor.h"
#include <algorithm>
#include <sstream>
#include "CLineSegment.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "CCircle.h"

using namespace std;

vector<string> ParsParams(istream& parameters)
{
	vector<string> params;
	string parameter;
	while (parameters >> parameter)
	{
		params.push_back(parameter);
	}
	return params;
}

shared_ptr<IShape> ShapesProcessor::ReadLineSegment(istream& parameters) const
{
	vector<string> parsedParams = ParsParams(parameters);
	if (parsedParams.size() != 5)
	{
		throw exception("Invalid line segment params count");
	}

	CPoint startPoint{ stod(parsedParams[0]), stod(parsedParams[1]) };
	CPoint endPoint{ stod(parsedParams[2]), stod(parsedParams[3]) };
	uint32_t outlineColor = stoul(parsedParams[4], nullptr, 16);

	return make_shared<CLineSegment>(startPoint, endPoint, outlineColor);
}

shared_ptr<IShape> ShapesProcessor::ReadTriangle(istream& parameters) const
{
	vector<string> parsedParams = ParsParams(parameters);
	if (parsedParams.size() != 8)
	{
		throw exception("Invalid triangle params count");
	}

	CPoint vertex1{ stod(parsedParams[0]), stod(parsedParams[1]) };
	CPoint vertex2{ stod(parsedParams[2]), stod(parsedParams[3]) };
	CPoint vertex3{ stod(parsedParams[4]), stod(parsedParams[5]) };
	uint32_t outlineColor = stoul(parsedParams[6], nullptr, 16);
	uint32_t fillColor = stoul(parsedParams[7], nullptr, 16);

	return make_shared<CTriangle>(vertex1, vertex2, vertex3, outlineColor, fillColor);
}

shared_ptr<IShape> ShapesProcessor::ReadRectangle(istream& parameters) const
{
	vector<string> parsedParams = ParsParams(parameters);
	if (parsedParams.size() != 6)
	{
		throw exception("Invalid rectangle params count");
	}

	CPoint leftTop{ stod(parsedParams[0]), stod(parsedParams[1]) };
	double width = stod(parsedParams[2]);
	double height = stod(parsedParams[3]);
	uint32_t outlineColor = stoul(parsedParams[4], nullptr, 16);
	uint32_t fillColor = stoul(parsedParams[5], nullptr, 16);

	return make_shared<CRectangle>(leftTop, width, height, outlineColor, fillColor);
}

shared_ptr<IShape> ShapesProcessor::ReadCircle(istream& parameters) const
{
	vector<string> parsedParams = ParsParams(parameters);
	if (parsedParams.size() != 5)
	{
		throw exception("Invalid circle params count");
	}

	CPoint center{ stod(parsedParams[0]), stod(parsedParams[1]) };
	double radius = stod(parsedParams[2]);
	uint32_t outlineColor = stoul(parsedParams[3], nullptr, 16);
	uint32_t fillColor = stoul(parsedParams[4], nullptr, 16);

	return make_shared<CCircle>(center, radius, outlineColor, fillColor);
}

void ShapesProcessor::ReadShapes(istream& input)
{
	string shapeCommand;
	while (getline(input, shapeCommand))
	{

		stringstream ss(shapeCommand);

		string shape;
		ss >> shape;
		if (shape == "lineSegment")
		{
			m_shapes.push_back(ReadLineSegment(ss));
		}
		else if (shape == "triangle")
		{
			m_shapes.push_back(ReadTriangle(ss));
		}
		else if (shape == "rectangle")
		{
			m_shapes.push_back(ReadRectangle(ss));
		}
		else if (shape == "circle")
		{
			m_shapes.push_back(ReadCircle(ss));
		}
	}
}

shared_ptr<IShape> ShapesProcessor::FindLargestAreaShape() const
{
	if (!m_shapes.empty())
	{
		auto element = max_element(m_shapes.begin(), m_shapes.end(), [](shared_ptr<IShape> a, shared_ptr<IShape> b) {
			return a->GetPerimeter() < b->GetPerimeter();
			});
		return *element;
	}
	return nullptr;
}

shared_ptr<IShape> ShapesProcessor::FindSmallestPerimeterShape() const
{
	if (!m_shapes.empty())
	{
		auto element = min_element(m_shapes.begin(), m_shapes.end(), [](shared_ptr<IShape> a, shared_ptr<IShape> b) {
			return a->GetPerimeter() < b->GetPerimeter();
			});
		return *element;
	}
	return nullptr;
}

const std::vector<std::shared_ptr<IShape>>& ShapesProcessor::GetShapes() const
{
	return m_shapes;
}