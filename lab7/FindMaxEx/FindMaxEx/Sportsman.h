#pragma once
#include <string>

class Sportsman
{
public:
	std::string name;
	double height = 0;
	double weight = 0;
};

bool FindMaxHeight(const Sportsman& s1, const Sportsman& s2)
{
	return s1.height < s2.height;
}

bool FindMaxWeight(const Sportsman& s1, const Sportsman& s2)
{
	return s1.weight < s2.weight;
}