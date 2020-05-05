#include "CCircle.h"
#include <sstream>
#include <iomanip>

CCircle::CCircle(CPoint center, double radius, uint32_t outlineColor, uint32_t fillColor) :
	m_center(center), m_radius(radius), m_outlineColor(outlineColor), m_fillColor(fillColor)
{
}

double CCircle::GetArea() const
{
	return 3.14 * pow(m_radius, 2);
}

double CCircle::GetPerimeter() const
{
	return 2 * 3.14 * m_radius;
}

std::string CCircle::ToString() const
{
	std::stringstream ss;
	ss << std::fixed;
	ss.precision(2);
	ss << "Circle (center: " << m_center.ToString()
		<< ", radius: " << m_radius
		<< ",\n\tarea: " << GetArea()
		<< ", perimeter: " << GetPerimeter()
		<< ", outlineColor: " << std::setfill('0') << std::setw(6) << std::hex << m_outlineColor
		<< ", fillColor: " << m_fillColor << ")";

	return ss.str();
}

uint32_t CCircle::GetOutlineColor() const
{
	return m_outlineColor;
}

uint32_t CCircle::GetFillColor() const
{
	return m_fillColor;
}

CPoint CCircle::GetCenter() const
{
	return m_center;
}

double CCircle::GetRadius() const
{
	return m_radius;
}