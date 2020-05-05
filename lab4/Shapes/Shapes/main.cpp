#include "ShapesProcessor.h"
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
	ShapesProcessor processor;

	try
	{
		ifstream input("shapes.txt");
		processor.ReadShapes(cin);
		shared_ptr<IShape> largestAreaShape = processor.FindLargestAreaShape();
		if (largestAreaShape != nullptr)
		{
			cout << "max area shape: " << largestAreaShape->ToString() << endl;
		}
		shared_ptr<IShape> smallestPerimeterShape = processor.FindSmallestPerimeterShape();
		if (largestAreaShape != nullptr)
		{
			cout << "min perimetr shape: " << smallestPerimeterShape->ToString() << endl;
		}
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
}