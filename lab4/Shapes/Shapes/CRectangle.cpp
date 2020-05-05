#include "CRectangle.h"
#include <sstream>
#include <iomanip>

CRectangle::CRectangle(CPoint leftTop, double width, double height, uint32_t outlineColor, uint32_t fillColor) :
	m_leftTop(leftTop), m_width(width), m_height(height), m_outlineColor(outlineColor), m_fillColor(fillColor)
{
	m_rightBottom = { leftTop.x + width, leftTop.y - height };
}

double CRectangle::GetArea() const
{
	return m_width * m_height;
}

double CRectangle::GetPerimeter() const
{
	return m_width * 2 + m_height * 2;
}

std::string CRectangle::ToString() const
{
	std::stringstream ss;
	ss << std::fixed;
	ss.precision(2);
	ss << "Rectangle (left top: " << m_leftTop.ToString()
		<< ", width: " << m_width
		<< ", height: " << m_height
		<< ",\n\tarea: " << GetArea()
		<< ", perimeter: " << GetPerimeter()
		<< ", outlineColor: " << std::setfill('0') << std::setw(6) << std::hex << m_outlineColor
		<< ", fillColor: " << m_fillColor << ")";

	return ss.str();
}

uint32_t CRectangle::GetOutlineColor() const
{
	return m_outlineColor;
}

uint32_t CRectangle::GetFillColor() const
{
	return m_fillColor;
}

CPoint CRectangle::GetLeftTop() const
{
	return m_leftTop;
}

CPoint CRectangle::GetRightBottom() const
{
	return m_rightBottom;
}

double CRectangle::GetWidth() const
{
	return m_width;
}

double CRectangle::GetHeight() const
{
	return m_height;
}