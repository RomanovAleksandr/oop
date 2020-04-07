#include <fstream>
#include <iostream>
#include <string>
#include <optional>
#include <sstream>
#include <array>

using namespace std;

const int SIZE = 3;
typedef std::array<std::array<double, 3>, 3> Matrix3x3;

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

double CalcDeterm(const Matrix3x3& matrix)
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

std::optional<Matrix3x3> CalcInvertMatrix(const Matrix3x3& matrix)
{
	double determinant = CalcDeterm(matrix);
	if (determinant == 0)
	{
		return std::nullopt;
	}

	Matrix3x3 invertMatrix;
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

	return invertMatrix;
}

void PrintMatrix(const Matrix3x3& matrix)
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

std::optional<Matrix3x3> ReadMatrixFromFile(const string& inputFileName)
{
	ifstream input(inputFileName);
	if (!input.is_open())
	{
		cout << "Failed to open '" << inputFileName << "' for reading\n";
		return std::nullopt;
	}

	Matrix3x3 matrix;
	for (int i = 0; i < SIZE; i++)
	{
		string line;
		if (getline(input, line))
		{
			stringstream sstring;
			sstring << line;
			for (int j = 0; j < SIZE; j++)
			{
				double temp;
				if (sstring >> temp)
				{
					matrix[i][j] = temp;
				}
				else
				{
					cout << "Failed to read matrix" << "\n";
					return std::nullopt;
				}
			}
			sstring.clear();
		}
		else
		{
			cout << "Failed to read matrix" << "\n";
			return std::nullopt;
		}
	}

	return matrix;
}

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);
	if (!args)
	{
		return 1;
	}

	auto matrix = ReadMatrixFromFile(args->inputFileName);
	if (!matrix)
	{
		return 1;
	}

	auto invertMatrix = CalcInvertMatrix(matrix.value());
	if (!invertMatrix)
	{
		cout << "Nul determ matrix\n";
		return 1;
	}

	PrintMatrix(invertMatrix.value());
	return 0;
}