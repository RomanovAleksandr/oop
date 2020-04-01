#include "VectorProcess.h"

void ReadVector(std::istream& input, std::vector<double>& vector)
{
	double value;
	while (input >> value)
	{
		vector.push_back(value);
	}
}

void MultiplyOnMinimal(std::vector<double>& vector)
{
	double min = *std::min_element(vector.begin(), vector.end());
	for (double& element : vector)
	{
		element *= min;
	}
}

void SortVector(std::vector<double>& vector)
{
	std::sort(vector.begin(), vector.end());
}

void PrintVector(std::ostream& output, const std::vector<double>& vector)
{
	for (const double& element : vector)
	{
		output << element << ' ';
	}
}