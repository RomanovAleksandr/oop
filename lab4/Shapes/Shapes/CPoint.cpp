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

bool CPoint::operator==(const CPoint& p) const
{
	return this->x == p.x && this->y == p.y;
}