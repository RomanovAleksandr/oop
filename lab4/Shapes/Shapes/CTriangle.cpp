#include "CTriangle.h"
#include <sstream>
#include <iomanip>

CTriangle::CTriangle(CPoint vertex1, CPoint vertex2, CPoint vertex3, uint32_t outlineColor, uint32_t fillColor) :
	m_vertex1(vertex1), m_vertex2(vertex2), m_vertex3(vertex3), m_outlineColor(outlineColor), m_fillColor(fillColor)
{
}

double CTriangle::GetArea() const
{
	return abs(((m_vertex1.x - m_vertex3.x) * (m_vertex2.y - m_vertex3.y))
		- ((m_vertex2.x - m_vertex3.x) * (m_vertex1.y - m_vertex3.y))) / 2;
}

double CTriangle::GetPerimeter() const
{
	double l12 = sqrt(pow(m_vertex1.x - m_vertex2.x, 2) + pow(m_vertex1.y - m_vertex2.y, 2));
	double l23 = sqrt(pow(m_vertex2.x - m_vertex3.x, 2) + pow(m_vertex2.y - m_vertex3.y, 2));
	double l31 = sqrt(pow(m_vertex3.x - m_vertex1.x, 2) + pow(m_vertex3.y - m_vertex1.y, 2));
	return l12 + l23 + l31;
}

std::string CTriangle::ToString() const
{
	std::stringstream ss;
	ss << std::fixed;
	ss.precision(2);
	ss << "Triangle (vertices; " << m_vertex1.ToString()
		<< ' ' << m_vertex2.ToString()
		<< ' ' << m_vertex3.ToString()
		<< ",\n\tarea: " << GetArea()
		<< ", perimeter: " << GetPerimeter()
		<< ", outlineColor: " << std::setfill('0') << std::setw(6) << std::hex << m_outlineColor
		<< ", fillColor: " << m_fillColor << ")";

	return ss.str();
}

uint32_t CTriangle::GetOutlineColor() const
{
	return m_outlineColor;
}

uint32_t CTriangle::GetFillColor() const
{
	return m_fillColor;
}

CPoint CTriangle::GetVertex1() const
{
	return m_vertex1;
}

CPoint CTriangle::GetVertex2() const
{
	return m_vertex2;
}

CPoint CTriangle::GetVertex3() const
{
	return m_vertex3;
}