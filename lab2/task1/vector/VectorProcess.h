#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

void ReadVector(std::istream& input, std::vector<double>& vector);
void MultiplyOnMinimal(std::vector<double>& vector);
void SortVector(std::vector<double>& vector);
void PrintVector(std::ostream& output, std::vector<double>& vector);