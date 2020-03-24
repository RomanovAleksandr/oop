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
	int row;
	int column;
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

bool Paint(vector<vector<char>>& vect, stack<pair<int, int>>& st)
{
	pair<int, int> pair = st.top();
	st.pop();
	if ((pair.first >= 0 && pair.first < 100) && (pair.second >= 0 && pair.second < 100))
	{
		if (pair.first >= vect.size())
		{
			vector<char> lineVect;
			vect.push_back(lineVect);
		}
		if (pair.second >= vect[pair.first].size())
		{
			for (size_t i = vect[pair.first].size(); i <= pair.second; i++)
			{
				vect[pair.first].push_back(' ');
			}
		}
		if (vect[pair.first][pair.second] != '#' && vect[pair.first][pair.second] != '.')
		{
			if (vect[pair.first][pair.second] != 'O')
			{
				vect[pair.first][pair.second] = '.';
			}
			st.push(make_pair(pair.first, pair.second + 1));
			st.push(make_pair(pair.first, pair.second - 1));
			st.push(make_pair(pair.first + 1, pair.second));
			st.push(make_pair(pair.first - 1, pair.second));
			return 1;
		}
	}
	return 0;
}

void FillHolstVect(ifstream& input, vector<vector<char>> &vect)
{
	string line;
	char ch;
	stringstream sstring;
	for (int i = 0; i < 100; i++)
	{
		if (getline(input, line))
		{
			vector<char> lineVect;
			vect.push_back(lineVect);
			sstring << line;
			for (int j = 0; j < line.length(); j++)
			{
				sstring << noskipws;
				sstring >> ch;
				vect[i].push_back(ch);
			}
		}
		else
		{
			break;
		}
	}
}

void OutInFile(ofstream& output, vector<vector<char>>& vect)
{
	for (int i = 0; i < vect.size(); i++)
	{
		for (int j = 0; j < vect[i].size(); j++)
		{
			output << vect[i][j];
		}
		output << "\n";
	}
}

void Fill(ifstream& input, ofstream& output)
{
	vector<vector<char>> vect;
	FillHolstVect(input, vect);
	

	for (int i = 0; i < vect.size(); i++)
	{
		for (int j = 0; j < vect[i].size(); j++)
		{
			if (vect[i][j] == 'O')
			{
				stack<pair<int, int>> stack;
				stack.push(make_pair(i, j));
				while (!stack.empty())
				{
					Paint(vect, stack);
				}
			}
		}
	}

	OutInFile(output, vect);
}

bool OpenFiles(ifstream& input, ofstream& output, string& inputFileName, string& outputFileName)
{
	input.open(inputFileName);
	if (!input.is_open())
	{
		cout << "Failed to open " << inputFileName << " for reading\n";
		return 0;
	}

	output.open(outputFileName);
	if (!input.is_open())
	{
		cout << "Failed to open " << outputFileName << " for writing\n";
		return 0;
	}

	return 1;
}

bool ReadCanvas(ifstream &input, Canvas &canvas)
{
	string line;
	char ch;
	stringstream sstring;
	for (int i = 0; i < 100; i++)
	{
		if (getline(input, line))
		{
			vector<char> lineVect;
			canvas.push_back(lineVect);
			sstring << line;
			for (int j = 0; j < line.length(); j++)
			{
				sstring << noskipws;
				sstring >> ch;
				canvas[i].push_back(ch);
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
		return 0;
	}

	return 1;
}

void Paint(Canvas &canvas, stack<Point> stack)
{
	Point point = stack.top();
	stack.pop();

	if ((point.row >= 0 && point.row < 100) && (point.column >= 0 && point.column < 100))
	{

	}
}

bool Fill(Canvas& canvas)
{
	for (int i = 0; i < canvas.size(); i++)
	{
		for (int j = 0; j < canvas[i].size(); j++)
		{
			if (canvas[i][j] == 'O')
			{
				stack<Point> stack;
				stack.push(Point{ i, j });
				while (!stack.empty())
				{
					Paint(canvas, stack);
				}
			}
		}
	}

	return 1;
}

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);
	if (!args)
	{
		return 1;
	}

	ifstream input;
	ofstream output;
	if (!OpenFiles(input, output, args->inputFileName, args->outputFileName))
	{
		return 1;
	}

	Canvas canvas;
	if (!ReadCanvas(input, canvas))
	{
		return 1;
	}

	if (!Fill(canvas))
	{
		return 1;
	}

	Fill(input, output);

	

	if (!output.flush())
	{
		cout << "Failed to write data to output file\n";
		return 1;
	}
}