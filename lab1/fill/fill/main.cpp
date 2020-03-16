#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <optional>
#include <stack>
#include <vector>

using namespace std;

struct Args
{
	string inputFileName;
	string outputFileName;
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
		cout << "Failed to open " << args->inputFileName << " for reading\n";
		return 1;
	}

	ofstream output(args->outputFileName);
	if (!input.is_open())
	{
		cout << "Failed to open " << args->outputFileName << " for writing\n";
		return 1;
	}

	Fill(input, output);

	if (input.bad())
	{
		cout << "Failed to read data from input file\n";
		return 1;
	}

	if (!output.flush())
	{
		cout << "Failed to write data to output file\n";
		return 1;
	}
}