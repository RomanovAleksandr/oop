#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <optional>
#include <stack>
#include <vector>

using namespace std;

typedef vector<vector<char>> Canvas;

const int CANVASSIZE = 100;

struct Args
{
	string inputFileName;
	string outputFileName;
};

struct Point
{
	size_t row;
	size_t column;
};

std::optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: fill.exe <input file> <output file>\n";
		return std::nullopt;
	}
	Args args;
	args.inputFileName = argv[1];
	args.outputFileName = argv[2];
	return args;
}

bool ReadCanvas(const string& inputFileName, Canvas &canvas)
{
	ifstream input(inputFileName);
	if (!input.is_open())
	{
		cout << "Failed to open " << inputFileName << " for reading\n";
		return false;
	}
		
	for (int i = 0; i < CANVASSIZE; i++)
	{
		string line;
		if (getline(input, line))
		{
			vector<char> lineVect;
			canvas.push_back(lineVect);
			stringstream sstring;
			sstring << line;
			for (size_t j = 0; j < line.length(); j++)
			{
				sstring << noskipws;
				canvas[i].push_back(sstring.get());
			}
		}
		else
		{
			break;
		}
	}

	if (input.bad())
	{
		cout << "Failed to read data from input file\n";
		return false;
	}

	return true;
}

void ResizeCanvas(Canvas& canvas)
{
	for (size_t i = canvas.size(); i < CANVASSIZE; i++)
	{
		vector<char> lineVect;
		canvas.push_back(lineVect);
	}
	for (size_t i = 0; i < canvas.size(); i++)
	{
		for (size_t j = canvas[i].size(); j < CANVASSIZE; j++)
		{
			canvas[i].push_back(' ');
		}
	}
}

void Paint(Canvas& canvas, size_t row, size_t column)
{
	stack<Point> stack;
	stack.push(Point{ row, column });
	while (!stack.empty())
	{
		Point point = stack.top();
		stack.pop();
		if ((point.row >= 0 && point.row < CANVASSIZE) && (point.column >= 0 && point.column < CANVASSIZE))
		{
			if (point.row >= canvas.size() || point.column >= canvas[point.row].size())
			{
				ResizeCanvas(canvas);
			}
			if (canvas[point.row][point.column] == ' ' || canvas[point.row][point.column] == 'O')
			{
				stack.push(Point{ point.row + 1, point.column });
				stack.push(Point{ point.row - 1, point.column });
				stack.push(Point{ point.row, point.column + 1 });
				stack.push(Point{ point.row, point.column - 1 });
				if (canvas[point.row][point.column] == ' ')
				{
					canvas[point.row][point.column] = '.';
				}
			}
		}
	}
}

void Fill(Canvas& canvas)
{
	for (size_t i = 0; i < canvas.size(); i++)
	{
		for (size_t j = 0; j < canvas[i].size(); j++)
		{
			if (canvas[i][j] == 'O')
			{
				Paint(canvas, i, j);
			}
		}
	}
}

bool OutCanvasInFile(const string& outputFileName, Canvas &canvas)
{
	ofstream output(outputFileName);
	if (!output.is_open())
	{
		cout << "Failed to open " << outputFileName << " for writing\n";
		return false;
	}

	for (size_t i = 0; i < canvas.size(); i++)
	{
		for (size_t j = 0; j < canvas[i].size(); j++)
		{
			output << canvas[i][j];
		}
		output << "\n";
	}

	if (!output.flush())
	{
		cout << "Failed to write data to output file\n";
		return false;
	}

	return true;
}

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);
	if (!args)
	{
		return 1;
	}

	Canvas canvas;
	if (!ReadCanvas(args->inputFileName, canvas))
	{
		return 1;
	}

	Fill(canvas);

	if (!OutCanvasInFile(args->outputFileName, canvas))
	{
		return 1;
	}
}