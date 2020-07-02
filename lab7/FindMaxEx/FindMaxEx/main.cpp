#include <iostream>
#include "FindMaxEx.h"
#include "Sportsman.h"
#include <vector>

using namespace std;

int main()
{
	vector<Sportsman> sportsmen = { {"Dima", 1.83, 80}, {"Anton", 2, 200}, {"VI KA", 1.7, 50}, {"Svetlana", 1.8, 50} };
	Sportsman maxHeight;
	FindMax(sportsmen, maxHeight, FindMaxHeight);
	Sportsman maxWeight;
	FindMax(sportsmen, maxWeight, FindMaxWeight);

	cout << "Max height: " << maxHeight.name << ' ' << maxHeight.height << endl;
	cout << "Max weight: " << maxWeight.name << ' ' << maxWeight.weight << endl;
}