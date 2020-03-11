#include <fstream>
#include <iostream>
#include <string>
#include <optional>
#include <sstream>

using namespace std;

struct Args
{
	string inputFileName;
};

std::optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: invert.exe <matrix file1>\n";
		return std::nullopt;
	}
	Args args;
	args.inputFileName = argv[1];
	return args;
}

int ReadMatrix(ifstream &input, int(&matrix)[3][3])
{
	double temp;
	int count = 0;
	stringstream sstring;
	string line;
	for (int i = 0; i < 3; i++)
	{
		if (getline(input, line))
		{
			sstring << line;
			for (int j = 0; j < 3; j++)
			{
				if (sstring >> temp)
				{
					matrix[i][j] = temp;
				}
				else
				{
					return 0;
				}
			}
			sstring.clear();
		}
		else
		{
			return 0;
		}
		
	}
	return 1;
}

int CalcDeterm(int(&matrix)[3][3])
{

}

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);
	if (!args)
	{
		return 1;
	}

	ifstream input(args->inputFileName);
	if (!input.is_open())
	{
		cout << "Failed to open '" << args->inputFileName << "' for reading\n";
		return 1;
	}

	int matrix[3][3];
	if (ReadMatrix(input, matrix))
	{
		cout << "success";
	}
}