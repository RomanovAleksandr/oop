#pragma once
#include <string>

class CPoint
{
public:
	double x = 0;
	double y = 0;
	std::string ToString() const;
	friend bool operator==(const CPoint& a, const CPoint& b);

private:
	
};