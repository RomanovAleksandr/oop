#include "ShapesProcessor.h"

using namespace std;

int main(int argc, char* argv[])
{
	ShapesProcessor processor;
	cout << "Use comands to enter shapes:\n\n"
		<< "lineSegment <start point> <end point> <outline color>\n"
		<< "triangle <vertex1> <vertex2> <vertex3> <outline color> <fill color>\n"
		<< "rectangle <left top vertex> <width> <height> <outline color> <fill color>\n"
		<< "circle <center> <radius> <outline color> <fill color>\n"
		<< "Example: circle 0 3.1 5.1 ff0000 00ff00\n\n";

	try
	{
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