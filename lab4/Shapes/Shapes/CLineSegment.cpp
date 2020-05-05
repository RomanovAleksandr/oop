#include "CLineSegment.h"
#include <sstream>
#include <iomanip>

CLineSegment::CLineSegment(CPoint startPoint, CPoint endPoint, uint32_t outlineColor) :
	m_startPoint(startPoint), m_endPoint(endPoint), m_outlineColor(outlineColor)
{
}

double CLineSegment::GetArea() const
{
	return 0;
}

double CLineSegment::GetPerimeter() const
{
	return sqrt(pow(m_endPoint.x - m_startPoint.x, 2) + pow(m_endPoint.y - m_startPoint.y, 2));
}

std::string CLineSegment::ToString() const
{
	std::stringstream ss;
	ss << std::fixed;
	ss.precision(2);
	ss << "LineSegment ("
		<< "start: " << m_startPoint.ToString()
		<< ", end: " << m_endPoint.ToString()
		<< ",\n\tarea: " << GetArea()
		<< ", perimeter " << GetPerimeter()
		<< ", outline color " << std::setfill('0') << std::setw(6) << std::hex << m_outlineColor << ")";

	return ss.str();
}

uint32_t CLineSegment::GetOutlineColor() const
{
	return m_outlineColor;
}

CPoint CLineSegment::GetStartPoint() const
{
	return m_startPoint;
}

CPoint CLineSegment::GetEndPoint() const
{
	return m_endPoint;
}