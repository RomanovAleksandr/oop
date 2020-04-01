#include <fstream>
#include <iostream>
#include <string>
#include <optional>
#include <sstream>

using namespace std;

const int SIZE = 3;

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

double CalcDeterm(const double(&matrix)[SIZE][SIZE])
{
	double determinant = 0;
	for (int i = 0; i < SIZE; i++)
	{
		int top = 1;
		int bottom = 2;
		int right = (i + 1) % SIZE;
		int left = (i + 2) % SIZE;
		determinant += matrix[0][i] * (matrix[top][right] * matrix[bottom][left] - matrix[top][left] * matrix[bottom][right]);
	}
	return determinant;
}

bool CalcInvertMatrix(const double(&matrix)[SIZE][SIZE], double(&invertMatrix)[SIZE][SIZE])
{
	double determinant = CalcDeterm(matrix);
	if (determinant == 0)
	{
		cout << "Determinant is zero\n";
		return 0;
	}

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			int top = (j + 1) % SIZE;
			int bottom = (j + 2) % SIZE;
			int right = (i + 1) % SIZE;
			int left = (i + 2) % SIZE;
			invertMatrix[i][j] = (matrix[top][right] * matrix[bottom][left] - matrix[top][left] * matrix[bottom][right]) / determinant;
		}
	}

	return 1;
}

void PrintMatrix(const double(&matrix)[SIZE][SIZE])
{
	cout.precision(3);
	cout.setf(ios::fixed);
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << "\n";
	}
}

bool ReadMatrixFromFile(const string &inputFileName, double(&matrix)[SIZE][SIZE])
{
	ifstream input(inputFileName);
	if (!input.is_open())
	{
		cout << "Failed to open '" << inputFileName << "' for reading\n";
		return 0;
	}

	double temp;
	int count = 0;
	stringstream sstring;
	string line;
	for (int i = 0; i < SIZE; i++)
	{
		if (getline(input, line))
		{
			sstring << line;
			for (int j = 0; j < SIZE; j++)
			{
				if (sstring >> temp)
				{
					matrix[i][j] = temp;
				}
				else
				{
					cout << "Failed to read matrix" << "\n";
					return 0;
				}
			}
			sstring.clear();
		}
		else
		{
			cout << "Failed to read matrix" << "\n";
			return 0;
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

	double matrix[SIZE][SIZE];
	if (!ReadMatrixFromFile(args->inputFileName, matrix))
	{
		return 1;
	}

	double invertMatrix[SIZE][SIZE];
	if (!CalcInvertMatrix(matrix, invertMatrix))
	{
		return 1;
	}

	PrintMatrix(invertMatrix);
	return 0;
}