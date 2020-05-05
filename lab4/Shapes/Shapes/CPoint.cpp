#include "CPoint.h"
#include <sstream>

std::string CPoint::ToString() const
{
	std::stringstream ss;
	ss << std::fixed;
	ss.precision(2);
	ss << "point (" << x << ", " << y << ")";
	return ss.str();
}

bool operator==(const CPoint& a, const CPoint& b)
{
	return a.x == b.x && a.y == b.y;
}