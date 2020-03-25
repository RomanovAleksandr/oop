// vector.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "VectorProcess.h"
#include <iostream>

using namespace std;

int main()
{
	vector<double> array;
	ReadVector(cin, array);
	MultiplyOnMinimal(array);
	SortVector(array);
	PrintVector(cout, array);
}
